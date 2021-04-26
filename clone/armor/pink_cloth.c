// Code of ShenZhou
// pink_cloth.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("粉红绸衫", ({ "pink cloth", "cloth" }) );
        set_color("$MAG$");
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这件粉红色的绸衫上面绣着几只黄鹊，闻起来还有一股淡香。\n");
		set("unit", "件");
		set("value", 300);
		set("material", "cloth");
		set("armor_prop/armor", 1);
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/pink_cloth.c");
//***** END OF ADDING *****
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

