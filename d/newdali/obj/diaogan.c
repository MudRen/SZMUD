// Code of ShenZhou
#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("����", ({ "diao gan", "gan","staff" }) );
 
        set_weight(3000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���������ɵĵ��ˣ��������˸���˿��\n");
                set("value", 250);
                set("material", "steel");
                set("wield_msg", "$N���һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");
        }
        init_staff(25);
        setup();
}

