// Code of ShenZhou
#include <ansi.h>
#include <weapon.h>
inherit AXE;

void create()
{
        set_name("С����", ({ "xiao tiefu", "axe" }));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", 
"����һ�����ִ����С��ͷ���ƺ���̫�ʺ�ս����ľ�����Է��ϲ���õĹ��ߡ�\n");
                set("value", 200);
                set("material", "steel");
                set("wield_msg", 
"$N��ৡ���һ���γ�һ������������С��ͷ�������\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
        }
        init_axe(10);
        setup();
}

