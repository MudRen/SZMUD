// Code of ShenZhou
// junfu.c
#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name(HIC"����"NOR, ({ "junfu", "cloth" }));
	set("long", "����һ���е�ɵĹٱ�����\n");
//***** ADDED BY SCATTER *****
                                set("wposition", "/d/city/npc/obj/junfu.c");
//***** END OF ADDING *****
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
		set("value", 500);
		set("armor_prop/armor", 10);
	}
	setup();
}
