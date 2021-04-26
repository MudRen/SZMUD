// Code of ShenZhou
// kaoya.c ��Ѽ

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void init();
int do_cut(string);

void create()
{
	set_name(MAG"��Ѽ"NOR, ({"kaoya", "ya"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һֻ�ʵ����͵ı�����Ѽ��\n");
		set("unit", "ֻ");
		set("value", 120);
		set("food_remaining", 3);
		set("food_supply", 80);
	}

	setup();
}

void init()
{
        add_action("do_cut", "cut");
}

int do_cut(string arg)
{
        object ob1 = this_object(), me = this_player();

	if ( !arg || arg == "") return 0;

	if ( arg == "��Ѽ" || arg == "kaoya" ) {
        	object ob2 = new("/clone/food/yazhang");
		message_vision("$N�ѿ�Ѽ��Ѽ������������\n", me);
		ob2->move(me);
		destruct(ob1);
		return 1;
	}
	return 0;
}

