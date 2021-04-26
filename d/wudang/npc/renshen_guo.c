// Code of ShenZhou
// renshen-guo.c �˲ι�

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
	                                      
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIG "�˲ι�" NOR, ({"renshen guo", "guo"}));
	set_weight(90);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("long", "����һö�˲ι�������ȥ����һ���װ����ֵ�С���ޡ�\n");
		set("no_drop","��ô������˲ι����������ӣ� \n");
		set("value", 10000);
	}

	setup();
}

int do_eat(string arg)
{
	object me = this_player();

	if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	me->set("eff_jing", (int)me->query("max_jing"));
	me->set("jing", (int)me->query("max_jing"));
	me->set("eff_qi", (int)me->query("max_qi"));
	me->set("qi", (int)me->query("max_qi"));
	me->set("neili", (int)me->query("max_neili"));
	me->set("max_neili", (int)me->query("max_neili")+1);
	me->set("food", (int)me->max_food_capacity());
        me->set("water", (int)me->max_water_capacity());
        
	message_vision(HIG "$N����һö�˲ι���ֻ���þ���������Ѫ��ӯ����������ԴԴ��������ƣ������һɨ����! \n" NOR, me);

	destruct(this_object());
	return 1;
}
