// Code of ShenZhou
// dianxin.c ����
// Shan 96/06/29

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("����", ({"dian xin", "dianxin", "dimsum"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������������С���ġ�\n");
		set("unit", "��");
		set("value", 100);
		set("food_remaining", 4);
		set("food_supply", 30);
	}
}
