// Code of ShenZhou

// road: /zhongnan/houyuan.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short","СԺ��");

        set("long",@LONG
���ǳ������һ��СԺ�ӡ���Զ��Χǽ�Ǩ棬һ��С�������š�����
С���������ɽ�ˡ������ǳ�������������ɽ��
LONG);

		  set("exits",([ "south" : __DIR__"kitchen1",
								"west" : __DIR__"haoshanxiaojing1",
							 ])
			  );
	  set("cost",2);
	  set("outdoors", "zhongnan");
	  create_door("south", "ľ��", "north", DOOR_CLOSED);

	  setup();
}
