//jiuer 09/09/2001
// longhua.c  龙女花

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIR "龙女花" NOR, ({ "longnu hua", "hua" }));
	set("weight", 10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",HIR"一朵深红色的鲜花，正开得灿烂。\n"NOR);
		set("unit", "朵");
		set("material", "wood");
	}
	setup();
}	
