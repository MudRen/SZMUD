// Code of ShenZhou
// renshen-guo.c �˲ι�

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(GRN "�˲ι�" NOR, ({"renshen guo", "guo"}));
	set_weight(90);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "ö");
		set("long", "����һö�˲ι�������ȥ����һ���װ����ֵ�С���ޡ�\n");
		set("value", 2);
		set("medicine", 1);
	}

	setup();
}

int cure_ob(object me)
{
	me->delete("yijin_wan");
        
	message_vision(GRN "$N����ææ�ذ��˲ι�������һ�ӣ���ζ����û�������������ġ����ˡ�һ��������ȥ\n" NOR, me);
	destruct(this_object());
	return 1;
}
