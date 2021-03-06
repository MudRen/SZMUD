// 金蜜散(jinmi san)
// by April 2001.11.10

#include <ansi.h>

inherit ITEM;

int cure_ob(string);
void init();

void create()
{
	set_name(HIW "金蜜散" NOR, ({"jinmi san", "jinmi", "san"}));
    set_weight(25);
    if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "包");
		set("value", 8000);
        set("medicine", 1);
	}

    setup();
}

int cure_ob(object me)
{
//	me->set("eff_jing", (int)me->query("max_jing"));
//	me->set("jing", (int)me->query("max_jing"));
//	me->set("eff_qi", (int)me->query("max_qi"));
//	me->set("qi", (int)me->query("max_qi"));
	if (me->query_condition("yf_zhen_poison") > 0)
        me->apply_condition("yf_zhen_poison", me->query_condition("yf_zhen_poison") - 100);
	if (me->query_condition("yufeng_poison") > 0)
        me->apply_condition("yufeng_poison", 0);
	message_vision(HIY "$N服下了一包金蜜散。苦中带甜，甜中带苦，一股香气沁人心脾。\n"NOR
		+HIY"你感觉体内的蜂毒已慢慢消去。\n" NOR, me);

	destruct(this_object());
	return 1;
}
