// Code of ShenZhou
// sbgun.c

#include <weapon.h>
inherit CLUB;

void create()
{
        set_name("������", ({ "suobo gun", "gun" }));
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���ɲ��õ�����������������̽(tan)���˲ε��ټ���\n");
                set("value", 200);
                set("material", "steel");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
              }
        init_club(5);
        setup();
}

