// Code of ShenZhou
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("����", ({ "chan zhang", "zhang" }));
        set_weight(28000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����������������ȣ�Լ��ʮ����Ǽ����ֵ��ر�����\n");
                set("value", 250);
                set("material", "steel");
//***** ADDED BY SCATTER *****
				set("wposition", "/clone/weapon/chanzhang.c");
//***** END OF ADDING *****
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
		set("shaolin",1);
        }
        init_staff(25);
        setup();
}

