// Code of ShenZhou
// weapon: dafu.c ��ͷ
// qfy August 19, 1996.

#include <weapon.h>
inherit AXE;

void create()
{
        set_name("��ͷ", ({ "da futou", "futou", "axe" }));
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Ѽ���ɱ�����Ĵ�ͷ�����λεķ���֮����\n");
                set("value", 250);
//***** ADDED BY SCATTER *****
				set("wposition", "/clone/weapon/dafu.c");
//***** END OF ADDING *****
                set("material", "steel");
                set("wield_msg", "$N˫������$n��\n");
                set("unwield_msg", "$N����$n��\n");
        }
        init_axe(25);
        setup();
}

