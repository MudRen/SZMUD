// Code of ShenZhou
// junfu.c

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name( CYN "����" NOR , ({ "junfu", "cloth" }));
	set("long", "����һ������ٱ��ı�׼������\n");
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
		set("value", 500);
		set("armor_prop/armor", 35);
	}
	setup();
}
