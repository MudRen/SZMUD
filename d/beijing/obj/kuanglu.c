//Cracked by Roath
// kuanglu.c ����®ͼ�᡹

inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_look", "look");
}

void create()
{
	set_name("����®ͼ�᡹", ({"picture", "hua"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", 
"���Ǻ�������������®ɽȫ��ͼ�����ư��磬Ϊ���о�Ʒ��\n");
		set("value", 10000);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("��Ҫ��ʲô��\n");

	this_player()->add("neili", 200);
	message_vision("$N����һ�Ź�Ԫ����ֻ������֫�ٺ�������ӯ�ޱ� !\n", this_player());
	destruct(this_object());
	return 1;
}


