// Code of ShenZhou
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("������", ({"zheng doufu", "steamed tofu"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�����������е�������չ��ġ���ʮ��������ҹ����\n");
		set("unit", "��");
		set("value", 50);
		set("food_remaining", 1);
		set("food_supply", 15);
	}
}
