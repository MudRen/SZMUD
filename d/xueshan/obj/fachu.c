// Code of ShenZhou
// weapon: fachu.c

#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("����", ({ "fa chu", "fa","chu" }) );
        set_weight(25000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������µķ��ƣ�Ҳ��ɮ�ҵķ���������\n");
                set("value", 100);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_staff(20);
        setup();
}

