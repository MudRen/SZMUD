// Code of ShenZhou
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(MAG"�赨"NOR, ({"shadan","dan"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "��");
                set("long","�赨��һ��ǳ������ĵ����ɽ�ٶ���\n");
                set("value", 6500);
				set("yaocai", 1);
        		set("cure_s",0);
		        set("cure_d",52);
		        set("cure_n",10);
		
        }
        setup();
}
