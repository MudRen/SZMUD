// Code of ShenZhou
// huwan.c

#include <ansi.h>
#include <armor.h>

inherit WRISTS;

void create()
{
	set_name( WHT"������"NOR, ({ "hu wan", "huwan" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
                set("long", "����һ��Ƥ�ʵĻ��������������������Ա����󲿡�\n");
		set("value", 500);
		set("material", "iron");
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/huwan.c");
//***** END OF ADDING *****
		set("armor_prop/armor", 5);
		set("shaolin",1);
	}
	setup();
}
