// Code of ShenZhou
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIG"��Ҷ"NOR, ({"he ye","heye","ye"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "��");
                set("long","��Ҷ����ͨ�ɻ�Ҷ��������ȥ��\n");
                set("value", 50);
				set("yaocai", 1);
        		set("cure_s",0);
		        set("cure_d",3);
		        set("cure_n",0);
		
        }
        setup();
}
