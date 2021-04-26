// Code of ShenZhou
// gaibang npc code

inherit NPC;

void create()
{
	set_name("�����", ({"qiu wanjia", "qiu", "wanjia"}));
	set("title", "ؤ���������");
	set("gender", "����");
	set("age", 18);
	set("long", 
		"����������ؤ������ü��Ŀ�㣬�ƺ��Ǽ������䣬�����˵���ͷ��\n");

	set("attitude", "heroism");
	set("str", 17);
	set("int", 26);
	set("con", 20);
	set("dex", 20);

	set("rank", 2);

	set("max_qi", 250);
	set("max_jing", 250);
	set("neili", 100);
	set("max_neili",100);
	set("jiali", 20);
	
	set("combat_exp", 10000);
	
	set_skill("force", 20); 
	set_skill("huntian-qigong", 20); 
	set_skill("strike", 25); 
	set_skill("xianglong-zhang", 20); 
	set_skill("dodge", 20); 
	set_skill("xiaoyaoyou", 18); 
	set_skill("parry", 20); 
	set_skill("stealing", 10); 
	set_skill("checking", 30); 
	
	map_skill("force", "huntian-qigong");
	map_skill("strike", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	prepare_skill("strike", "xianglong-zhang");

	create_family("ؤ��", 19, "����");
	setup();

	carry_object("/d/gaibang/obj/budai")->set_amount(1);
	carry_object("/d/gaibang/obj/budai")->wear();
}

#include "/kungfu/class/gaibang/promote.h"
