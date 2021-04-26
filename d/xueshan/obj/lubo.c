// Code of ShenZhou

inherit F_LIQUID;
#include <weapon.h>
#include <ansi.h>

inherit HAMMER;
void create()
{
	set_name( BLU "­��" NOR, ({"lubo"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����­���ƳɵĲ���\n");
		set("unit", "��");
		set("no_sell",1);
		set("value", 100);
		set("max_liquid", 10);
		set("regidity", 1000);
		set("wield_msg", "$N��������һ��$n���������\n");
                set("unequip_msg", "$N��$n���������һ����䡣\n");
	}

	// because a container can contain different liquid
	// we set it to contain water at the beginning
	set("liquid", ([
		"type": "water",
		"name": "��ˮ",
		"remaining": 10,
		"drunk_supply": 10,
	]));
	init_hammer(30);
}
