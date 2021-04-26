// Code of ShenZhou
// jadesword.c ��

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name(HIW"��"NOR, ({ "jade sword", "jian", "sword" }));
	set_weight(2500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ����ɫ�������ǰ�������ɣ��п�ĥ�ú��Ƿ��񣬺͸��������������¡�\n");
		set("value", 10000);
		set("material", "jade");
		set("rigidity", -10);
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(25);
	setup();
}
