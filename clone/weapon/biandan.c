// Code of ShenZhou
// weapon: tiegun.c
// Summer. 10/7/96
#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("�ⵣ", ({ "biandan", "bian" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����ʵ�ıⵣ��\n");
                set("value", 40);
                set("material", "iron");
//***** ADDED BY SCATTER *****
				set("wposition", "/clone/weapon/biandan.c");
//***** END OF ADDING *****
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_staff(7);
        setup();
}

