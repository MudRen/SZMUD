// Code of ShenZhou
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(YEL"����"NOR, ({"chantui"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "Ǯ");
                set("long","���ɣ������׳��ɱ����ɳ����ŵĿǣ���ȥ��ʪ��Ч����\n");
                set("value", 80);
				set("yaocai", 1);
        		set("cure_s",3);
		        set("cure_d",0);
		        set("cure_n",0);
		
        }
        setup();
}
