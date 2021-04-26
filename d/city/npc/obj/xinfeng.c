// Code of ShenZhou
// Write by Wzfeng 12-29

inherit ITEM;

void create()
{
	set_name("����", ({"feng tao"}));
	set_weight(1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������װ�麯�ķ��ס�\n");
		set("unit", "��");
		set("value", 100);
		set("send_level",1);
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
		return notify_fail("�����Ϻ���û������麯��\n");
	if(!ob_letter->query("can_feng"))
		return notify_fail("�Բ����㲻�ܽ�����Ž������\n");
	
	message_vision("$N�������ͳ�һ��д�õ��麯װ�ڷ����\n",me);

	ob_letter->set("long", "����һ���Ѿ���õķ��ף�����װ���麯��\n");
	ob_letter->set_name("�ź�", ({"xin han","letter"}));
	ob_letter->set("can_feng",0);		
	ob_letter->set("can_send",1);
	ob_letter->set("letter/send_level",1);
	destruct(this_object());
	return 1;
}



