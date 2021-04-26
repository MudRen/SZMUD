// Code of ShenZhou
// gaibang npc code

inherit NPC;

void create()
{
	set_name("������", ({"jiang shangyou", "jiang shangyou", "jiang"}));
	set("title", "ؤ���������");
	set("gender", "����");
	set("age", 28);
	set("long", 
		"����Զ��������Ǳˮ���֣��������˸���žͽС������㡹�����Ρ�\n");

	set("attitude", "peaceful");
	set("str", 20);
	set("int", 24);
	set("con", 20);
	set("dex", 28);

	set("rank", 5);

	set("max_qi", 550);
	set("max_jing", 550);
	set("neili", 400);
	set("max_neili", 400);
	set("jiali", 40);
	
	set("combat_exp", 100000);
	
	set_skill("force", 50); 
	set_skill("huntian-qigong", 55); 
	set_skill("hand", 55); 
	set_skill("shexing-diaoshou", 45); 
	set_skill("dodge", 55); 
	set_skill("xiaoyaoyou", 50); 
	set_skill("parry", 50); 
	set_skill("stealing", 60); 
	
	map_skill("force", "huntian-qigong");
	map_skill("hand",  "shexing-diaoshou");
	map_skill("dodge", "xiaoyaoyou");
	
	prepare_skill("hand", "shexing-diaoshou");

	create_family("ؤ��", 19, "����");

	setup();

	carry_object("/d/gaibang/obj/budai")->set_amount(4);
	carry_object("/d/gaibang/obj/budai")->wear();
}

#include "/kungfu/class/gaibang/promote.h"
