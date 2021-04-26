// Code of ShenZhou
// gaibang npc code

inherit NPC;

void create()
{
	set_name("Ī����", ({"mo bushou", "mo", "bushou"}));
	set("title", "ؤ����������");
	set("gender", "����");
	set("age", 21);
	set("long", 
		"���Ǹ���ͷ�����������ؤ��������Ÿ�����ߺߣ����㲻�գ������գ�˭Ҳ��Ը�� ...��\n");

	set("attitude", "peaceful");
	set("str", 25);
	set("int", 22);
	set("con", 18);
	set("dex", 25);

	set("rank", 3);

	set("max_qi", 300);
	set("max_jing", 300);
	set("neili", 150);
	set("max_neili", 150);
	set("jiali", 25);
	
	set("combat_exp", 29000);
	
	set_skill("unarmed", 30);
	set_skill("force", 30); 
	set_skill("huntian-qigong", 30); 
	set_skill("stick", 30); 
	set_skill("dagou-bang", 35); 
	set_skill("dodge", 30); 
	set_skill("xiaoyaoyou", 30); 
	set_skill("parry", 32); 
	set_skill("begging", 30); 
	set_skill("checking", 20); 
	
	map_skill("force", "huntian-qigong");
	map_skill("stick", "dagou-bang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("ؤ��", 19, "����");
	setup();

	carry_object("/d/gaibang/obj/budai")->set_amount(4);
	carry_object("/d/gaibang/obj/budai")->wear();
	carry_object("/d/village/npc/obj/stick")->wield();
}

#include "/kungfu/class/gaibang/promote.h"
