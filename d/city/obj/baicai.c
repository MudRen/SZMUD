// Code of ShenZhou
// baicai �ײ�

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("�ײ�", ({"baicai", "vegetable"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�����ʵĴ�ײ��ġ�\n");
		set("unit", "��");
		set("value", 20);
		set("food_remaining", 2);
		set("food_supply", 20);
	}
}
