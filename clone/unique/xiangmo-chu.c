// Code of ShenZhou
// weapon: xiangmo-chu.c
// Summer. 10/7/96

#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit STAFF;

void create()
{
        set_name(HIY"��ħ��"NOR, ({ "xiangmo chu", "xiangmo","chu" }));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", HIY"���ƶ�������״������Լ���ߣ�Ѽ����ϸ���ƶμ�����������������ｵ����ħ�ķ�����\n"NOR);
                set("value", 7000000);
                set("material", "steel");
		set("rigidity", 4000);
                set("wield_msg", HIY"һ�����������ǰһ����$N�ٳ�һ����ħ�ƣ��ٹ�ͷ������ã���ա�\n"NOR);
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_staff(120);
        setup();
	::create();
}


