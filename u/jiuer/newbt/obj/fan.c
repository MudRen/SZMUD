// by jiuer
// ouyang ke fan.c 折扇
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(HIC"折扇"NOR, ({"fan","zheshan", "shan"}) );

    set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
        set("long","一柄折扇，扇骨是钢铸的。\n");
		set("rigidity", 1000000);
		set_weight(1000);
		set("value", 20);
		set("ding", 10);
		set("material", "blacksteel");

		set("wield_msg",HIM"$N从袖中掏出一柄折扇，一挥，张了开来，露出扇上一朵娇艳欲滴的牡丹。\n"NOR);
		set("unwield_msg", "啪的一声，$N把折扇合了起来，收进袖中。\n");

		init_stick(30);
		set("actions", (: call_other, __FILE__, "query_action" :) );
		setup();
	}
}
