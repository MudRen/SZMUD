//fix by cheap
//10-30-01
inherit NPC;
inherit F_MASTER;

string ask_me();

int auto_perform();

void create()
{
        set_name("̷����", ({ "tan chuduan", "tan" }));
        set("nickname", "������");
        set("long",
                "������ȫ�������е�̷���ˣ����ų����ӣ����������ĵ��������еڶ���\n"
                "����һ�������ʿ����ɫ����\n"
      );
        set("gender", "����");
        set("age", 70);
        set("attitude", "heroic");
        set("shen_type", 1);
        set("str", 28);
        set("int", 28);
        set("con", 28);
        set("con", 28);
        set("dex", 28);

        set("max_qi", 2500);
        set("max_jing", 2000);
        set("max_jingli", 2000);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 50);
        set("combat_exp", 750000);
        set("score", 60000);

        set_skill("beidou-zhenfa", 150);
        set_skill("force", 150);
        set_skill("xiantian-gong", 150);
        set_skill("dodge", 150);
        set_skill("jinyangong", 150);
        set_skill("cuff", 150);
        set_skill("chunyang-quan", 150);
        set_skill("strike", 150);
        set_skill("sanhua-juding", 150);
        set_skill("parry", 150);
        set_skill("parry", 150);
        set_skill("sword", 150);
        set_skill("quanzhen-jian", 150);
        set_skill("literate", 120);
        set_skill("taoism", 150);

        map_skill("force", "xiantian-gong");
        map_skill("dodge", "jinyangong");
        map_skill("cuff", "chunyang-quan");
        map_skill("strike", "sanhua-juding");
        map_skill("parry", "quanzhen-jian");
        map_skill("sword", "quanzhen-jian");

        prepare_skill("cuff", "chunyang-quan");
        prepare_skill("strike", "sanhua-juding");

        create_family("ȫ���", 2, "����");
        set("inquiry", ([
                "miji" : (: ask_me :),
                "�ؼ�" : (: ask_me :),
]));
        set("chat_chance_combat", 50);
/*
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
*/
        setup();
        set("book_count", 1);
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/greyrobe")->wear();
}

void attempt_apprentice(object ob)
{
        mapping fam;
        string name,new_name;

        if( mapp(fam = ob->query("family")) && fam["family_name"] != "ȫ���" )
        {
                command ("say " + RANK_D->query_respect(this_player())
                        + "�����������ˣ�ϰ�仹���ȴӸ�λ������ɣ�");
                return;
        }

        if ((int)ob->query_skill("xiantian-gong", 1) < 60) {
                command("say ��ȫ������ڼ��书���������ڹ��ķ���");
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�����������칦�϶��µ㹦��");
                return;
        }

        if ((int)ob->query("shen") < 35000) {
                command("say ��ȫ������������������ɣ��Ե���Ҫ���ϡ�");
                command("say �ڵ��з��棬" + RANK_D->query_respect(ob) +
                        "�Ƿ����ò�����");
                return;
        }
        command("say �ðɣ�ƶ�����������ˡ�");
        name = ob->query("name");
        new_name = name[0..01]+"־" + name[4..5];
        command("say �ӽ��Ժ���ͽ���" + new_name + "��");
        ob->set("name",new_name);
        command("recruit " + ob->query("id"));
}
string ask_me()
{
        mapping fam;
        object ob, *obs,ob2 ;

        if (!(fam = this_player()->query("family")) || fam["family_name"] != "ȫ���")
                return RANK_D->query_respect(this_player()) +
                "�뱾��������������֪�˻��Ӻ�̸��";

        if (query("book_count") < 1)
                return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���";
           obs = filter_array(children("/d/zhongnan/obj/qz_force"), (: clonep :));
                  if (sizeof(obs) > 20)
                return "�������ˣ����ɵ��ڹ��ķ����ڴ˴���";

        ob=new("/d/zhongnan/obj/qz_force");
        ob->move(this_player());
        add("book_count", -1);
        command ("rumor "+this_player()->query("name")+"Ū����һ�������ڹ��ķ���");
        return "�ðɣ��Ȿ�������ڹ��ķ������û�ȥ�ú����С�";
}

