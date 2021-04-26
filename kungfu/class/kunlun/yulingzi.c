// xihuazi.c (kunlun)

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("������", ({ "yuling zi","yuling", "zi" }));
	set("long",
		"�������ɵ�������ӣ�������������ķ���������Ͷ�����ŵ�����֮�⡣\n");
	set("gender", "Ů");
	set("age", 28);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 23);
	set("con", 25);
	set("dex", 28);
	set("per", 28);

	set("max_qi", 850);
	set("max_qi", 850);
	set("max_jing", 600);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 30);
	set("combat_exp", 380000);
	set("score", 4000);

	set_skill("force", 100);
        set_skill("literate", 120);
        set_skill("qinqi-shuhua", 120);
	set_skill("xuantian-wuji", 100);
	set_skill("dodge", 100);
	set_skill("taxue-wuhen", 100);
	set_skill("parry", 100);
	set_skill("sword", 100);
        set_skill("liangyi-jian", 100);
        set_skill("strike", 100);
	set_skill("kunlun-zhang", 100);
	


	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
        map_skill("sword", "liangyi-jian");
        map_skill("strike", "kunlun-zhang");

       prepare_skill("strike", "kunlun-zhang");

	create_family("������", 5, "����");
	setup();
	carry_object("/d/kunlun/obj/sword")->wield();
	carry_object("/d/kunlun/obj/pao3")->wear();
}



