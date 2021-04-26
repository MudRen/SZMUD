#include <ansi.h>
inherit ITEM;
int cure_ob(string);
void init();

void create()
{
        set_name( WHT "Å£Ï¥" NOR , ({"niu xi", "xi"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "Ç®");
                set("long", "Å£Ï¥£º¸ù¾¥Àà£¬¿à£¬Ëá£¬Æ½£¬¿ÉÖÎÑüÏ¥¹ÇÍ´¡¢×ãğôÒõÏû£¬Ê§Äç¡£\n");
                set("value", 100);
                set("yaocai", 1); 
                set("cure_s",0);
                set("cure_d",20);
                set("cure_n",0);
        }
        setup();
}
