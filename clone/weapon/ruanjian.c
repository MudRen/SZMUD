// Code of ShenZhou
// longsword.c ����

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIW"��"NOR, ({ "ruanjian", "jian" }));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ����ͨ�������������ᣬ��Χ�����䡣\n");
		set("value", 250);
		set("material", "steel");
		set("rigidity", 300);
		set("wield_msg", "$N��ৡ���һ��չ��һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n�ƻ����䡣\n");
	}
	init_sword(10);
	setup();
}
