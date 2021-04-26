// Code of ShenZhou
// pishui-zhu.c ��ˮ����

inherit ITEM;

void init()
{
	add_action("do_eat", "eat");
	add_action("do_han", "han");
}

void create()
{
	set_name("��ˮ����", ({"pishui zhu", "zhu"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ���ɱ�ˮ�����޽��Ƴɵı�ˮ���飬��������ߺ������֣��鲨���ס�\n");
		set("value", 1000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");

	message_vision("\n$N����һ�����ѱ�ˮ�����¶���ƺ�ʲôζ��Ҳû���� ... \n", this_player());
	this_player()->set_temp("zhu_eat", 1);

	destruct(this_object());
	return 1;
}

int do_han(string arg)
{
	if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");

	message_vision("\n$NС������������ˮ���飬�������\n", this_player());
	this_player()->set_temp("zhu_han", 1);

	return 1;
}
