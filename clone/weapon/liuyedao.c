// Code of ShenZhou
// jiedao.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;
void create()
{
	set_name(GRN"��Ҷ��"NOR, ({ "liuyedao", "dao", "blade" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 250);
		set("material", "iron");
		set("long", "����һ�ѳ߰볤�ĸֵ���������Ҷ��������Ʈ������Ů�ӳ��ñ�����\n");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unequip_msg", "$N�����е�$n�������䡣\n");
	}
	init_blade(25);
	setup();
}
