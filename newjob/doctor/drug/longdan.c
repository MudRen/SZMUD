#include <ansi.h>
inherit ITEM;
int cure_ob(string);
void init();

void create()
{
        set_name( HIR "龙旦" NOR , ({"long dan", "dan"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "钱");
                set("long", "龙旦：根茎类，苦，大寒，除下部风湿，一也；及湿热，二也；脐下至足肿痛，三也；寒湿脚气，四也。\n");
                set("value", 100);
                set("yaocai", 1); 
                set("cure_s",0);
                set("cure_d",20);
                set("cure_n",0);
        }
        setup();
}
