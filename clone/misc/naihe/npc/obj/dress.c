// 赌场人员定做的衣服。 dress.c
// by naihe 2002-05-01

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("长裙", ({"dress"}) );
	set_color("$HIC$");
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一条天青色的露背长裙。\n");
		set("unit", "条");
		set("value", 10000);
		set("material", "silk");
		set("armor_prop/armor", 1);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}
