// Code of ShenZhou
//

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("´óºìôÂôÄ", ({ "jia sha","jiasha", "cloth" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¼þ");
                set("material", "cloth");
                set("armor_prop/armor", 20);
		set("value",1500);
        }
        setup();
}

