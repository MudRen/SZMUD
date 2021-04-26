// Code of ShenZhou
// lotus.c
#include <ansi.h>

inherit COMBINED_ITEM;

int value() { return query_amount() * (int)query("base_value"); }

void create()
{
          set_name(HIW "荷花" NOR, ({"he hua", "lotus"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
                  set("long", "这是一朵雨后白荷散发着淡淡的清香,花瓣上还有一滴如泪滴状的雨珠.。\n");
		set("unit", "朵");
		set("value", 50);
		set("base_unit", "朵");
        set("base_weight", 100);
	set("flower_w",1);
			}
	set_amount(1);
}

