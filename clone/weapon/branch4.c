// Code of ShenZhou
// branch2.c
// Jay 7/4/96

#include <weapon.h>
inherit STICK;

void create()
{
    set_name("长树枝", ({"shuzhi", "zhi", "branch"}));
    set_weight(500+random(500)); 
    if( clonep() )
      set_default_object(__FILE__);
    else {
      set("long", "这是一根长树枝。\n");
	set("unit","根");
//***** ADDED BY SCATTER *****
				set("wposition", "/clone/weapon/branch4.c");
//***** END OF ADDING *****
	set("wield_msg","$N拔出一根长树枝握在手中。\n");
	set("material", "wood");
    }
    init_stick(random(2)+1);

    setup();
}
