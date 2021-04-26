// Code of ShenZhou
// gua.c
// xbc: 11/18/96

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(CYN"ʯ�������"NOR, ({ "shiqing gua", "yinshu gua", "gua"}) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ��������ϸ��ʯ������ӡ�\n");
		set("unit", "��");
		set("value", 300);
		set("material", "cloth");
		set("armor_prop/armor", 3);
		set("armor_prop/personality", 3);
	}
	setup();
}

