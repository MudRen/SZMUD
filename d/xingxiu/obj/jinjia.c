// Code of ShenZhou
// jinjia.c �ƽ����
//
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_UNIQUE;

void create()
{
	set_name(HIY"�ƽ����"NOR, ({ "golden armor", "armor" }) );
	set_weight(26000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ���ƽ���ף������ʮ�־��£��ؼ��Ͽ���һͷ�����������ա�\n����Ź��У�ֻ�й��������Է��������ռǡ�\n");
		set("unit", "��");
		set("material", "gold");
		set("value", 50000);
		set("armor_prop/armor", 150);
	}
	setup();
	::create();
}

