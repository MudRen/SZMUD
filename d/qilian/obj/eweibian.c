// Code of ShenZhou

#include <weapon.h>
inherit WHIP;

void create()
{
	set_name("��β��", ({ "ewei bian", "bian" }));
	set_weight(8000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���������β�����ɵı��ӣ������ϵ�����һ�������롣\n");
		set("value", 200);
		set("material", "leather");
		set("wield_msg", "$N��ৡ���һ������һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n������䡣\n");
	}
	init_whip(150);
	setup();
}
