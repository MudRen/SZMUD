// Code of ShenZhou
#include <weapon.h>
inherit THROWING;

void create()
{
        set_name("�̸�", ({ "duan fu", "fu", "axe" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "��������ż���С��ͷ�����λεķ������ˡ�\n");
				set("base_unit", "��");
				set("value", 150);
                set("material", "steel");
                set("wield_msg", "$N�Ӳ�����γ�һ��$n��\n");
                set("unwield_msg", "$N��$n�Żز����\n");
        }
        init_throwing(25);
        set_amount(5);
        setup();
}
