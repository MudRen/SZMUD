// lingzhi.c ǧ����֥
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
	set_name(HIR"������֥"NOR, ({"ling zhi", "zhi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��������ʿ���������������֥����˵��һ�ÿɵ�3000���飬1000Ǳ�ܡ�\n");
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
      object me=this_player();
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	this_player()->add("combat_exp", 3000);
	this_player()->add("potential",1000);
        this_player()->set("eff_jing", (int)me->query("max_jing"));
        this_player()->set("jing", (int)me->query("max_jing"));
        this_player()->set("eff_qi", (int)me->query("max_qi"));
        this_player()->set("jingli", (int)me->query("max_jingli"));
        this_player()->set("qi", (int)me->query("max_qi"));
        this_player()->set("neili", (int)me->query("max_neili"));
	message_vision("$N����һ��������֥���е������泩!\n", this_player());
	this_player()->add("story/lingzhi",1);
	destruct(this_object());
	return 1;
}

