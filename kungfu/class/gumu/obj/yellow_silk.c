// yellow_silk ��ɴȹ
// by April 2001.09.29

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
	set_name("��ɴȹ", ({ "yellow skirt","skirt" }) );
	set_weight(800);

	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�������Ļ�ɴȹ��\n");
		set("material", "cloth");
		set("value", 0);
		set("armor_prop/armor", 8);
		set("armor_prop/personality", 5);
		set("female_only", 1);
	}

	setup();
}

