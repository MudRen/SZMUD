// Code of ShenZhou
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("����", ({ "yao qin", "qin" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "��������ɫ���ɣ���������������ǧ��Ĺ��\n");
                set("value", 300);
                set("material", "wood");
                set("wield_msg", "$N����һ��$n�����С�\n");
                set("unwield_msg", "$N�����е�$n����������\n");
        }
        init_staff(25);
        setup();
}

