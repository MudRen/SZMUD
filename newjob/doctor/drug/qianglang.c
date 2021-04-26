//by keny
#include <ansi.h>
inherit ITEM;
int cure_ob(string);
void init();

void create()
{
        set_name( WHT "òŞòë" NOR , ({"qianglang"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "Ö»");
                set("long", "òŞòë£º³æ²¿£¬ÆøÎ¶ÏÌ£¬º®£¬ÓĞ¶¾£¬Ö÷ÖÎğÛÖ×¶ñ´¯£¬³à°×Á¡¡£
\n");
                set("value", 100);
                set("yaocai", 1); 
                set("cure_s",0);
                set("cure_d",0);
                set("cure_n",0);
        }
        setup();
}
