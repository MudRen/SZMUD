// Code of ShenZhou
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("信", ({"mr-letter"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                
set("long","这是一封王语嫣写给慕容公子的信。\n");
                set("no_drop", "这样东西不能离开你。\n");
                set("material", "paper");
        }
}







