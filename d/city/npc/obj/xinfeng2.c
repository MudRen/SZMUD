// Code of ShenZhou
// Write by Wzfeng 12-29
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"����"NOR, ({"jin tao"}));
	set_weight(1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ����˿�����ɵ����ӣ���������װ�麯�����顣���ӵı���մ�������ë��\n");
		set("unit", "��");
		set("value", 1000);
		set("send_level",3);

	}
}
void init()
{
	add_action("do_feng", "feng");	
}

int do_feng(string arg)
{
	object ob_letter,me;
	me=this_player();
	if(!arg) return notify_fail("��Ҫ��ʲôװ�������\n");
	
	ob_letter = present(arg, me);
	if(!ob_letter)
		return notify_fail("�����Ϻ���û�з��麯��\n");
	if(!ob_letter->query("can_feng"))
		return notify_fail("�Բ����㲻�ܽ�����Ž������\n");
		message_vision("$N�������ͳ�һ��д�õ��麯װ�ڲ����\n",me);
	ob_letter->set("long", "����һ���Ѿ���õĲ��ף�����װ���麯�����ӵı���մ�������ë��\n");
	
	ob_letter->set_name(HIR"�ź�"NOR, ({"xin han","letter"}));
	ob_letter->set("can_feng",0);
	ob_letter->set("can_send",1);
	ob_letter->set("letter/send_level",3);
	destruct(this_object());
	return 1;
}
