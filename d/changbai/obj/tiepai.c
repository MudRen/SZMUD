// Code of ShenZhou
// /d/changbai/obj/tiepai.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(RED"����"NOR, ({ "tiepai", "dao", "blade" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1000);
                set("material", "steel");
                set("long", "����һ�����ƣ���״�����á�");
                set("wield_msg", "$N���һ֧$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ػ��\n");
        }
        init_blade(25);
        setup();
}

