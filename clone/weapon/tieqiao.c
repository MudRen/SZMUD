// Code of ShenZhou
// weapon: /d/xingxiu/npc/obj/yaochu.c
// Jay 3/18/96

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("����", ({ "tie qiao", "qiao" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ѿ�ɽ��ʯ�õ����£��Ѿ���Щ�����ˡ�\n");
                set("value", 150);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_hammer(10);
        setup();
}

