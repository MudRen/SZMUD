// Code of ShenZhou
// ham.c ����

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("����", ({"huo tui", "ham"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һֻ�����ַʵĻ��ȡ�\n");
		set("unit", "ֻ");
		set("value", 120);
		set("food_remaining", 4);
		set("food_supply", 60);
	}
}
