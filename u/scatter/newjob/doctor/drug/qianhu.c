#include <ansi.h>
inherit ITEM;
int cure_ob(string);
void init();

void create()
{
        set_name( WHT "ǰ��" NOR , ({"qian hu", "hu"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "Ǯ");
                set("long", "ǰ���������࣬�࣬΢������ʱ����Ϊ��ǰ��ζ��������΢ƽ���书����������������̵�ȡ����ԡ�Ʀ����Ż�����\n");
                set("value", 100);
                set("yaocai", 1); 
                set("cure_s",0);
                set("cure_d",0);
                set("cure_n",10);
        }
        setup();
}
