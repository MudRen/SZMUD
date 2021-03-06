// /d/gumu/obj/junzi-jian.c 君子剑
// by April 01.08.04
// update flower 01.08.24

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit SWORD;

#include "/clone/unique/special_weapon.h"

void create()
{
	set_name(HIG"君子剑"NOR, ({ "junzi jian", "junzi", "jian" }) );
	set_weight(3000);
		if( clonep() )
			set_default_object(__FILE__);
        else {
			set("unit", "柄");
			set("long", "这柄剑既无尖头，又无剑锋，圆头钝边。剑身乌黑，没半点光泽，倒有些似一条薄薄的木鞭\n");
			set("value", 12000);
			set("material", "steel");
			set("rigidity", 2000);
			set("wield_msg",HIG"$N拔剑出鞘，君子豪情，剑气冲天，天地间顿时苍凉之意大盛！\n"NOR);
			set("unwield_msg", HIG"$N将手中的$n插入腰间的剑鞘。\n"NOR);
			set("unequip_msg", HIG"$N将手中的$n插入腰间的剑鞘。\n"NOR);
		}

        init_sword(120);
        setup();
        ::create();

}
