// Code of ShenZhou

#include <ansi.h>

inherit ITEM;

int cure_ob(string);
void init();

void create()
{
	set_name(HIW "�Ҹ�ɢ" NOR, ({"xingfu san", "san"}));
	set_weight(20);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 50);
		set("medicine", 1);
                set("no_sell", 1);
		set("no_get", 1);
		set("no_steal", 1);
		set("no_drop", 1);
		set("no_sell", 1);
	}

	setup();
}

int cure_ob(object me)
{
	me->add("shenzhou/pts", 40); 
        message_vision(HIG "$N������һЩ�Ҹ�ɢ�����з�Թ���һ�ʹ���! \n" NOR, me); 

	destruct(this_object());
	return 1;
}
