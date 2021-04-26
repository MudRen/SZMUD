// Code of ShenZhou
// letter2.c С����

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("С����", ({"feng tao", "tao", "envelope"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
			"��Ƥ��д�ţ�������֮������\n");
                set("material", "paper");
        }
}

void init()
{
	add_action("do_open", "open");
}

int do_open(string arg)
{
	object me=this_player();

	if ( !arg || arg =="" )
		return notify_fail("��Ҫ��ʲô�򿪣�\n");

        if ( (arg == "feng tao" || arg == "tao" || arg == "envelope" )
        && objectp(present(arg, me)) ) {	
		if ( this_object()->query_temp("opened") )
			return notify_fail("���Ѿ����ŷ⣬�����ֽ�ˣ�\n");

		message_vision("$N���ŷ⣬���һ�Ųоɵ���ֽ��\n", me);
		this_object()->set_name("��ֽ", ({"letter"}));
		this_object()->set("unit", "��");
		this_object()->set("long", HIG
		"�������ң����л�����˫����������(pull)�����м�����\n" NOR);

		this_object()->set_temp("opened", 1);
		me->set_temp("read2", 1);

		return 1;
	}
	else return 0;
}
