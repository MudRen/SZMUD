// Code of ShenZhou
// gb_beef.c ţ����

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ţ����", ({"niurou tiao", "tiao", "beef"}));
	set_weight(40);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����ţ������ÿ��ţ�ⶼ��������С��ƴ�ɣ�����Ũ����\n");
		set("unit", "��");
		set("value", 50);
		set("food_remaining", 1);
		set("food_supply", 20);
	}
}
