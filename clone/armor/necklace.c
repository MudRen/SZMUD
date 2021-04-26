// Code of ShenZhou
// necklace.c ������

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	set_name("������", ({ "golden necklace", "necklace", "lace" }));
        set_color("$HIY$");
	set("weight", 500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1500);
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/necklace.c");
//***** END OF ADDING *****
		set("material", "gold");
		set("armor_prop/armor", 1);
	}
	setup();
}	
