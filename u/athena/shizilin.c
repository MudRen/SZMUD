
// 苏梦馨(Athena) 
// Room：/u/athena/shizilin.c 

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "狮子林");
	set("long", @LONG
你一走进狮子林，便不禁为江南苏州园林的奇妙美景所折服
。狮子林东南多山，西北多水，素有”假山王国“之称。假山峰
峦叠嶂，曲折盘旋，石洞连绵不断，幽深莫测。咫尺之间，可望
而不可及，变幻无穷如入迷宫，不由得不为之赞叹不已。
LONG
	);
	set("exits", ([
	"west" : __DIR__"liuyuan",
        ]));
 	set("outdoors", "Sufu");
        setup();
}

