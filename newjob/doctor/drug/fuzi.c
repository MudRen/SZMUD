#include <ansi.h>
inherit ITEM;
int cure_ob(string);
void init();

void create()
{
        set_name( HIG "附子" NOR , ({"fu zi", "fuzi"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "钱");
                set("long", "附子(乌头)：根茎类，辛，温，有大毒。\n");
                set("value", 100);
                set("yaocai", 1); 
                set("cure_s",0);
                set("cure_d",20);
                set("cure_n",0);
        }
        setup();
}
