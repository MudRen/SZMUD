// Code of ShenZhou
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("ץ��", ({"zhua fan", "fan"}));
	set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���������ץ�����Ǵ��ס����⡢���ܲ��Ȼ���������ƣ��Ե�ʱ��Ҫ��������ץʳ��\n");
		set("unit", "��");
		set("value", 100);
		set("eat_msg", "$N����������ץ��һ��ץ���������\n");
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
