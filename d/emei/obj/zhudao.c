// Code of ShenZhou
// zhudao.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(GRN"��"NOR,({ "zhu dao", "dao", "blade" }) );
	set_weight(1500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 75);
		set("material", "bamboo");
		set("long", "����һ�������Ƴɵ�����̵������ҵ���ϰ����ô˵����������ˡ�\n");
		set("wield_msg", "$N���һ��$n���������С�\n");
		set("unequip_msg", "$N�����е�$n������䡣\n");
	}
	init_blade(10);
	setup();
}
