// Code of ShenZhou
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIY"ţ��"NOR, ({"niuhuang"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "Ǯ");
                set("long","ţ�ƣ�ţ�ĵ���ʯ�����Խⶾ��\n");
                set("value", 5000);
				set("yaocai", 1);
        		set("cure_s",0);
		        set("cure_d",30);
		        set("cure_n",0);
		
        }
        setup();
}
