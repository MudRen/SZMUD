// Code of ShenZhou
// yayi_cloth.c
#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name(CYN"���۷�"NOR, ({ "yayi cloth", "cloth" }));
	set("long", "����һ��ո�µİ��޲����۷���\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
		set("value", 200);
		set("armor_prop/armor", 4);
	}
	setup();
}
