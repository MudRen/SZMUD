// Code of ShenZhou
// /d/xingxiu/silk4.c
// Jay 3/17/96
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
		"west" : __DIR__"shamo2",
		"south" : __DIR__"shamo3",
		"north" : __DIR__"shamo4",
	]));             
	set("cost", 4);
	set("outdoors", "xingxiu-hai");
        setup();

}

#include "/d/xingxiu/shamo.h"
