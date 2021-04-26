// Code of ShenZhou
// /d/changbai/renshen.c 人参

inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("长白山人参", ({"renshen", "shen"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "株");
                set("long", "这是一株沾满山泥的长白山人参。\n");
                set("medicine", 1);
                set("no_sell",  1);
                set("value",  100);
                set("highprice",1000);
                set("lowprice",500);
        }
        setup();
}
