#include <ansi.h>
inherit ITEM;
int cure_ob(string);
void init();

void create()
{
        set_name( HIG "茅根" NOR , ({"miao geng", "geng"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "钱");
                set("long", "茅根：根茎类，甘，寒，治胃有伏热，令人胸满，引起气逆，气逆发。\n");
                set("value", 100);
                set("yaocai", 1); 
                set("cure_s",0);
                set("cure_d",20);
                set("cure_n",0);
        }
        setup();
}
