//Lnere;
// qixiu-jian.c;

#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit SWORD;
#include "/clone/unique/special_weapon.h"
void create()
{
        set_name(HIB"七修剑"NOR, ({ "qixiu jian", "sword", "jian" }) );
	set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "柄");
                set("long", 
            "此剑为七修门镇山之宝。属上古降魔利器，由千年铁陨打造成成。\n"
            "传说此剑出鞘能幻出道道金白之光，光到之处，所向披靡。\n" );
		set("value", 10000);
		set("material", "steel");
		set("rigidity", 2000);
                set("wield_msg",
  HIY"只见金光道道，耀人眼目，$N手中多了一把上古利器"+NOR+""+HIB+"七修剑"+NOR+"，"+HIW+"一条条白色光棱透剑而出　"+NOR+"令人不敢正视 !\n"NOR);
            set("unwield_msg", HIW"$N将手中的"+HIB+"七修剑"+HIY+"插入背上的剑鞘。\n"NOR);
          set("unequip_msg", HIW"$N将手中的"+HIB+"七修剑"+HIY+"插入背上的剑鞘。\n"NOR);
        }

	init_sword(100);
        setup();
	::create();
}


