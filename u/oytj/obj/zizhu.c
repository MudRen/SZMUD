// u/oytj/obj/zizhu.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(MAG "紫竹" NOR, ({"fugui zhu","zhu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
        set("long","这是彩虹从很远的地方弄回来的竹子，非常漂亮。\n");  
                set_weight(30000);
                set("value", 5000000);
                set("unit", "株");
                set("no_get", 1);
                set("no_drop", 1);
        }
        setup();
}
