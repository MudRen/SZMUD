// Code of ShenZhou
// xu-cloth.c
//

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("»Æ²¼ôÂôÄ", ({ "jia sha", "cloth" }) );
        set_color("$HIY$");
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "cloth");
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/xu-cloth.c");
//***** END OF ADDING *****
                set("armor_prop/armor", 2);
        }
        setup();
}

