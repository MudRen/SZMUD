// purplequn.c
// jiuer: 05/23/2002

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(MAG"����ȹ"NOR, ({ "skirt", "qun"}) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ����ɫ��ȹ��ȹ������������ɫ�ȴ���\n");
		set("unit", "��");
		set("value", 250);
		set("material", "cloth");
		set("armor_prop/armor", 2);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

