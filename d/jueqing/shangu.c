// Filename:   /d/jueqinggu/shangu.c ɽ��
// Jiuer Aug 15, 2001
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","ɽ��");
	set("long",@LONG
����Ϫ�����ۣ�����(row raft)��ת�������ɽ�ȣ�����ɽ��������
����ʮ���վ���վ�ڸ߸ԣ������Ĺȣ�������ľɭɭ��������ҫ������
��䣬ƮƮ�����ģ����������ƶˡ�
LONG);

	  set("outdoors","jueqing");
	  set("resource/water", 1);
	  set("cost",1);
	  
	  setup();	
}

void init()
{
	add_action("do_row","row");
	add_action("do_drift","drift");
}

int do_row(string arg)
{
    object ob, me = this_player();

	if(!arg||arg=="")
		return 0;
	if(arg =="raft") {
		
		message_vision("$Nʹ���ذѷ�����ǰ��ѽ����ѽ��\n\n", me);
		me->receive_damage("jingli", 10, "��ˮ������");
		message_vision("$N���ŷ���ʻ����ɽ���\n\n",me);
		me->move("/d/jueqing/valley");
		return 1;
 }
 else
	 return notify_fail("��Ҫ��ʲô��\n");
}

int do_drift()
{
	object me = this_player();
	message_vision(HIW"$N�ս����ң�Ƥ��˳�ӵ���Ư�����¡�\n"NOR,me);
	me->move("/d/jueqing/dongkou");
	message_vision(HIW"��ˮ����$N��Ƥ���������Ŵ�����Ư�����¡�\n"NOR,me);
	return 1;
}
