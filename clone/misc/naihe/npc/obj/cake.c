// С���⣬�������ҵ�NPC���ġ�    ��/npc/obj/cake.c
// by naihe  2002-04-27

inherit ITEM;
#include <ansi.h>

int remaining=3;

void create()
{
	set_name(HIC"С����"NOR, ({"cake","dan gao"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "����һ������ƴ��С���⣬���ϻ�Ƕ�ſ�Сӣ�ң�������ζ������\n");
		set("unit", "��");
		set("value", 80);
		set("food_supply", 30);
	}
	setup();
}

void init()
{
	add_action("do_food", "eat");
	add_action("do_food", "eatt");
}

int do_food(string arg)
{
	object me=this_player();

	if (arg != "cake" && arg != "dan gao")
	return 0;

	if (me->is_busy())
	return notify_fail("�����ԣ��𼱡�\n");

//	if ((int)me->query("water") >= (int)me->max_water_capacity())
//	return notify_fail("���Ѿ��ȵ�̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");

	if ((int)me->query("food") >= (int)me->max_food_capacity())
	return notify_fail("���Ѿ��Ե�̫���ˣ���Ҳ�Ų����κζ����ˡ�\n");

	set("value", 0);
//	me->add("water", (int)query("drink_supply"));
	me->add("food", (int)query("food_supply"));

	if(me->is_fighting())
	me->start_busy(1);

	me->start_busy(1);
	remaining-=1;

	if (remaining>0)
		{
			message_vision("$N����С����ҧ��һ�ڣ�����ζ�����治��\n",me);
		}

	else
		{
			message_vision("$N��ʣ�µ�С����һ�ڳ�����ȥ�����ǻ�ζ���\n",me);
			destruct(this_object());
		}
	return 1;
}
