// jindao.c 金刀

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit BLADE;
#include "/clone/unique/special_weapon.h"
void create()
{
	set_name(YEL"金刀"NOR, ({ "jin dao", "jindao", "dao" }));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把背厚刃宽的锯齿刀，金光闪闪，似是黄金打造。\n");
		set("value", 10000);
		set("material", "gold");
		set("rigidity", 300);
		set("wield_msg", HIY "只听「铮」的一声，一道金光划过，$n已在$N的掌中。\n" NOR);
		set("unwield_msg", HIY "$n自$N掌中一转，在半空中划过一道金光，「唰」地跃入刀鞘。\n" NOR);
	}
	init_blade(120);
	setup();
	::create();
}


