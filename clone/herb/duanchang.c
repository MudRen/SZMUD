// Code of ShenZhou
#include <ansi.h>
inherit ITEM;


void create()
{
        set_name(MAG"�ϳ���"NOR, ({"duanchangcao", "cao"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "Ǯ");
                set("long","�ϳ��ݣ��ݱ�ֲ���Ҷ�����綾��\n");
                set("value", 50);
		set("yaocai", 1);
        set("cure_s",0);
		set("cure_d",5);
		set("cure_n",0);
		
        }
        setup();
}
