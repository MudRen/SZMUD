// Code of ShenZhou
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("�йٱ�", ({ "panguan bi", "bi" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", 
"����һ���������糤���йٱʣ�͸��ͨ�ڡ�\n");
                set("value", 100);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_sword(20);
        setup();
}

