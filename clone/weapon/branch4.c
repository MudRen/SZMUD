// Code of ShenZhou
// branch2.c
// Jay 7/4/96

#include <weapon.h>
inherit STICK;

void create()
{
    set_name("����֦", ({"shuzhi", "zhi", "branch"}));
    set_weight(500+random(500)); 
    if( clonep() )
      set_default_object(__FILE__);
    else {
      set("long", "����һ������֦��\n");
	set("unit","��");
//***** ADDED BY SCATTER *****
				set("wposition", "/clone/weapon/branch4.c");
//***** END OF ADDING *****
	set("wield_msg","$N�γ�һ������֦�������С�\n");
	set("material", "wood");
    }
    init_stick(random(2)+1);

    setup();
}
