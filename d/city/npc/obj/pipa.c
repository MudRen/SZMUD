// Code of ShenZhou
#include <ansi.h>
#include <weapon.h>

inherit HAMMER;
void create()
{
        set_name(HIM "����" NOR, ({ "pi pa"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���ǰ���ͷ�������⣬����̴�Ƴɵ�����ʮ��Ʒ���á�\n");
                set("value", 0);
                set("material", "wood");
                set("wield_msg", "$N����һ��$n�����С�\n");
                set("unwield_msg", "$N�����е�$n����������\n");
                }
        init_hammer(45);
        setup();
}
