// Code of ShenZhou
// /kungfu/class/quanzhen/shen.c
// shen.c  ��־��
// sdong 08/01/98

inherit NPC;

void create()
{
	set_name("��־��", ({ "shen zhifan", "shen" }));
	set("long",
		"����һλȫ��̵��������ӡ�\n"
		);
	set("gender", "����");
	set("age", 46);
	set("attitude", "heroic");
	set("shen_type", 1);
	set("str", 20);
	set("int", 28);
	set("con", 28);
	set("dex", 20);

	set("max_qi", 1000);
	set("max_jing", 1000);
	set("max_jingli", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 100000);
	set("score", 6000);

	set_skill("force", 90);
	set_skill("xiantian-gong", 90);
	set_skill("dodge", 90);
	set_skill("jinyangong", 90);
	set_skill("cuff", 90);
	set_skill("chunyang-quan", 90);
	set_skill("strike", 90);
	set_skill("sanhua-juding", 90);
	set_skill("parry", 90);
	set_skill("sword", 90);
	set_skill("quanzhen-jian", 90);
	set_skill("literate", 80);
	set_skill("taoism", 90);
	set_skill("beidou-zhenfa", 90);

	map_skill("force", "xiantian-gong");
	map_skill("dodge", "jinyangong");
	map_skill("cuff", "chunyang-quan");
	map_skill("strike", "sanhua-juding");
	map_skill("parry", "quanzhen-jian");
	map_skill("sword", "quanzhen-jian");

	prepare_skill("cuff", "chunyang-quan");
	prepare_skill("strike", "sanhua-juding");

	create_family("ȫ���", 3, "����");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}


