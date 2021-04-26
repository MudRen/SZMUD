// Code of ShenZhou
// lt_snake.c ��ͷ�� ( ??? )
// by maco

#include <ansi.h>

inherit NPC;

int auto_perform_double();

void create()
{
	int poison = 10;
	set_name("��ͷ��", ({ "liangtou she", "she", "snake" }) );
	set("race", "����");
	set("age", 100);
	set("long", "�����߻��ư�쵣��������߷ֲ���Ȼ������ͷ������������\n��˵������ͷ�ߵ��ˣ�һ��������\n");
	set("attitude", "aggressive");

	set_weight(poison*600 + 9000);
	set("str", 30 + poison );
	set("con", 30 + poison );
	set("int", 20);
	set("dex", 30 + poison );

	set("max_jing", 9000);
	set("max_qi", 9000);
	set("max_jingli", 9000);

	set("limbs", ({ "��", "�Ҿ�", "����", "�ߴ�", "β��" }) );

	set("combat_exp", 1200000);

	set_temp("apply/attack", 700);
	set_temp("apply/damage", 250);
	set_temp("apply/dodge", 200);
	set_temp("apply/armor", 300);

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: auto_perform_double :),
	}));

	set("snake_poison", 60 + poison*40 +random(61));
	set("bt_snake", 1);

	setup();
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	victim->apply_condition("snake_poison", 10 + me->query("snake_poison")/5 +
		victim->query_condition("snake_poison") );
}

#include "snake_perform.h"
