// Code of ShenZhou
// mianbing.c ���

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("���", ({"mian bing", "bing"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��������Ŀ������\n");
		set("unit", "��");
		set("value", 60);
		set("food_remaining", 3);
		set("food_supply", 40);
	}
}
