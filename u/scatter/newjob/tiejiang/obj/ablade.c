//Code by Scatter
// bblade.c

#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name("��", ({ "blade", "dao" }));
        set_weight(7000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Ѻ����ĵ��ӡ�\n");
                set("value", 250);
                set("material", "steel");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n����������\n");
        }
        init_blade(35);
        setup();
}