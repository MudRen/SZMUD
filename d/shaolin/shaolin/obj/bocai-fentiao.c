// Code of ShenZhou
// bocai-fentiao.c ���˷���

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("���˷���", ({"bocai fentiao", "fentiao"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ�������䣬����ɿڵĲ��˷�����\n");
		set("unit", "��");
		set("value", 80);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
