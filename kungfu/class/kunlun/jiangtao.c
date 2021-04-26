// jiangtao.c (kunlun)

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����", ({ "jiang tao", "jiang"}));
	set("long",
		"������ɫ���ۣ�����б�峤������ʮ�˾�����͡�\n"
		"���ֺ�˪��һ��Ҫ�������ǵ�ģ����\n");
	set("gender", "����");
	set("age", 20);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("str", 26);
	set("int", 24);
	set("con", 24);
	set("dex", 25);

	set("max_qi", 500);
	set("max_jing", 450);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 30);
	set("combat_exp", 80000);
	set("score", 10000);

	set_skill("force", 80);
        set_skill("literate", 80);
        set_skill("qinqi-shuhua", 80);
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
	setup();
       carry_object("/d/kunlun/obj/sword")->wield();
	carry_object("/d/kunlun/obj/pao3")->wear();
}


