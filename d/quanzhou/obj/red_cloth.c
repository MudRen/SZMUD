// Code of ShenZhou
// pink_cloth.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("��籰�", ({ "red cloth", "cloth" }) );
        set_color("$HIR$");
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�����ɫ��籰��幤����������������һ�ɵ��㡣\n");
		set("unit", "��");
		set("value", 500);
		set("material", "cloth");
		set("armor_prop/armor", 8);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

