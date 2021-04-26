//by keny
#include <ansi.h>
inherit ITEM;
int cure_ob(string);
void init();

void create()
{
        set_name( YEL "òãòµ" NOR , ({"feimeng"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "Ö»");
                set("long", "òãòµ£º³æ²¿£¬¿à£¬Î¢º®£¬ÓÐ¶¾£¬Ö÷ÖÎµø×¹ðöÑª£¬Éßó§Ñª³ö¡£\n");
                set("value", 100);
                set("yaocai", 1); 
                set("cure_s",0);
                set("cure_d",0);
                set("cure_n",0);
        }
        setup();
}
