#include <ansi.h>
inherit ITEM;
int cure_ob(string);
void init();

void create()
{
        set_name( YEL "�ػ�" NOR , ({"di huang", "di"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "Ǯ");
                set("long", "�ػƣ�(���ػ�)�ʣ�����(��ػ�)�ʣ�΢�࣬΢�¡�����󺮶���Ѫ������΢�¶�����\n");
                set("value", 100);
                set("yaocai", 1); 
                set("cure_s",0);
                set("cure_d",20);
                set("cure_n",0);
        }
        setup();
}
