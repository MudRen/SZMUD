// guzheng.c 古筝

#include <weapon.h>
#include <ansi.h>
inherit STAFF;

void create()
{
	set_name(HIG"古筝"NOR, ({ "gu zheng", "zheng", "qin" }));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long",
			HIG"这是一张做工十分考究的古筝，古香古色，音质极好。\n"NOR);
		set("value", 5000);
                set("material", "wood");
                set("wield_msg", "$N捧起一张$n在手中。\n");
                set("unwield_msg", "$N将手中的$n放了下来。\n");
                set("shape", "zither");
      }
        init_staff(45);
        setup();
}

#include "/shenzhou/d/kunlun/obj/flute.h" 
