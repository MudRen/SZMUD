// Code of ShenZhou
// Room: /d/newdali/dian2.c

inherit ROOM;

void create()
{
	set("short", "沿池堤岸");
	set("long", @LONG
这里沿湖堤岸遍植白色的素馨花，故又称“银棱河”；而它的一条分支，
堤岸栽种黄色的迎春花，故称“金棱河”，或金汁河。两河同为滇池的出水
口，又称海口。
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"riverbank",
  "north" : __DIR__"dian1",
  "eastup" : __DIR__"dian3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
