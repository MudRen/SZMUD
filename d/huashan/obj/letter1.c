// Code of ShenZhou
// letter1.c �����

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("�����", ({"feng tao", "tao", "envelope"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
			"��Ƥ��д�Ű˸��֣������Һ��ߣ������˼���\n");
                set("material", "paper");
        }
}

void init()
{
	add_action("do_open", "open");
}

int do_open(string arg)
{
	object ob1, ob2, me=this_player();

	if ( !arg || arg =="" )
		return notify_fail("��Ҫ��ʲô�򿪣�\n");

        if ( (arg == "feng tao" || arg == "tao" || arg == "envelope" )
        && objectp(present(arg, me)) ) {
	   	if ( this_object()->query_temp("opened") )
			return notify_fail("���Ѿ����ŷ⣬�����ֽ������С�����ˣ�\n");

		message_vision("$N���ŷ⣬���һ�Ųоɵ���ֽ������С���ס�\n", me);
		this_object()->set_name("��ֽ", ({"letter"}));
		this_object()->set("unit", "��");
		this_object()->set("long", HIY
		"����֮�������Ե��Ω�ú��ߣ���������(bury)�Һ��ǣ�\n"
		"�������У�Ҫ��Ҫ����\n" NOR);
		this_object()->set_temp("opened", 1);
		me->set_temp("read1", 1);

		ob1=new(__DIR__"letter3");
		ob2=new(__DIR__"letter2");
		ob1->move(me);
		ob2->move(me);

		return 1;
	}
	else return 0;
}
