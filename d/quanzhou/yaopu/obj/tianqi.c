// Code of ShenZhou
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIY"����"NOR, ({"tianqi"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "Ǯ");
                set("long","���ߣ��ݱ�ֲ��ɽⶾ��\n");
                set("value", 4500);
				set("yaocai", 1);
        		set("cure_s",5);
		        set("cure_d",30);
		        set("cure_n",0);
		
        }
        setup();
}
