// Code of ShenZhou
// shoutao.c

#include <ansi.h>
#include <armor.h>

inherit HANDS;

void create()
{
	set_name( YEL"Ƥ����"NOR, ({ "pi shoutao", "shoutao" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "˫");
                set("long", "����һ˫Ƥ���ף�������Ӳ����յĺۼ���\n");
		set("value", 150);
		set("material", "leather");
//***** ADDED BY SCATTER *****
                                set("wposition", "/clone/armor/shoutao.c");
//***** END OF ADDING *****

		set("armor_prop/armor", 3);
		set("shaolin",1);
	}
	setup();
}
