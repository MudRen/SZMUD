// Code of ShenZhou
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIW"�Ͷ�"NOR, ({"ba dou","dou"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "Ǯ");
                set("long","�Ͷ���ɫ�ף�����϶���ĥ�ۺ������к�����ʿɽⶾ�������������á�\n");
                set("value", 1000);
				set("yaocai", 1);
        		set("cure_s",-1);
		        set("cure_d",2);
		        set("cure_n",0);
		
        }
        setup();
}
