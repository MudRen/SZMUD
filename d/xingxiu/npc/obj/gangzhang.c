// Code of ShenZhou
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("����", ({ "gang zhang", "zhang" }));
        set_weight(28000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���ڹ�����ĸ��ȣ�Լ��ʮ����Ǽ������޴���ر�����\n");
                set("value", 350);
                set("material", "steel");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n����������\n");
        }
        init_staff(25);
        setup();
}

