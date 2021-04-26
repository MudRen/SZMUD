// ���ȣ��������ҵ�NPC���ġ�    ��/npc/obj/coffee.c
// by naihe  2002-04-27

inherit ITEM;
#include <ansi.h>

int remaining=3;

void create()
{
	set_name(WHT"����"NOR, ({"coffee","kafei"}));

	set_weight(180);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "����һ����ζŨ����������Ʒ�����ֽ��������ȡ�����˵�Ǳߵ��˶���������\n");
		set("unit", "��");
		set("value", 1000);
		set("drink_supply", 100);
	}
	setup();
}

void init()
{
	add_action("do_food", "drink");
	add_action("do_food", "drink");
}

int do_food(string arg)
{
	object me=this_player();
	
	if (arg!="coffee" && arg!="kafei")
	return 0;

	if (me->is_busy())
	return notify_fail("�����ȣ��𼱡�\n");

	if ((int)me->query("water") >= (int)me->max_water_capacity())
	return notify_fail("���Ѿ��ȵ�̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");

	set("value", 0);
	me->add("water", (int)query("drink_supply"));
//	me->add("food", (int)query("food_supply"));

	if(me->is_fighting())
	me->start_busy(1);

	me->start_busy(1);
	remaining-=1;

	if (remaining>0)
	{
		message_vision("$N����һ�����ȣ�ϸϸ������һ�ڡ�\n",me);
	}

	else
	{
		message_vision("$N���𿧷ȣ������һ�ں�����ȥ��\n",me);

	destruct(this_object());
	}
	return 1;
}
