// Code of ShenZhou
// junfu.c

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("����", ({ "junfu", "cloth" }));
        set_color("$HIC$");
	set("long", "����һ���е�ɵĹٱ�����\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "��");
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/junfu.c");
//***** END OF ADDING *****
		set("value", 500);
		set("armor_prop/armor", 10);
	}
	setup();
}
