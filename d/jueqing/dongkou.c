// Filename:   /d/jueqinggu/dongkou.c СϪ����
// Jiuer 08/ 2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",HIW"������"NOR);

	set("long",@LONG
������������ֻ�����׳���һ����խ��Ϫˮ��Ϫˮ��ڴ���һ���
��ľ��ס���㼱æ��תƤ�������������л��˽�ȥ��Ϫ��ɽʯ��ˮ�治
�����ߣ� �����ú���(lay)����(raft)ʼ�ܻ��룬��ˮ�ļ���Ƥ����
��Ư��(drift)��
LONG);
	
	set("outdoors", "/d/jueqing");		
	set("cost",1); 
	setup();
}

void init()
{
  add_action("do_lay","lay");
  add_action("do_drift","drift");
}

int do_lay(string arg)
{ 
	object me = this_player();
	if (!arg|| arg !="raft")            
		return 0;

	if(arg =="raft")
	{		
		message_vision("$N������Դ��У����Ƶ�ס������ʯ��С����������...\n\n", me);
		me->add("jingli",-20);		
		message_vision(
			"$N����һ��ͷ��¶��һ˿���ߣ�����ɽ�������¶��̧ͷ���죬����һ���졣\n"
			+"$N��ʻ����ɽ�ȵش���\n\n",me);
		me->move("/d/jueqing/shangu");
		remove_call_out("close_door");
		call_out("close_door",5,me);
		return 1;
	}	 
	return notify_fail("��һͷײ����ʯ�����ϣ�������������һ�����\n");
}

int do_drift()
{
	object me = this_player();
	message_vision(HIW"$N�ս����ң�Ƥ��˳�ӵ���Ư�����¡�\n"NOR,me);
	me->move("/d/jueqing/river");
	message_vision(HIW"��ˮ����$N��Ƥ���������Ŵ����η������¡�\n"NOR,me);
	message_vision(HIW"��ˮ��Ƥ�������ˣ�$N���ӵ��˰��ߡ�\n"NOR,me);
	return 1;
}

void close_door()
{
	tell_room(this_object(),"����һ���������һ��ɽ�磬���ڱ����Ը�ס�ˡ�\n");
}