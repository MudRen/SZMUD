// Code of ShenZhou
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(YEL"��ɽ��"NOR, ({"chuanshanjia"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "Ǯ");
                set("long","��ɽ�ף�һ��ʳ���ޣ�Ƥ�׼�񣬿���ҩ����������Ԫ���������࣬�����˼�Ϊ��Ч��\n");
                set("value", 2500);
				set("yaocai", 1);
        		set("cure_s",0);
		        set("cure_d",0);
		        set("cure_n",30);
		
        }
        setup();
}
