// Code of ShenZhou
//rama@sz

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("不知名的书", ({"noname book"}));
        set_weight(10);
        set_weight(1);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一本破破旧旧的书，不知道是用什么文字写成的。\n");
                set("unit", "本");
                set("material", "paper");
                set("value", 2000);
                set("no_sell", 1);
        }
}


