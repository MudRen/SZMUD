// Code of ShenZhou
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("��ɨ��", ({ "sao ba", "ba" }));
        set_weight(50000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����������ɨ�ѣ�Լ��������ּ�Ϊ���ء�\n");
                set("material", "iron");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
	    set("shaolin",1);
        }
        init_staff(100);
        setup();
}

