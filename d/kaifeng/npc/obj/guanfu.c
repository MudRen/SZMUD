// Code of ShenZhou
// guanfu.c
#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
        set_name(HIC"官服"NOR, ({ "guanfu", "cloth", "guan fu" }));
        set("long", "这是一件当朝大臣穿的官服，上边还有花翎。\n");
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "cloth");
		set("unit", "件");
                set("value", 800);
                set("armor_prop/armor", 20);
	}
	setup();
}
