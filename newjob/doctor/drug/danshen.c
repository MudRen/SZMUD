#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
        set_name( YEL "����" NOR , ({"dan shen", "shen"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "Ǯ");
                set("long", "���Σ������࣬�࣬΢������������Ѫ����Ԥ������Ѫ��\n");
                set("value", 100);
                set("yaocai", 1); 
                set("cure_s",0);
                set("cure_d",20);
                set("cure_n",0);
                  
}
        setup();
}
