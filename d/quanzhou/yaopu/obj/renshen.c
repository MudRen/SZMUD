// Code of ShenZhou
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIW"�˲�"NOR, ({"renshen","shen"}));
	set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "֧");
                set("long","�˲Σ���Ʒ�������\n");
                set("value", 10000);
		set("yaocai", 1);
        	set("cure_s",100);
		set("cure_d",0);
		set("cure_n",0);
		
        }
        setup();
}
