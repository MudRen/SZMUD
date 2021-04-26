// Code of ShenZhou
// Write by Wzfeng 12-29
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name(YEL"���"NOR, ({"jian feng"}));
	set_weight(1);
	if (clonep())			   
		set_default_object(__FILE__);
	else {
		set("long", "һ������װ�麯�ļ�⡣�䱳��մ��������ë��\n");
		set("unit", "��");
		set("value", 500);
		set("send_level",2);

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
	if(!arg) return notify_fail("��Ҫ��ʲôװ������\n");
	
	ob_letter = present(arg, me);
	if(!ob_letter)
		return notify_fail("�����Ϻ���û������麯��\n");
	if(!ob_letter->query("can_feng"))
		return notify_fail("�Բ����㲻�ܽ�����Ž�����\n");
	
	message_vision("$N�������ͳ�һ��д�õ��麯װ�ڼ���\n",me);

	ob_letter->set("long", "����һ��װ���麯�ļ�⡣�䱳��մ��������ë��\n");
	ob_letter->set_name(YEL"�ź�"NOR, ({"xin han","letter"}));
	ob_letter->set("can_feng",0);

	ob_letter->set("can_send",1);
	ob_letter->set("letter/send_level",2);
	destruct(this_object());
	return 1;
}

