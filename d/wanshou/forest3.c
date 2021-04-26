// Code of ShenZhou
// /d/wanshou/forest3.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void reset_path(object me);
void check_out(object me);

void create()
{
        set("short", "����");
        set("long", @LONG
��һƬ������ľï�ܣ�������գ������������ޱ��޼ʡ��ڰ�
�оͻ���ʲô����ͻ�������������ȥ�Ƶġ����������һƬ����
�ޱߡ������ڰ������ֲ���һ�󵨺����������ǸϿ��˳�ȥ�ĺá�
LONG
        );
        set("exits", ([
				"north" : __DIR__"forest6",
				"south" : __DIR__"forest9",
				"east" : __DIR__"forest1",
				"west" : __DIR__"forest2",
        ]));

        set("outdoors", "wanshou-shanzhuang");

	    set("cost", 1);
        setup();

}

void  init()
{              
	object  me=this_player();

	if(  me->query_temp("tree3")  ==  0  )
	{
		me->set_temp("tree3",  1);
	}
	else  if(  me->query_temp("tree3")  ==  1  )
	{
		reset_path(me);
	}
	
	if(  check_out(me)  )
	{  
        set("exits/south", __DIR__"forest0");
        call_out("close_exit_forest", 5);
	}
}

void close_exit_forest()
{
       set("exits/south", __DIR__"forest9");
}

void  reset_path(object me)
{
	int i;

	for (i=1; i<10; i++) {
   	   if(  me->query_temp("tree"+i)  )     	   
   	        me->delete_temp("tree"+i);
	}
	return;
}

int  check_out(object  me)
{
	int i;

	for (i=1; i<10; i++) {
   	   if(  me->query_temp("tree"+i) != 1 )     	   
		  return 0;
	}
	reset_path(me); 
	return 1;
}