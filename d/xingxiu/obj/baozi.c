// Code of ShenZhou
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("��Ƥ����", ({"baozi"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "��Ƥ����Ƥ����ֽ��ɫ���������ڰ������ڣ���ζ������\n");
		set("unit", "��");
		set("value", 30);
		set("food_remaining", 3);
		set("food_supply", 30);
	}
}
