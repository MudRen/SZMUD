#include <ansi.h>
inherit ITEM;
int cure_ob(string);
void init();

void create()
{
        set_name( WHT "�Ӻ���" NOR , ({"yan husuo", "husuo"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "Ǯ");
                set("long", "�Ӻ����������࣬����ƽ������ʹ������֮Ч��\n");
                set("value", 100);
                set("yaocai", 1); 
                set("cure_s",10);
                set("cure_d",-9);
                set("cure_n",17);
        }
        setup();
}
