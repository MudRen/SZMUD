// Code of ShenZhou
// cloth: wcloth.c
// Jay 3/17/96

#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("�����˳���", ({ "hazakh robe", "robe"}) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ɫ�Ĺ����˳���\n");
                set("material", "cloth");
                set("armor_prop/armor", 15);
                set("value", 100);
        }
        setup();
}

