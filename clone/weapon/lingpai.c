// Code of ShenZhou
// lingpai.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(RED"����"NOR, ({ "lingpai", "dao", "blade" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
		set("value", 40);
		set("material", "wood");
		set("long", "����һ֧ľ���ƣ�����������д��һ����ɱ���֡�\n");
		set("wield_msg", "$N���һ֧$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ػ��\n");
	}
	init_blade(4);
	setup();
}
