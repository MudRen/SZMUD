// Code of ShenZhou
// guazi.c
// xbc: 11/18/96

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(RED"���ƹ���"NOR, ({ "duijin guazi", "guazi", "gua"}) );
	set_weight(850);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ��������ϸ�Ĵ��̶ж��ƹ��ӡ�\n");
		set("unit", "��");
		set("value", 350);
		set("material", "cloth");
		set("armor_prop/armor", 4);
		set("armor_prop/personality", 3);
	}
	setup();
}

