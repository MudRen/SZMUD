
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
void create()
{
	set_name("逍遥剑", ({ "xiaoyao jian", "xiaoyao", "jian" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 50000);
		set("material", "steel");
		set("long", HIC"传说中神仙所有的仙物，以南海的五仙石炼成，似乎有非凡的用途。\n"NOR);
		set("wield_msg", HIY"$N缓缓地从腰边抽出一丙"+HIR"五"+HIG"彩"+HIC"缤"+HIM"纷"+HIY"的长剑，似乎是传说中的$n。\n"NOR);
		set("unequip_msg", HIB"唰的一声，$N将手中的$n收回。\n"NOR);
	}
	init_sword(500);
	setup();
}


