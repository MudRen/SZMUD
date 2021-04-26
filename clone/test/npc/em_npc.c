// Code of ShenZhou

// modified from zhou 3/00

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        set_name("������", ({ "zhou zhiruo", "zhou"}));
        set("long", 
                "����һ��������������Ů�ӣ���������һ���̽���\n"
                "ֻ�����������ţ���ɫ������\n");
        set("gender", "Ů��");
        set("age", 62);
        set("attitude", "peaceful");
        set("shen_type", random(2)?-1:1);

        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
	set("kar", 20);
	set("per", 20);
        
        set("max_qi", 4000);
        set("max_jing", 4000);
        set("neili", 8000);
        set("max_neili", 8000);
        set("max_jingli", 5000);
        set("eff_jingli", 5000);
        set("jiali", 200);

        set("combat_exp", 6400000);
        set("score", 100000);

        set_skill("literate", 400);
        set_skill("mahayana", 400);
        set_skill("force", 400);
        set_skill("linji-zhuang", 400);
        set_skill("claw", 400);
        set_skill("jiuyin-zhao", 400);
        set_skill("strike", 400);
		set_skill("cuixin-zhang", 400);
        set_skill("jinding-zhang", 400);
        set_skill("finger", 400);
        set_skill("tiangang-zhi", 400);
		set_skill("whip", 400);
		set_skill("feiyu-bian", 400);
        set_skill("sword", 400);
        set_skill("emei-jian", 400);
        set_skill("parry", 400);
        set_skill("dodge", 400);
        set_skill("zhutian-bu", 400);
        set_skill("throwing", 400);
        set_skill("persuading", 400);
        set_skill("beauty", 400);

        map_skill("claw", "jiuyin-zhao");
        map_skill("force", "linji-zhuang");
	    map_skill("whip", "feiyu-bian");
        map_skill("sword", "emei-jian");
        map_skill("blade", "yanxing-dao");
        map_skill("parry", "emei-jian");
        map_skill("dodge", "zhutian-bu");
        map_skill("finger", "tiangang-zhi");
        map_skill("strike", "cuixin-zhang");

        prepare_skill("claw", "jiuyin-zhao");
        prepare_skill("finger", "cuixin-zhang");

        create_family("������", 4, "����");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
		(: exert_function("longhe") :),
		(: exert_function("recover") :),
		(: perform_action("sword.mie") :),
		(: perform_action("whip.heji") :),
		(: perform_action("whip.chanrao") :),
		(: exert_function("fengyun") :),

        }) );

/*
        set("inquiry", ([
            "���ʦ̫" : "���Ǳ��������ˣ��ڻ��������С�\n",
        ]));
*/
        setup();
        carry_object("/d/emei/npc/obj/hui-cloth")->wear();
        carry_object("/d/emei/npc/obj/emei-shoes")->wear();
        carry_object("/clone/weapon/changbian")->wield();
        carry_object("/clone/weapon/duanjian");

}

void attempt_apprentice(object ob)
{
    mapping fam;
    int last_betray;

        if ((string)ob->query("family/family_name") == "ؤ��" && ob->query("rank") > 1 ) {
                command("say " + RANK_D->query_respect(ob) + "��ؤ����֣�ˡ�Ҳ������㡣");
                return;
        }
        // Giving everybody one chance to enter emei
        last_betray=ob->query("zhou-betray");
        if (last_betray>0 && last_betray != ob->query("betrayer")) {
            if( ob->query("family/family_name") != "������"
            && ob->query("combat_exp") >= 10000 ) {
                command ("say " + RANK_D->query_respect(this_player()) +
                         "��Ȼ�ѳ�����, �˿����ȴ������. \n");
                command ("say " + RANK_D->query_respect(this_player()) + "��"
                        +ob->query("family/family_name")+"���֣����ɿɲ���������");
                return;
            }
        }
        if ((int)ob->query_skill("claw", 1) < 40) {
                command("say �ҿ�������ѧ�����澭�ϵĹ���ɣ���ȥѧ�������צ�������ɡ�");
                return;
        }

        if ((int)ob->query_skill("jiuyin-zhao", 1) < 40) {
                command("say �ҿ�������ѧ�����澭�ϵĹ���ɣ���ȥѧ��������ľ���צ�����ɡ�");
                return;
        }
        command("say �ðɣ���͸������ѧ�ɡ�"); 
        command("say ������ɼ�ס��, Ҫ��������ʦ��, �ҿɲ���������.\n");
        command("recruit " + ob->query("id"));
        ob->set("emei", 1);
        ob->set("zhou-betray", ob->query("betrayer"));
        command("whisper " + ob->query("id") + " �´�������ʱ�������϶��ڽ�һ���������º��������Ҿͻ����˴��������");
}
