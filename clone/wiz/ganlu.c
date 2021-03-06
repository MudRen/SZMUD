// Code of ShenZhou
// ganlu.c 甘露

#include <ansi.h>

inherit ITEM;

int cure_ob(string);
void init();

void create()
{
	set_name(HIM "甘露" NOR, ({"gan lu", "lu"}));
	set_weight(10);

	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "滴");
		set("long", "这是一滴观音菩萨的甘露，晶莹的水滴散发着异样的光芒。\n");
		set("value",0);
		set("medicine", 1);
	}

	setup();
}

int cure_ob(object me)
{
	object *inv;
	int i;

	me->clear_condition();

	if ( me->query_temp("sanxiao") ){
		me->delete_temp("sanxiao");
		me->delete_temp("smile");
	}

	me->set("eff_jing", (int)me->query("max_jing"));
	me->set("jing", (int)me->query("max_jing"));
	me->set("jingli", (int)me->query("max_jingli"));
	me->set("eff_qi", (int)me->query("max_qi"));
	me->set("qi", (int)me->query("max_qi"));
	me->set("neili", (int)me->query("max_neili"));
	me->set("food", (int)me->max_food_capacity());
	me->set("water", (int)me->max_water_capacity());
        
	message_vision(HIG"甘露撒心，$N只觉得精神健旺，气血充盈，体内真力源源滋生，\n"
		+"将疲乏饥渴一扫而空而且所中的毒也没了! \n"NOR, me);

	destruct(this_object());
	return 1;
}
