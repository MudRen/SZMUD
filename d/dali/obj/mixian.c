// Code of ShenZhou
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIW"��������"NOR, ({"guoqiao mixian", "rice noodle", "mixian"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ���������ڵ��ͽ����׷ۣ����Ǵ������˹������ߡ�\n");
		set("unit", "��");
		set("value", 80);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}



