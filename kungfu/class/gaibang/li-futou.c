// Code of ShenZhou
// gaibang npc code

inherit NPC;

void create()
{
	set_name("�ͷ", ({"li futou", "futou", "li"}));
	set("title", "ؤ����������");
	set("gender", "����");
	set("age", 32);
	set("long", 
		"�ͷ���Ժ�ˬ����ʹ��師�������޵У���ؤ�������ĺ���֮ʿ��\n");

	set("attitude", "heroism");
	set("str", 30);
	set("int", 18);
	set("con", 28);
	set("dex", 20);

	set("rank", 6);

	set("max_qi", 650);
	set("max_jing", 400);
	set("neili",600);
	set("max_neili", 600);
	set("jiali", 50);
	
	set("combat_exp", 166000);
	
	set_skill("force", 60); 
	set_skill("huntian-qigong", 60); 
	set_skill("strike", 55); 
	set_skill("xianglong-zhang", 65); 
	set_skill("axe", 80); 
	set_skill("dodge", 60); 
	set_skill("xiaoyaoyou", 50); 
	set_skill("parry", 60); 
	
	map_skill("force", "huntian-qigong");
	map_skill("strike", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");

	prepare_skill("strike", "xianglong-zhang");
	
	create_family("ؤ��", 19, "����");
	setup();

	carry_object("/d/gaibang/obj/budai")->set_amount(5);
	carry_object("/d/gaibang/obj/budai")->wear();
	carry_object("/clone/weapon/banfu")->wield();
}

#include "/kungfu/class/gaibang/promote.h"
