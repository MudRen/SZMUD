// 苏梦馨(Athena)
// /u/athena/obj/bamboo.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIG "富贵竹" NOR, ({"fugui zhu","zhu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
        set("long","由于主人懒浇水,它长得并不茂盛，一半都干枯了,另一半却绿意盎然,倒象是练了枯荣神功!\n");  
                set_weight(30000);
                set("value", 5000000);
                set("unit", "株");
                set("no_get", 1);
                set("no_drop", 1);
        }
        setup();
}
