// by Jiuer
// guzhen.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name(HIW"����"NOR,({ "tie zheng", "zheng" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 5000);
		set("material", "steel");
        set("shape", "zither");
		set("long", "����һ�������������ϸ�ƶ��ɡ�\n");
		set("wield_msg", "$N����һ��$n���������С�\n");
		set("unequip_msg", "$N�������е�$n��\n");
	}
	init_staff(7);
	setup();
}
