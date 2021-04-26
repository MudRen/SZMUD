// Code of ShenZhou
// gaibang npc code

inherit NPC;

void create()
{
	set_name("�Թ���", ({"zhao gouer", "zhao", "gouer"}));
	set("title", "ؤ��һ������");
	set("gender", "����");
	set("age", 16);
	set("long", 
		"�����������ŵ�С��ؤ����������·�߻������ش��˯��\n");
	set("attitude", "peaceful");
	set("str", 22);
	set("int", 20);
	set("con", 25);
	set("dex", 26);

	set("rank", 1);

	set("max_qi", 120);
	set("max_jing", 120);
	set("neili", 30);
	set("max_neili", 30);
	set("jiali", 3);
	
	set("combat_exp", 2000);
	
	set_skill("force", 12); 
	set_skill("huntian-qigong", 10); 
	set_skill("strike", 10); 
	set_skill("dodge", 10); 
	set_skill("parry", 70); 
	set_skill("begging", 30); 
	set_skill("stealing", 40); 
	set_skill("checking", 10); 
	
	map_skill("force", "huntian-qigong");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("ؤ��", 20, "����");
	setup();

	carry_object("/d/gaibang/obj/budai")->wear();
}

#include "/kungfu/class/gaibang/promote.h"
