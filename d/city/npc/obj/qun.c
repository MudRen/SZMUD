// Code of ShenZhou
// qun.c
// xbc: 11/18/96

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(WHT"��ɴ�������ȹ"NOR, ({ "xiangbian qun", "qun", "skirt"}) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ��������ϸ�İ�ɴ�������ȹ��\n");
		set("unit", "��");
		set("value", 250);
		set("material", "cloth");
		set("armor_prop/armor", 2);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

