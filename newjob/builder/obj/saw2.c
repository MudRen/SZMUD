// Ŀ¼: ľ��/ľ��
// saw2.c �־�

#include <weapon.h>
inherit AXE;

void create()
{
	set_name("�־�", ({ "saw","ju zi", "ju" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���־⣬����������ľͷ�ġ�\n");
		set("value", 1000);
		set("material", "steel");
		set("no_drop",1);
	}
	init_axe(10);
	setup();
}
