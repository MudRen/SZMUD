// Code of ShenZhou
// yazhang.c Ѽ��

inherit ITEM;
inherit F_FOOD;

void init();

void create()
{
	set_name("Ѽ��", ({"ya zhang", "yazhang"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һֻ��Ѽ��Ѽ�ơ�\n");
		set("unit", "ֻ");
		set("value", 30);
		set("food_remaining", 1);
		set("food_supply", 60);
	}

	setup();
}

