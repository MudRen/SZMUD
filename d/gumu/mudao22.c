// July 31,2000
// Code by April
// /gumu/mudao22.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short","Ĺ��");

        set("long",@LONG
����ɭɭ��Ĺ����Ҳ��֪����ͨ���Ķ��ġ�ǽ�ϵ�һ֦С��������
���ࣵ�ȼ���š��ǻ��ε�΢�⣬������������һ��Ĺ������Զһ�����
�������ˡ�Ĺ����ͷ�ƺ���Щ����������
LONG);

	 set("exits",([ 
		"west" : __DIR__"mushi",
		"east" : __FILE__,
		"south" : __DIR__"mudao21",
		"north" : __FILE__,
		 ])
			  );

	create_door("west","���ص�ʯ��","east",DOOR_CLOSED);

	  set("cost",1);

		  setup();

}
