// Code of ShenZhou
#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name(HIW"�޻���"NOR, ({"wuhua guo","guo"}));
        set_weight(5);
        if (clonep())
                set_default_object(__FILE__);
        else 
        {
                set("unit", "Ǯ");
                set("long","����һǮ�޻�����\n");
                set("value", 1000);
                        set("yaocai", 1);
                        set("cure_s",0);
                        set("cure_d",-40);
                        set("cure_n",40);
                
        }
        setup();
}
