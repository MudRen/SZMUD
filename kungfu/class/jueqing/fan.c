// /d/jueqing/npc/fan.c
// Jiuer 2001-8-28  

inherit NPC;

void create()
{
	set_name("��һ��", ({ "fan yiweng","fan" }));
	set("long",
"��������ļ����������ĳߣ��������죬��ò���棬�������
һ�Ժ���ֱ�����أ���ī��ɫ���ۣ�������ɫ��������ò���ǹŹ֡�\n\n");
	
         set("age", 50);
	 set("combat_exp", 200000);
	 set("bellicosity", 1);
	 
	 set("gender","����");
	 set("attitude","aggressive");
	 
	 add_money("silver",10);
     
	 set("str", 28);
	 set("dex", 25);
     set("con", 23);
     set("int", 19);
     
	 set_skill("staff", 120);
     set_skill("unarmed", 120);
     set_skill("parry", 120);
     set_skill("force", 120);
     set_skill("dodge", 120);
	 
	 set("max_jingli",1000);
	 set("jingli",1000);
	 set("max_neili",1000);
	 set("neili",1000);
	 set("eff_jing",1000);
	 
	 set("jing",1000);
	 set("eff_qi",1000);
	 set("qi",1000);

	 setup();

         carry_object("/d/jueqing/npc/obj/staff")->wield();
         carry_object("/d/jueqing/npc/obj/greenrobe")->wear();
}


