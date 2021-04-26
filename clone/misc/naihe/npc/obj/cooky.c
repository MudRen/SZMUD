// ��������������ҵ�NPC���ġ�    ��/npc/obj/cooky.c
// by naihe  2002-04-27

inherit ITEM;
#include <ansi.h>

int remaining=(3+random(4));

void create()
{
	set_name(HIY"�����"NOR, ({"cooky","bing" ,"bing gan"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "һС�����ɣ������5��6����ͦ�ɴ��ģ����\n");
		set("unit", "��");
		set("value", 100);
		set("food_supply", 20);
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

	if (arg!="cooky" && arg!="bing" && arg!="bing gan")
	return 0;

	if (me->is_busy())
	return notify_fail("����һ��������û����ɡ�\n");

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
		message_vision("$N�ӵ���������һ�������������ȥ��\n",me);
	}

	else
	{
		message_vision("$N�������������һ���������ʮ�ֲ���س�����ȥ��\n",me);
		destruct(this_object());
	}
	return 1;
}
