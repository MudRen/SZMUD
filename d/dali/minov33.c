// Code of ShenZhou
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "农田");
	set("long", @LONG
这是一小块普通的水田，附近有溪流流过，灌溉十分方便。围绕
农田的是一片片桑林，摆夷人采桑、养蚕，纺织相当精致的丝织品。
西边有所民居。
LONG
        );

	set("exits", ([
		"west" : __DIR__"minov34",
		"south" : __DIR__"minov31",
		]));

	set("objects", ([
		"/d/dali/npc/niu.c" : 1,
		"/d/dali/npc/bynong.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 3);
	setup();
}
