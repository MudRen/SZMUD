// /d/jueqing/bishuitan.c ��ˮ̶
// By jiuer

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIY"��ˮ̶"NOR);
	set("long",@LONG 
���ﾹ��һ��ˮ̶���������ɸߴ�Ծ�������������ε����ң���ֱ
��׹����ȥ��Ҳ��֪����ˮ�ж��
LONG);
	set("outdoors","jueqing");

	set("cost",1);
	setup();
}

void init()
{
	add_action("do_dive","dive");
	add_action("do_climb","climb");
}

int do_dive(string arg)
{
	object me = this_player();
	if(!arg)
		return 0;

	if(arg == "down") 
	{
		message_vision("$N������̶��ֱ���Ǳȥ��\n",me);
		me->add("jingli",-50);
		message_vision("$N�������£��͵���ֻ��һ�ɼ��������ȥ����������Ȼ��һ����\n",me);
		set("exits/enter",__DIR__"bingyao");
		remove_call_out("close_door");
		call_out("close_door",5,me);
		return 1;
	}
}

int do_climb(string arg)
{
	object me = this_player();
	
	if(arg =="up")
	{ 
		message_vision("$Nʪ���˵Ĵ�̶ˮ������̶����\n",me);
		me->move(__DIR__"tanbian");
		return 1;
	} 
	else
		return 0;
}
void close_door()
{
	tell_room(this_object(),"ˮ�������ǿ����ʱ���������ı���������������\n");
	delete("exits/enter");
}