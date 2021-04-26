// Code of ShenZhou
// qing-cloth.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("°×²¼ºÚ±ßôÂôÄ", ({ "jia sha", "cloth" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "cloth");
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/qing-cloth.c");
//***** END OF ADDING *****
                set("armor_prop/armor", 4);
        }
        setup();
}

