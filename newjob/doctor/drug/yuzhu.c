#include <ansi.h>
inherit ITEM;
int cure_ob(string);
void init();

void create()
{
        set_name( HIG "”Ò÷Ò" NOR , ({"yu zhu", "zhu"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "«Æ");
                set("long", "”Ò÷Ò£∫∏˘æ•¿‡£¨∏ £¨–¡£¨∫Æ£¨”–∂æ£¨ø…÷Œ…ﬂ≥Ê“ß…À°£\n");
                set("value", 100);
                set("yaocai", 1); 
                set("cure_s",20);
                set("cure_d",15);
                set("cure_n",5);
        }
        setup();
}
