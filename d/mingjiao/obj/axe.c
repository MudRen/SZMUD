// Code of ShenZhou
// axe.c ��ͷ

#include <weapon.h>
inherit AXE;

void create()
{
	set_name("��ͷ", ({ "axe","fu" }));
	set_weight(9000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Ѹ�ͷ����������������\n");
		set("value", 1000);
		set("material", "steel");
		set("no_drop",1);
	}
	init_axe(10);
	setup();
}

