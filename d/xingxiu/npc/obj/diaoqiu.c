// Code of ShenZhou

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	set_name( MAG "����" NOR, ({ "diao qiu", "qiu" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ����ë��ƤΧ����\n");
		set("value", 500);
		set("material", "leather");
		set("armor_prop/armor", 5);
		set("shaolin",1);
	}
	setup();
}
