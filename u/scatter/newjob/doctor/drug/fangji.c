#include <ansi.h>
inherit ITEM;
int cure_ob(string);
void init();

void create()
{
        set_name( BLU "����" NOR , ({"fang ji", "ji"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "Ǯ");
                set("long", "�����������࣬����ƽ�������˺��������������ԡ�\n");
                set("value", 100);
                set("yaocai", 1); 
                set("cure_s",10);
                set("cure_d",4);
                set("cure_n",23);
        }
        setup();
}
