// Code of ShenZhou
// dao-cloth.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("�Ҳ��������", ({ "jia sha", "cloth" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/dao-cloth.c");
//***** END OF ADDING *****
                set("material", "cloth");
                set("armor_prop/armor", 6);
        }
        setup();
}

