// Code of ShenZhou
// cloth.c
//

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("�಼ɮ��", ({ "cloth" }) );
        set_color("$HIC$");
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/seng-cloth.c");
//***** END OF ADDING *****
                set("armor_prop/armor", 1);
        }
        setup();
}

