#include <ansi.h>
inherit ITEM;
void create()
{       set_name(CYN"八仙桌"NOR,({"table"}));
        set("long","这是一张大理石制成的八仙桌，桌脚下印着苏府两个字。\n");
	set("unit","张");
	set("value",100);
	set("no_get",1);
        set("is_jiaju",1);
}
