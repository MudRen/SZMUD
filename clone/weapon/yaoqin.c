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
                set("value", 5000);
                set("material", "wood");
                set("wield_msg", "$N����һ��$n�����С�\n");
                set("unwield_msg", "$N�����е�$n����������\n");
                set("shape", "zither");
        }
        init_staff(45);
        setup();
}
void init()
{
	add_action("do_lianxi", "lianxi");
}

#include "/d/taohua/obj/music.h"
