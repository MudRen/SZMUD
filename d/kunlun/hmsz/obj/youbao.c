// kunlun
#include <ansi.h>;
inherit ITEM;

void create()
{
	set_name("�Ͳ���", ({ "bag", "bao" }));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���Ͳ�������\n");
		set("value", 500);
		set("material", "cloth");
	}
	set("book_count", 1);
}

void init()
{
	if( this_player() == environment() )
	{
		add_action("do_open", "open");
		add_action("do_open", "unpack");
		add_action("do_open", "dakai");
	}
}

int do_open(string arg)
{
	object me, book;
	object where;

	if ( !arg )
	{
		return notify_fail("ʲô��\n");
	}
	if ( query("book_count") < 1)
	{
		return notify_fail("�Ͳ�������ʲôҲû���ˡ�\n");
	}

	me = this_player();
	if ( arg == "bag")
	{
		where = environment(me);
  message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ���˵�����澭�䵽"+this_player()->query("name")+"��������\n"NOR, users());
		message_vision(
"$N����ذ��Ͳ�������ʱ������ԭ�����ı������ľ��飬ֻ���Ͳ����ý��ܣ���
���ڲ���Գ��֮�У���ҳ��Ȼ�������\n", me);
                  book = new("/d/kunlun/hmsz/obj/jiuyang1");
		book->move(file_name(where));
                  book = new("/d/kunlun/hmsz/obj/jiuyang2");
		book->move(file_name(where));
                   book = new("/d/kunlun/hmsz/obj/jiuyang3");
		book->move(file_name(where));
                   book = new("/d/kunlun/hmsz/obj/jiuyang4");
		book->move(file_name(where));
		add("book_count",-1);
	}
	return 1;
}