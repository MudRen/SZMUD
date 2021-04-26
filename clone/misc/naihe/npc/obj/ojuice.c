// ����֭���������ҵ�NPC���ġ�    ��/npc/obj/ojuice.c
// by naihe  2002-04-29

inherit ITEM;
#include <ansi.h>

int remaining=(4+random(3));

void create()
{
	set_name(HIY"����֭"NOR, ({"orange juice", "juice"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "һ������ե�õ�����֭��\n");
		set("unit", "��");
		set("value", 300);
		set("drink_supply", 30);
	}
	setup();
}

void init()
{
	add_action("do_food", "drink");
        add_action("do_food", "he");
}

int do_food(string arg)
{
	object me=this_player();

	if (arg!="orange juice" && arg!="ojuice")
	return 0;

	if (me->is_busy())
	return notify_fail("����һ��������û����ɡ�\n");

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
		message_vision("$N����һ������֭������ζ���������ˡ�\n",me);
	}

	else
	{
		message_vision("$N��ʣ�µ�����֭һ�ںȵøɸɾ�����\n",me);

	destruct(this_object());
	}
	return 1;
}
