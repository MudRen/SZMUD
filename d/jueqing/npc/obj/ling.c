// ling.c
//jiuer 9/2001
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL "手令" NOR, ({ "shou ling", "ling" }));
	set("weight", 8);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",YEL"一卷纸制的庄主手令。\n"NOR);
		set("unit", "卷");
		set("material", "paper");
	}
	setup();
}	
