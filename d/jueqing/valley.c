// Filename:   /d/jueqinggu/valley.c ɽ���
// Code by :   Jiuer
// Date:       Aug 15, 2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","ɽ���");
	set("long",@LONG
Ƥ������ɽ���������ɽ��ˮ�̣���ɫ�������ģ����¼�����Ϣ��
����͸�����ա����ֻ��������Ϫ�ĺ��оſ��ʯ(stone)ӭ��������
��������һ�㣬��ס������ȥ·��
LONG);
	
	set("item_desc",([
		"stone" : "�ſ�޴����ʯ��ɵ�ʯ������ס��ȥ·����������ԥ��֪\n"
		+"����ô��ȥʱ��ͻȻ�������½ǵ���ʯ��������ײ���е㲻ͬ��\n"
		]));

	set("outdoors", "jueqing" );
	
	set("cost",2);
	setup();	
}

void init()
{
	add_action("do_push","push");
	add_action("do_drift","drift");
}

int do_push(string arg)
{
 	object me = this_player();
	if( !arg||arg == "" )
		return 0;
	if( arg == "stone"||arg=="shi") 
	{
		message_vision("$N���ְ��˰�����ʯû���κη�Ӧ��$N˳������һ����ʯ����\n"+
        "ֻ��������һ�����죬�м��������ʯ�������ѿ���¶��һ��ϸխ�ĺӵ���\n\n",me);

        remove_call_out("close_door");
        call_out("close_door",10,me); 
		
		message_vision("$NѸ�ٵػ���ӵ���Ƥ����ǰʻȥ��\n\n",me);
		me->move("/d/jueqing/path");
		message_vision("$N����Ƥ����ת����ɽ����ȥ��\n",me);
		return 1;
        }
        else
			return notify_fail("��Ҫ��ʲô��\n");
}
int do_drift()
{
	object me = this_player();
	message_vision(HIW"$N�ս����ң�Ƥ��˳�ӵ���Ư�����¡�\n"NOR,me);
	me->move("/d/jueqing/shangu");
	message_vision(HIW"��ˮ����$N��Ƥ���������Ŵ�����Ư�����¡�\n"NOR,me);
	return 1;
}
void close_door()
{
        tell_room(this_object(),"�ֹ���һ���������һ���¡������ʯ�ֱ�������һ��\n");
}
