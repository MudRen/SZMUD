// huanrou.c ���
// jiuer 2001/11

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("���", ({"huan rou", "rou"}));
	set_weight(400);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��ʵ����͵�Ұ��⣬�����������������ˡ�\n");
		set("unit", "��");
		set("value", 80);
		set("food_remaining", 5);
		set("food_supply", 80);
//		set("food_race","Ұ��");
	}
}
