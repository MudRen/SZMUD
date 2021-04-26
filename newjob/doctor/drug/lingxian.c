#include <ansi.h>
inherit ITEM;
int cure_ob(string);
void init();

void create()
{
        set_name( HIC "ÍşÁéÏÉ" NOR , ({"wei lingxian", "lingxian"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "Ç®");
                set("long", "ÍşÁéÏÉ: ¸ù¾¥Àà£¬Î¶¿à£¬ÆøÎÂ£¬ÓĞÇıÍ´£¬Ö¹ÑªÖ®Ğ§¡£\n");
                set("value", 100);
                set("yaocai", 1); 
                set("cure_s",0);
                set("cure_d",20);
                set("cure_n",0);
        }
        setup();
}
