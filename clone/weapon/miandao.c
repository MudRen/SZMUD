// Code of ShenZhou
// gangdao.c

#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name(HIW"�嵶"NOR, ({ "mian dao", "blade", "dao" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���ֳ��ֱ���������嵶��\n");
		set("value", 300);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
	}
	init_blade(25);
	setup();
}
