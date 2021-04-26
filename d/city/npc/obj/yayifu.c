// Code of ShenZhou
// yayi_cloth.c
#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name(CYN"衙役服"NOR, ({ "yayi cloth", "cloth" }));
	set("long", "这是一件崭新的白棉布衙役服。\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "件");
		set("value", 200);
		set("armor_prop/armor", 4);
	}
	setup();
}
