// zhanchun.c (kunlun)

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("ղ��", ({ "zhan chun", "zhan", "chun" }));
	set("long",
		"���Ǻ�̫����ϲ���ĵ��ӣ����õ�Ҳ��Ϊ������\n");
	set("gender", "Ů��");
	set("age", 24);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 25);
	set("int", 24);
	set("con", 28);
	set("dex", 26);
	set("per", 26);

	set("max_qi", 600);
	set("max_jing", 400);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 30);
	set("combat_exp", 50000);
	set("score", 5000);

	set_skill("force", 80);
	set_skill("xuantian-wuji", 80);
	set_skill("dodge", 80);
	set_skill("taxue-wuhen", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
        set_skill("liangyi-jian", 80);
        set_skill("strike", 80);
	set_skill("kunlun-zhang", 80);

        map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
        map_skill("strike", "kunlun-zhang");
        map_skill("sword", "liangyi-jian");

       prepare_skill("strike", "kunlun-zhang");



	create_family("������", 5, "����");
	setup();
	carry_object("/d/kunlun/obj/sword")->wield();
	carry_object("/d/kunlun/obj/pao3")->wear();
}


