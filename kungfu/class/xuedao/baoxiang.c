// Code of ShenZhou
// Summer 9/26/1996.
inherit F_MASTER;
inherit NPC;
string ask_me();

void create()
{
	set_name("����", ({ "bao xiang", "bao", "xiang" }));
	set("long", 
"һ�����߼��ݵ�ɮ�ˣ�������â���䡣������Ѫ���������£������ĺ�������\n");
	set("gender", "����");
	set("age", 30);
	set("attitude", "heroism");
	set("class","lama");
	set("chat_chance", 20);
	set("shen_type", -1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("max_qi", 800);
	set("max_jing", 450);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 60);
	set("combat_exp", 90000);

	set_skill("force", 60);
	set_skill("dodge", 60);
	set_skill("lamaism", 60);
	set_skill("parry", 60);
	set_skill("blade", 60);
	set_skill("xue-dao", 60);
	set_skill("cuff", 60);
	set_skill("yujiamu-quan", 60);
	set_skill("xueshitiao", 60);
	set_skill("longxiang-banruo", 60);
	set("book_count", 1);
	set("inquiry", ([
                "Ѫ������" : (: ask_me :),
        ]));

	map_skill("force", "longxiang-banruo");
	map_skill("blade", "xue-dao");
	map_skill("dodge", "xueshitiao");
	map_skill("parry", "xue-dao");
	map_skill("cuff", "yujiamu-quan");

	prepare_skill("cuff", "yujiamu-quan");
	

	create_family("Ѫ����", 5, "����");

	setup();
	carry_object("/d/qilian/obj/miandao")->wield();
	carry_object("/d/qilian/obj/lamajiasha")->wear();
}
void attempt_apprentice(object ob)
{
        if (ob->query("gender")=="Ů��") {
                command ("say ���ɲ���Ů���ӣ����ȥ�ɡ�");
                return;
        }

	if( ob->query("family/family_name") != "ѩɽ��"
        && ob->query("family/family_name") != "Ѫ����"
        && ob->query("combat_exp") >= 10000 ) {
                command ("say " + RANK_D->query_respect(this_player()) + "��"
                +ob->query("family/family_name")+"���֣����ɿɲ���������");
                return;
        }
	if ((int)ob->query_skill("longxiang-banruo", 1) < 30) {
                command("say " + RANK_D->query_respect(ob) +
                        "����������������췹�ɳԲ�����");
                return;
	}
	command("say �ðɣ�ƶɮ���������ˡ�");
        command("recruit " + ob->query("id"));
}
string ask_me()
{
	mapping fam;
        object ob;
        if (!(fam = this_player()->query("family")) || fam["family_name"] !="Ѫ����")
                return  "�ҡ�������֪����";
        if (query("book_count") < 1)
                return "�ҡ�������֪����";
        if( (random(30) > 5))
                return "�ҡ�������֪����\n";
        add("book_count", -1);
        ob = new("/d/qilian/obj/xuedao_book");
        ob->move(this_player());
        return "�ðɣ��Ȿ��ͽ���㿴����ɡ�";
}
