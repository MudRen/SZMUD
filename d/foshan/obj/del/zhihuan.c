// Code of ShenZhou
#include <armor.h>

inherit FINGER;

void create()
{
	set_name("ָ��", ({ "zhi huan", "huan", "ring" }));
	set("weight", 400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","һö��ָ����������һЩϸϸ�Ļ��ơ�\n");
		set("unit", "ö");
		set("value", 500);
		set("material", "gold");
		set("armor_prop/armor", 1);
	}
	setup();
}	
