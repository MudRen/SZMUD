// Code of ShenZhou

#include <ansi.h>

inherit ITEM;

int cure_ob(string);
void init();

void create()
{
	set_name(RED "?????˵?" NOR, ({"xuming badan", "badan", "dan"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "??");
		set("value", 50000);
                set("no_sell", 1);
		set("medicine", 1);
	}
set("wposition", "/clone/drug/badan.c");

	setup();
}

int cure_ob(object me)
{
	me->set("eff_jing", (int)me->query("max_jing"));
	me->set("jing", (int)me->query("max_jing"));
	me->set("eff_qi", (int)me->query("max_qi"));
	me->set("qi", (int)me->query("max_qi"));
	if (me->query_condition("insect_poison") > 30)
	me->apply_condition("insect_poison", 0);
	if (me->query_condition("snake_poison") > 30)
	me->apply_condition("snake_poison", 0);
	if (me->query_condition("sl_poison") > 30)
	me->apply_condition("sl_poison", 0);
	if (me->query_condition("xx_poison") > 30)
       	me->apply_condition("xx_poison", me->query_condition("xx_poison") - 30); 
	if (me->query_condition("xx_poison") > 50)
        me->apply_condition("xx_poison", me->query_condition("xx_poison") - 50);
	if (me->query_condition("hanbing_damage") > 30)
	me->apply_condition("hanbing_damage", 10);
	message_vision(HIG "$N????һ???????˵??????????˻???! \n" NOR, me);

	destruct(this_object());
	return 1;
}
