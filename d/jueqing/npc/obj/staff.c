//Filename:  /d/jueqing/obj/gangzhang.c 龙头钢杖
//jiuer--08/15/2001

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("龙头钢杖", ({ "longtou-gangzhang", "gangzhang", "staff" }));
	set_weight(30000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根长约一丈一尺的龙头钢杖，一条青龙盘卧杖头。\n");
		set("value", 2500);
		set("material", "steel");
		set("rigidity", 1200);

		set("wield_msg", "只见眼前青光一闪，$N抽出一根$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n往后背收起。\n");
	}
  	init_staff(35);
	setup();
}