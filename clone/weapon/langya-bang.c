// Code of ShenZhou
#include <ansi.h>
#include <weapon.h>
inherit STICK;

void create()
{
        set_name(YEL"������"NOR, ({ "langya bang", "bang" }));
        set_weight(25000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ڴֵ�������������һ�˵�����һ����������\n");
                set("value", 500);
                set("material", "steel");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
        }
        init_stick(50);
        setup();
}

