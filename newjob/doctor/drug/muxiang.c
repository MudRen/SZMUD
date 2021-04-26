#include <ansi.h>
inherit ITEM;
int cure_ob(string);
void init();

void create()
{
        set_name( GRN "Ä¾Ïã" NOR , ({"mu xiang", "xiang"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "Ç®");
                set("long", "Ä¾Ïã£º¸ù¾¥Àà£¬ÐÁ£¬ÎÂ£¬ÐÐÆøÖ¹Í´£¬½¡Æ¢ºÍÎ¸¡£\n");
                set("value", 100);
                set("yaocai", 1); 
                set("cure_s",0);
                set("cure_d",20);
                set("cure_n",0);
        }
        setup();
}
