// Code of ShenZhou
// guitou-dao.c  ��ͷ��
// Sure 2001.5

#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
        set_name(CYN"��ͷ��"NOR, ({ "guitou dao","guitou","dao" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����λεĹ�ͷ����������֨���������ֻ���Դ���һҡ�������⡱ֱ�졣\n");
                set("value", 1000);
                set("material", "steel");
                set("wield_msg", "$N�������⡹��һ������һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n���¡�\n");
        }
        init_blade(100);
        setup();
}
