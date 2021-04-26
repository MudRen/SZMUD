#include <ansi.h>
inherit ITEM;
int cure_ob(string);
void init();

void create()
{
        set_name( YEL "ÍÁÜòÜß" NOR , ({"tu fuling", "fuling"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "Ç®");
                set("long", "ÍÁÜòÜß£º¸ù¾¥Àà£¬¸Ê£¬µ­£¬Æ½£¬Ö÷ÖÎ¹ÇÂÎÓ¸Â©£¬¹ÇÂÎÓ¸Â©¡£\n");
                set("value", 100);
                set("yaocai", 1); 
                set("cure_s",0);
                set("cure_d",20);
                set("cure_n",0);
        }
        setup();
}
