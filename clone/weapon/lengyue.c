
//lengyuedao by chchong
//lengyuedao.c ���µ�
//chchong 2001/08/26

#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
        set_name(WHT"���µ�"NOR, ({ "lengyue dao", "dao"}));
        set_weight(8000);
        if (clonep())
        set_default_object(__FILE__);
        else 
        {       set("unit", "��");
                set("long", WHT"һ�ѿ�����ͨ�ĳ����������Ϸ��𵭵��İ�ɫ��\n" NOR);
                set("value", 1000);
                set("material", "steel");
                set("wield_msg", "$N��ৡ���һ�����죬���ж���һ��$n��\n" NOR);
                set("unwield_msg", "$N�����е�$n������䵶�ʡ�\n");
        }
init_blade(70+random(11));
        setup(); ::create();
}
