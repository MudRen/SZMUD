// Code of ShenZhou
// ҹ�Ɑ
#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIW"ҹ�Ɑ"NOR, ({"yeguang bei", "bei", "cup"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�����񾫵�ϸ�����ɵ�ҹ�Ɑ��ɫ�ʰ�쵣��ż�����ҹ�Ɑ������֮��������ҹ�ա���\n");
		set("unit", "��");
		set("value", 50000);
		set("max_liquid", 4);
		set("worthless", 1);
		set("liquid", ([
			"type": "alcohol",
			"name": "���Ѿ�",
			"remaining": 4,
			"drunk_apply": 5,
		]));
	}
}
