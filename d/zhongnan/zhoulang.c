// Code of ShenZhou
// Room: /d/zhongnan/zhoulang.c
// Date: sdong 07/23/98

inherit ROOM;


void create()
{
		  set("short", "����");
		  set("long", @LONG
������һ�������ϣ�����ǰ�������ĵ����ͨ�������
LONG
		  );

		  set("exits", ([
					 "west" : __DIR__"taijie3",
					 "east" : __DIR__"dadian",
		  ]));

		  set("outdoors", "zhongnan");
		  set("cost", 2);
		  setup();
}

