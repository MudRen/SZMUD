// Code of ShenZhou
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("����", ({ "tie di", "di" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long", 
"����һֻ���������ĵ��ӣ������������ġ�\n");
                set("value", 100);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ����$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_sword(20);
        setup();
}

