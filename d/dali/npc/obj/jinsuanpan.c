// Code of ShenZhou
// weapon: /d/dali/npc/obj/jinsuanpan.c
// lyu

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("������", ({ "jin suanpan", "suanpan" }) );
        set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������õ����̣�ȴ�Ǵ������ɵġ�\n");
                  set("value", 2500);
                set("material", "gold");
                set("wield_msg", "$N�ӱ���ȡ��һ��$n���������С�\n");
                set("unwield_msg", "$N�����е�$n���ڱ���\n");
        }

        init_hammer(25);
        setup();
}

