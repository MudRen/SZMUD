// Code of ShenZhou
#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( CYN "Ƥѥ" NOR , ({ "pi xue", "xue" }) );
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("long", "һ˫���������񳣴�����ѥ��");
		set("value", 300);
		set("material", "boots");
		set("armor_prop/armor", 6);
	}
	setup();
}
