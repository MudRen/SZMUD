// Code of ShenZhou
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(MAG"��̥"NOR, ({"bao tai","baotai","tai"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "ֻ");
                set("long","��̥����֮�����������Ч���Ա�̥����֮ҩ������ǿ��ǵ�Ч����\n");
                set("value", 12000);
				set("yaocai", 1);
        		set("cure_s",30);
		        set("cure_d",0);
		        set("cure_n",72);
		
        }
        setup();
}
