//Cracked by Roath
// zhubang.c ���

#include <ansi.h>
#include <weapon.h>
inherit STICK;

void create()
{
        set_name(GRN"�����"NOR, ({ "fishing pole", "pole" }));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���������ĵ���ˡ�\n");
                set("value", 250);
                set("material", "steal");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
        }
        init_stick(10);
        setup();
}
