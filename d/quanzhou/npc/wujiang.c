// Code of ShenZhou
// wujiang.c �佫

#include <ansi.h>

inherit NPC;
inherit F_SKILL;

void create()
{
	set_name("�佫", ({ "wu jiang", "wu", "jiang" }));
	set_color("$YEL$");
	set("gender", "����");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "��վ�������ȷ��˵���������硣\n");
	set("combat_exp", 75000);
	set("shen_type", 0);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("sword", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 400); 
	set("max_neili", 400);
	set("jiali", 10);

	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/clone/armor/tiejia")->wear();
}

void init()
{
	object ob;
//	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}
int accept_fight(object me)
{
        command("say ��ү����������ɱ�ţ��������㵹ù��\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

int accept_kill(object me)
{
        command("say ��ү����������ɱ�ţ��������㵹ù��\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}
