// Code of ShenZhou
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("���ײ�", ({"chao baicai", "baicai"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������ĳ��ײˡ�\n");
		set("unit", "��");
		set("value", 50);
		set("food_remaining", 1);
		set("food_supply", 15);
	}
}
