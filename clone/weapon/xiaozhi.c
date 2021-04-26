// Code of ShenZhou
// youlong.c

#include <ansi.h>
#include <weapon.h>

inherit SWORD;
#include "/clone/unique/special_weapon.h"
void create()
{
        set_name(HIR"����"NOR, ({ "huoshen sword", "huoshen", "sword" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
			"���ǰѿ���������ͨ�ĳ���������ϸһ�����������м���ϸ����˸������\n");
                set("value", 1000);
                set("material", "blacksteel");
		set("rigidity", 100);
                set("wield_msg", 
                        HIR"����һ��ҫ�۵ĺ�⣬��������һ�����͵Ļ��������������$N�����С�\n"NOR);
                set("unequip_msg", HIR"���һ�����������뽣�ʡ�\n"NOR);
                set("unwield_msg", HIR"���һ�����������뽣�ʡ�\n"NOR);
        }

        init_sword(100);
        setup();
}
