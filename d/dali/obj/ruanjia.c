// 金丝铠甲
// by snowyu 

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIY"金丝软甲"NOR, ({ "ruanjia", "armor" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是一件用生金丝与龙鳞相穿做成的护身软甲,相传是段氏远祖
入洱海斩妖龙所得龙鳞串以金丝而成胸前精秀的刺了二龙戏珠图。\n");
		set("material", "wood");
		set("value", 10);
		set("wear_msg", HIY "$N穿上一件金丝软甲,身上隐有宝光流动,举手投足间一派帝王之势!\n" NOR);
		set("unequip_msg", HIY "$N将金丝软甲从身上脱了下来。\n" NOR);
		set("armor_prop/armor", 90);
		set("ruanjia", 1);
	}
	setup();
}

