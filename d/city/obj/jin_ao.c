// Code of ShenZhou
// jin_ao.c
// xbc: 11/18/96

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(YEL"խ�̰�"NOR, ({ "ken ao", "ao" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "����һ����ٵ��������Ƽ��խ�̣��幤����������������һ�ɵ��㡣\n");
                set("unit", "��");
                set("value", 400);
                set("material", "cloth");
                set("armor_prop/armor", 5);
                set("armor_prop/personality", 3);
                set("female_only", 1);
	}
	setup();
}

