// Code of ShenZhou
// weapon: /d/xingxiu/npc/obj/yaochu.c
// Jay 3/18/96

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("������", ({ "tie suanpan", "suanpan" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������õ����̣�ȴ�Ǿ������ơ�\n");
                set("value", 1000);
                set("material", "iron");
                set("wield_msg", "$N�ӱ���ȡ��һ��$n���������С�\n");
                set("unwield_msg", "$N�����е�$n���ڱ���\n");
        }

        init_hammer(15);
        setup();
}

