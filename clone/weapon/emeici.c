// Code of ShenZhou
// Jay 7/11/96

#include <weapon.h>
inherit SWORD;

void create()
{
    set_name("峨眉刺", ({"emei ci", "ci", "sword"}));
    set_weight(1000); 
    if( clonep() )
      set_default_object(__FILE__);
    else {
      set("long", "这是一对峨眉刺，可做短剑使用。\n");
	set("unit","对");
//***** ADDED BY SCATTER *****
				set("wposition", "/clone/weapon/emeici.c");
//***** END OF ADDING *****

	set("value",100);
	set("material", "iron");
    }
    init_sword(10);

    setup();
}
