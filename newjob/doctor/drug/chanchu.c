//by keny
#include <ansi.h>
inherit ITEM;
int cure_ob(string);
void init();

void create()
{
        set_name( HIC "Û∏Ú‹" NOR , ({"chanchu"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "÷ª");
                set("long", "Û∏Ú‹£∫≥Ê≤ø£¨∆¯Œ∂Û∏À÷£∫∏ –¡£¨Œ¬£¨”–∂æ°Æ–¡°¢¡π°¢Œ¢∂æ°Ø ÷˜÷Œ∞Œ»°€∂æ£¨∆∆…À∑Á°£\n");
                set("value", 100);
                set("yaocai", 1); 
                set("cure_s",0);
                set("cure_d",0);
                set("cure_n",0);
        }
        setup();
}
