//by keny
#include <ansi.h>
inherit ITEM;
int cure_ob(string);
void init();

void create()
{
        set_name( RED "���" NOR , ({"feilian"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", "��󹣺�沿���̣������ж���������Ѫ��֢�ᣬ���ȣ���������Ѫ����\n");
                set("value", 100);
                set("yaocai", 1); 
                set("cure_s",0);
                set("cure_d",0);
                set("cure_n",0);
        }
        setup();
}
