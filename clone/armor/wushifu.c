// Code of ShenZhou
// wushifu.c ��ʿ��

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("��ʿ��", ({ "wushi fu", "fu", "cloth" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/wushifu.c");
//***** END OF ADDING *****
                set("armor_prop/armor", 5);
        }
        setup();
}

