#include <ansi.h>
inherit ITEM;
int cure_ob(string);
void init();

void create()
{
        set_name( HIY "黄精" NOR , ({"huang jing", "jing"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "钱");
                set("long", "黄精：根茎类，甘、平，有补肝，去弱之效。\n");
                set("value", 100);
                set("yaocai", 1); 
                set("cure_s",0);
                set("cure_d",20);
                set("cure_n",0);
        }
        setup();
}
