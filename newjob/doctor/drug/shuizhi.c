//by keny
#include <ansi.h>
inherit ITEM;
int cure_ob(string);
void init();

void create()
{
        set_name( HIC "ˮ��" NOR , ({"shuizhi"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", "ˮ�Σ��沿���̣��࣬ƽ���ж������ε������ˣ�׹�����ˣ���׶��ס�\n");
                set("value", 100);
                set("yaocai", 1); 
                set("cure_s",0);
                set("cure_d",0);
                set("cure_n",0);
        }
        setup();
}
