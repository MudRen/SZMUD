// Code of ShenZhou

#include <weapon.h>
inherit WHIP;

void create()
{
	set_name("���", ({ "ma bian", "bian" }));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���ϳ������õ���ޡ�\n");
		set("value", 100);
		set("material", "leather");
		set("rigidity", 100);
		set("wield_msg", "$N��ৡ���һ������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
	init_whip(10);
	setup();
}
