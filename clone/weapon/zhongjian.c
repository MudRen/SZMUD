// Code of ShenZhou
// gangjian.c

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("�ؽ�", ({ "zhongjian", "jian", "sword" }));
	set_weight(30000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�����صĽ������մֲڡ�\n");
		set("value", 30);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
	init_sword(3);
	setup();
}
