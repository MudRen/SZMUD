// Code of ShenZhou
// branch1.c
// Jay 7/4/96
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
    set_name("С��֦", ({"shuzhi", "zhi", "branch"}));
    set_weight(100+random(100)); 
    if( clonep() )
      set_default_object(__FILE__);
    else {
      set("long", "����һ��С��֦��\n");
	set("unit","��");
	set("wield_msg","$N���һ��С��֦�������С�\n");
	set("material", "wood");
    }
    init_sword(random(2));

    setup();
}
