// pihuwan.c

#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create()
{
	set_name( "ţƤ����", ({ "hu wan", "huwan" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
                set("long", "����һ��Ƥ�ʵĻ������Ա����󲿡�\n");
		set("value", 250);
		set("material", "skin");
		set("armor_prop/armor", 5);
		set("jueqing",1);
	}
	setup();
}
