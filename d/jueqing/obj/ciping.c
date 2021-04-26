
// ciping.c ���ƿ 
// jiuer -- 08/15/2001

#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIW"���ƿ"NOR, ({"ci ping", "ping", "ciping", "bottle"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һֻ����ʢˮ�Ĵ��ƿ������ʢ��һ��ƿˮ��\n");
		set("unit", "ֻ");
		set_weight(900);
		set("value", 200);
		set("max_liquid", 30);
	}

	// because a container can contain different liquid
	// we set it to contain water at the beginning
	set("liquid", ([
		"type": "water",
		"name": "��ˮ",
		"remaining": 15,
		"drunk_supply": 10,
	]));
}
