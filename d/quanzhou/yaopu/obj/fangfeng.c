// Code of ShenZhou
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(YEL"����"NOR, ({"fangfeng"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "Ǯ");
                set("long","���磺������ҩ�����Ե�����ࡣ\n");
                set("value", 200);
				set("yaocai", 1);
        		set("cure_s",0);
		        set("cure_d",0);
		        set("cure_n",5);
		
        }
        setup();
}
