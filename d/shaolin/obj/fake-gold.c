// Code of ShenZhou
// fake-gold.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"�ƽ�"NOR, ({"gold", "ingot", "gold_money"}));
	set_weight(150000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "�ƳγεĽ��ӣ��˼��˰��Ľ��ӣ����� ...��ɫ�е㲻�ԡ�\n");
		set("unit", "��");
		set("material", "lead");
	}
	setup();
}

