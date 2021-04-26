// Code of ShenZhou
// cy_snake.c ����(���ݣ����ݸ�Ŀ)
// by maco

#include <ansi.h>

inherit NPC;

int auto_perform_duwu();

void create()
{
	int poison = 10;
	set_name("����", ({ "chi yan", "she", "snake" }) );
	set_color("$HIR$");
	set("long", "����һ������ͨ��Ķ��ߣ��������磬ϸС��ָ��\n�γ�ʱ�������Ȫ���η��֣��綾�ޱȣ���˵���Ǳ���ҧ�����߲�������\n");
	set("race", "����");
	set("age", 100);
	set("attitude", "aggressive");

	set_weight(8000);

	set("str", 30 + poison );
	set("con", 30 + poison );
	set("int", 20);
	set("dex", 30 + poison );

	set("max_jing", 10000);
	set("max_qi", 12000);
	set("qi", 12000);
	set("max_jingli", 10000);

	set("combat_exp", 2000000);

	set_temp("apply/attack", 500);
	set_temp("apply/damage", 300);
	set_temp("apply/dodge", 400);
	set_temp("apply/armor", 200);

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: auto_perform_duwu :),
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
