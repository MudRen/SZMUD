#include <ansi.h>
inherit ITEM;
int cure_ob(string);
void init();

void create()
{
        set_name( HIY "人吉梗" NOR , ({"ren jigeng", "jigeng"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "钱");
                set("long", "人吉梗：根茎类，辛，微温，有小毒；李时珍认为：“当以苦、辛、平为”，有驱痛，下痰，降血之效。\n");
                set("value", 100);
                set("yaocai", 1); 
                set("cure_s",0);
                set("cure_d",20);
                set("cure_n",0);
        }
        setup();
}
