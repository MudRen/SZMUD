// Code of ShenZhou
// weapon: tiejiang.c

#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("����", ({ "tie jiang", "jiang" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���ں������������������ű�����\n");
                set("value", 300);
                set("material", "iron");
                set("wield_msg", "$N˫������һ��$n��\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_staff(30);
        setup();
}

