// /clone/unique/blackjian.c
// 黑剑
// by jiuer 09/01/2001

#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit SWORD;

//#include "/clone/unique/special_weapon.h"
void create()
{
	set_name(HIB"黑剑"NOR, ({ "black jian", "heijian", "jian" }) );
	set_weight(3000);
		if( clonep() )
			 set_default_object(__FILE__);
		else {
		set("unit", "柄");
		set("long", "一柄又细又长的黑剑，剑柔刃软，却锋锐异常。\n");
		set("value", 10000);
		set("material", "steel");
		set("rigidity", 2000);
		set("wield_msg",
			HIB"只见蓝光一闪，$N的手中一柄"+"$n"+HIB"，轻轻颤动，剑刃口发出蓝光，这把黑剑竟是锋锐无比的利刃。!\n"NOR);
		set("unwield_msg", HIB"$N将手中的$n插入腰间的剑鞘。\n"NOR);
		set("unequip_msg", HIB"$N将手中的$n插入腰间的剑鞘。\n"NOR);
		}

	init_sword(100);
	setup();
	::create();
}


