// Code of ShenZhou

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name(  "ɮЬ" , ({ "seng xie", "xie" }) );
        set_color("$CYN$");
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("long", "һ˫�಼ɮЬ��\n");
		set("value", 250);
		set("material", "cloth");
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/sengxie.c");
//***** END OF ADDING *****
		set("armor_prop/dodge", 5);
		set("shaolin",1);
	}
	setup();
}
