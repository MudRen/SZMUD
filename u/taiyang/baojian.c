// Code of Taiyang
// baojian.c

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
               set_name(HIY "太阳剑" NOR, ({ "taiyang jian", "jian", "sword", "baojian" })); 
        set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("material", "steel");
                set("value", 22000);
		set("unit", "柄");
                      set("long", HIY "这是太阳神用阳光锻造的神剑，剑刃上泛着金色的光茫。 \n"NOR); 
//***** ADDED BY SCATTER *****
                                      set("wposition", "/u/taiyang/baojian.c");
//***** END OF ADDING *****
                set("wield_msg", "$N「唰」的一声抽出一柄光芒四射的$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
	}
        init_sword(2000);
	setup();
}
