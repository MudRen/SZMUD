#include <ansi.h>
inherit ITEM;
int cure_ob(string);
void init();

void create()
{
        set_name( HIW "天门冬" NOR , ({"tian mendong", "mendong"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "钱");
                set("long", "天门冬：根茎类，苦，平，可治肺痿咳嗽，吐涎，回燥。\n");
                set("value", 100);
                set("yaocai", 1); 
                set("cure_s",0);
                set("cure_d",20);
                set("cure_n",0);
        }
        setup();
}
