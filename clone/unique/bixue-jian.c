//Alan.F
// bixue-jian.c

#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit SWORD;
#include "/clone/unique/special_weapon.h"
void create()
{
	set_name(HIR"碧血剑"NOR, ({ "bixue jian", "sword", "jian" }) );
	set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "柄");
                set("long", 
                "剑长四尺三寸，剑身上刻着以被鲜血染红四个大字:「精忠报国」。\n"
                "剑身上一道道血痕，像是鲜血在流动，发出碧油油的暗光。这正是\n"
                "碧血剑，上面有袁崇焕将军的血，英雄的血、忠臣的血，三年化碧，\n"
                "好似鲜血还在在流动。\n");
		set("value", 10000);
		set("material", "steel");
		set("rigidity", 2000);
                set("wield_msg",
			HIR"只见血光一闪，鲜血顺着$N的手流到"+NOR+""+HIC+"碧血剑"+NOR+"，"+RED+"一条条血痕围绕着"+HIR+"碧血剑"+RED+"流动着 !\n"NOR);
                set("unwield_msg", HIW"$N将手中的"+HIC+"碧血剑"+HIW+"插入背上的剑鞘。\n"NOR);
                set("unequip_msg", HIW"$N将手中的"+HIC+"碧血剑"+HIW+"插入背上的剑鞘。\n"NOR);
        }

	init_sword(100);
        setup();
	::create();
}


