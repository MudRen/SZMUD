// Code of ShenZhou
// tiebang.c ����
#include <ansi.h>
#include <weapon.h>
inherit STICK;

void create()
{
        set_name("����", ({ "tie bang", "bang" }));
        set_weight(9000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������ĳ�����\n");
                set("value", 350);
                set("material", "iron");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
        }
        init_stick(25);
        setup();
}
