//  /d/jueqing/obj/donggu.c ����
//  jiuer -- 08/15/2001

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("���Բ���", ({"donggu caixin", "dong gu", "donggu", "caixin", "cai xin"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ��ڰ����ġ�Ʈ�ŵ��������Ķ��Բ��ġ�\n");
		set("unit", "��");
		set("value", 150);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
