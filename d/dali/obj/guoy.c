// Code of ShenZhou
// renshen-guo.c 人参果

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(GRN "人参果" NOR, ({"renshen guo", "guo"}));
	set_weight(90);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("long", "这是一枚人参果，看上去就像一个白白胖胖的小娃娃。\n");
		set("value", 2);
		set("medicine", 1);
	}

	setup();
}

int cure_ob(object me)
{
	me->delete("yijin_wan");
        
	message_vision(GRN "$N急急忙忙地把人参果往嘴里一扔，连味道还没尝出来就整个的“咕咚”一声吞了下去\n" NOR, me);
	destruct(this_object());
	return 1;
}
