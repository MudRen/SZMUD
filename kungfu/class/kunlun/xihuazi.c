// xihuazi.c (kunlun)

inherit NPC;
    string ask_me();
inherit F_MASTER;

void create()
{
	set_name("������", ({ "xi huazi", "xi" }));
	set("long",
		"���������ɵ�������ӣ�������ף�����ʮ�ֱ��ꡣ\n");
	set("gender", "����");
	set("age", 26);
	set("attitude", "peaceful");
        set("shen_type", 1);
        set("book_count", 1);
	set("str", 30);
	set("int", 23);
	set("con", 25);
	set("dex", 28);

	set("max_qi", 800);
	set("max_qi", 800);
	set("max_jing", 600);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 30);
	set("combat_exp", 400000);
	set("score", 1000);

        set_skill("force", 80);
	set_skill("xuantian-wuji", 80);
	set_skill("dodge", 80);
	set_skill("taxue-wuhen", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("strike", 80);
	set_skill("kunlun-zhang", 80);
	set_skill("liangyi-jian", 80);
	
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
        map_skill("sword", "liangyi-jian");
        map_skill("strike", "kunlun-zhang");
	prepare_skill("strike", "kunlun-zhang");

	create_family("������", 5, "����");
set("inquiry",
                ([
                        "Ͷ���ؾ�" : (: ask_me :),
                           "ɥ�Ŷ�" : "���������ɶ��Ű�����\n",
                ]));
	setup();
	carry_object("/d/kunlun/obj/sword")->wield();
	carry_object("/d/kunlun/obj/pao3")->wear();
}
    string ask_me()
{
                  mapping fam;
                  object ob;

                  if (!(fam = this_player()->query("family"))
                 || fam["family_name"] != "������")
                                         return RANK_D->query_respect(this_player()) +
                                         "�뱾��������������֪�˻��Ӻ�̸��";
                  if (query("book_count") < 1)
                                         return "�������ˣ�Ͷ���ؾ��ѱ���ʦ�������ˡ�";
                  add("book_count", -1);
                  ob = new("/d/kunlun/obj/throwing-book.c");
                  ob->move(this_player());
                  return "Ͷ���ؾ������������סһ��Ҫ��ɥ�Ŷ�����ϰ���ú���Ҳ����֪����������ɥ�Ŷ�������!";
}





