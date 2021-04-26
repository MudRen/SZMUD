// Code of ShenZhou
// cui.c ��Ա��
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("��Ա��", ({ "cui yuanwai", "cui" }));
        set_color("$YEL$");
	set("gender", "����");
	set("age", 55);

	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 10);

	set("combat_exp", 25000);
	set("shen_type", -1);
	setup();
	add_money("silver", 50);
	carry_object(__DIR__"obj/yaoshi");
}
	
int accept_kill(object me)
{
        command("say ���컯��֮�¾�������ɱ�ˣ�û��������\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}


