// Code of ShenZhou
// ҩ��

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("ҩ��", ({ "yaochu", "chu" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����ƵĲ�ҩ�õ�ҩ����\n");
                set("value", 30);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_hammer(30);
        setup();
}

