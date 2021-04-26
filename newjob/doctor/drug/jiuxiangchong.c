//by keny
#include <ansi.h>
inherit ITEM;
int cure_ob(string);
void init();

void create()
{
        set_name( HIC "¾ÅÏã³æ" NOR , ({"jiuxiang chong"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "Ö»");
                set("long", "¾ÅÏã³æ£º³æ²¿£¬ÏÌ£¬ÎÂ£¬Ö÷ÖÎëõëäÖÍÆø£¬Æ¢Éö¿÷Ëğ£¬ÔªÑô²»×ã¡£\n");
                set("value", 100);
                set("yaocai", 1); 
                set("cure_s",0);
                set("cure_d",0);
                set("cure_n",0);
        }
        setup();
}
