// /d/jueqing/garden.c  ��԰
// By jiuer

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIR"��԰"NOR);
	set("long",@LONG 
ֻ������ҫ�ۣ������˱ǣ����Ǳ�����أ���Ŀ�Ĺˣ�ֻ��������
�ݣ���ͬһ������Ļ�԰��Ȼ��Ӱ�������Ĺ����ˡ�����ʮ�������м�
��é�ݡ�
LONG);
	
	set("exits",([ 
		"east" : __DIR__"maowu",
		"westdown" : __DIR__"bingyao",
		]));
	set("outdoors","jueqing");

	set("cost",1);
	setup();
}

int do_dive(string arg)
{
	object me = this_player();
	if(!arg||arg !="in")
		return 0;

	if(arg == "in") 
	{
		message_vision("$N������̶��ֱ���Ǳȥ��\n",me);
		me->add("jingli",-50);
		message_vision("$N�������£��͵���ֻ��һ�ɼ��������ȥ����������Ȼ��һ����\n",me);
		set("exits/up",__DIR__"bingyao");
		remove_call_out("close_door");
		call_out("close_door",5,me);
		return 2;
	}
}

void close_door()
{
	tell_room(this_object(),"$NǱ����ѣ��ص�̶�ߡ�\n");
	delete("exits/up");
}