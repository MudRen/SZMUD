//Code by Scatter
// bcaidao.c

#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("�˵�", ({ "Caidao", "dao" }));
        set_weight(7000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����Ϊ�����Ĳ˵���\n");
                set("value", 160);
                set("material", "steel");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n����������\n");
        }
        init_blade(11);
        setup();
}