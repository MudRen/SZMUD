// Code of ShenZhou
// kaoya.c ��Ѽ

#include <ansi.h>
inherit ITEM;

void init();
int do_cut(string);

void create()
{
        set_name(HIW"С����"NOR, ({"baobao"}));
	set_weight(200);
        set("no_get",1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һֻ�ʵ����͵ı�����Ѽ��\n");
		set("unit", "ֻ");
		set("value", 120);
	}

	setup();
}

void init()
{
        add_action("do_cut", "cut");
        add_action("do_ff", "sj");
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

