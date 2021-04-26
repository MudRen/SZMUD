// Code of ShenZhou
// tengjia.c �ټ�
//
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(YEL"�ټ�"NOR, ({ "tengjia", "armor" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���ô���ĳ��ɽ���ز���������֯�ɵ��ټף������ֽ�ʵ���ǻ����Ʒ��\n");
		set("material", "wood");
		set("value", 10);
		set("armor_prop/armor", 75);
	}
	setup();
}

int is_special() { return 1;}

mixed hit_by(object me, object victim, int damage, object weapon)
{
	if (weapon)	return damage*2/3;
	return damage*3/4;
}
