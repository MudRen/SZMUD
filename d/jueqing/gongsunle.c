
// Filename:  gongsun lve ��������
// path:      /d/jueqinggu/npc/e.c
// By jiuer-> Aug 14, 2001

#include <ansi.h>

inherit NPC;

void create()
{
	object bj; 

	set_name("��������", ({ "gongsun lue", "gongsun", "lue" }));
	set("long",
		"�����Ǿ����ˮ��ׯׯ����Ů����\n\n"
		+"ֻ������ɫ���ﷺ�죬�����쳣��üĿ���ţ������峺���������СС���룬���ǽ�����\n\n");

	set("gender", "Ů��" );
	set("age", 17);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("combat_exp", 200000); 
	set("per",25); 
	set("str", 20); 
	set("int", 25);
	
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("jiajin", 10);
	set("jiali", 10);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jingli",1000);
	set("eff_jingli",1000);
	set("max_jingli",1000);

	set_skill("force", 150); 
	set_skill("blade", 150);
	set_skill("dodge", 150); 
	set_skill("parry", 150);
	set_skill("sword", 150);
	setup(); 
	
	carry_object("/u/jiuer/obj/greenrobe")->wear(); 
	carry_object("/d/city/obj/changjian")->wield();
}

void init()
{
	object ob;
	::init();
	return;
}
