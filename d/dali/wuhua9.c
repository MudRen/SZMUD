// Code of ShenZhou
// Room: /d/dali/wuhua9.c

inherit ROOM;

void create()
{
	set("short", "贵宾房");
	set("long", @LONG
这里通常是南方部族首领进都时的住所。这里的摆设多与其
洞中相仿，地上垫了几张虎皮，豹皮。墙边则是一张乌檀木的大
床，东壁上挂了几把弯刀，枪，铲之物。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"wuhua7.c",
]));
        set("objects", ([
__DIR__"npc/leader1" : 1,
        ]));

set("cost", 1);
	setup();
	replace_program(ROOM);
}
