// Code of ShenZhou
// huyao.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name( HIC "ͷ��" NOR, ({ "tou kui", "kui" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", "����һ������ͷ�������Ա���ͷ����\n");
		set("value", 500);
		set("material", "iron");
		set("armor_prop/armor", 10);
		set("shaolin",1);
	}
	setup();
}
