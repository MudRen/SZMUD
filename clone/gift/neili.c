// lingzhi.c ǧ��ѩ��
//����(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIR"����ѩ��"NOR, ({"xu lian", "lian"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������ʿ�������������ѩ������˵��һ�ÿɵ�50��������\n");
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	this_player()->add("max_neili", 50);
	this_player()->add("eff_neili", 50);
	message_vision("$N����һ������ѩ����ֻ�����Լ���������������һЩ !\n", this_player());
	destruct(this_object());
	return 1;
}

