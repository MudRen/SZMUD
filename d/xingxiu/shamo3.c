// Code of ShenZhou
// Room: /d/xingxiu/shamo3.c

#include <room.h>
inherit ROOM;

void create()
{
       set("short","��ɳĮ");
       set("long", @LONG
����һƬһ���޼ʵĴ�ɳĮ����һ��������ʧ�˷���
����Ҫ�߳����ɳĮ�������¡�
LONG
     );
	set("exits", ([
		"east" : __FILE__,
		"west" : __DIR__"shamo4",
//                "south" : __DIR__"shamo1",
                "south" : __DIR__"shamo5",
		"north" : __DIR__"shamo2",
	]));
	set("cost", 5);
	set("outdoors", "xingxiu-hai");
	setup();
}

#include "/d/xingxiu/shamo.h"
