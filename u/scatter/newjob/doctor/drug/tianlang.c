//by keny
#include <ansi.h>
inherit ITEM;
int cure_ob(string);
void init();

void create()
{
        set_name( GRN "���ɣ���" NOR , ({"tanglang sangpiaoxiao","tianlang"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", "���ɣ��٣��沿���̣��ʣ�ƽ�������ž����ǣ��������ͣ��ʺ�������\n");
                set("value", 100);
                set("yaocai", 1); 
                set("cure_s",0);
                set("cure_d",0);
                set("cure_n",0);
        }
        setup();
}
