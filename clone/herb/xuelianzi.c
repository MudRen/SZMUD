//Cracked by Kafei
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIW"ѩ����"NOR, ({"xuelian zi","xuelian","zi"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "��");
                set("long","ѩ���ӣ���ɫ����ζ����Ѫ�������嶾������\n");
                set("value", 7000);
				set("yaocai", 1);
        		set("cure_s",20);
		        set("cure_d",30);
		        set("cure_n",40);
		
        }
        setup();
}
