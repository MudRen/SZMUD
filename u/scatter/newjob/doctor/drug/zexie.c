#include <ansi.h>
inherit ITEM;
int cure_ob(string);
void init();

void create()
{
        set_name( WHT "��к" NOR , ({"ze xie", "xie"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "Ǯ");
                set("long", "��к�������࣬�ʣ�����ʵ�η�����ʣ�����������аʪ��\n");
                set("value", 100);
                set("yaocai", 1); 
                set("cure_s",10);
                set("cure_d",20);
                set("cure_n",5);
        }
        setup();
}
