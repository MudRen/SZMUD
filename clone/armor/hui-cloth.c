// Code of ShenZhou
// hui-cloth.c
//

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("�಼�������", ({ "jia sha", "cloth" }) );
        set_color("$HIC$");
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/hui-cloth.c");
//***** END OF ADDING *****
                set("material", "cloth");
                set("armor_prop/armor", 8);
        }
        setup();
}

