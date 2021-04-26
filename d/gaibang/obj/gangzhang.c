// Code of ShenZhou
// gangzhang.c 钢杖

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("钢杖", ({ "gangzhang" ,"zhang", "staff"}));
	set_weight(28000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根粗重的钢杖，掂在手上沉甸甸的。\n");
		set("value", 250);
		set("material", "steel");
//***** ADDED BY SCATTER *****
		set("wposition", "/clone/weapon/gangzhang.c");
//***** END OF ADDING *****
		set("wield_msg", "$N抽出一根$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插回腰间。\n");
	}
  	init_staff(25);
	setup();
}

