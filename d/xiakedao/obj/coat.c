//Cracked by Roath
#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name("�Ͳ�����", ({ "rain coat", "coat"}) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���Ͳ����¡�\n");
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("value", 0);
        }
        setup();
}

