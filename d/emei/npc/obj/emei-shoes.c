// Code of ShenZhou
// emei_shoes.c

#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("�಼Ů��", ({ "shoes"}) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
		set("long", 
"����һ˫�಼Ů�ġ�\n");
		set("material", "cloth");
                set("armor_type", "boots");
                set("armor_prop/armor", 1);
                set("female_only", 1);
	}

}
