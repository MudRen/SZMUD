// Code of ShenZhou
#include <weapon.h>
inherit AXE;

void create()
{
        set_name("�ָ�", ({ "gang fu" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����ִ���ĸ�ͷ��\n");
                set("value", 200);
                set("material", "steel");
                set("wield_msg", 
"$N��ৡ���һ���γ�һ�����������ĸ�ͷ�������\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
        }
        init_axe(20);
        setup();
}

