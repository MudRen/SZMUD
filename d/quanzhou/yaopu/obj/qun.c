// Code of ShenZhou
// qingbu-qun.c
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(GRN"�಼ȹ"NOR, ({ "qingbu qun", "cloth", "qun" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ�����ص��಼��ȹ��\n");
		set("unit", "��");
		set("value", 50);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

