// Code of ShenZhou
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIR"�غ컨"NOR, ({"zanghonghua","hua"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "Ǯ");
                set("long","�غ컨����Ѫ֮����������Ѫ��\n");
                set("value", 2000);
				set("yaocai", 1);
        		set("cure_s",30);
		        set("cure_d",0);
		        set("cure_n",0);
		
        }
        setup();
}
