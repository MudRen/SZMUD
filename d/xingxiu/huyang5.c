// Code of ShenZhou
// huyang road
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "胡杨林");
	set("long", @LONG
道路两边疏疏落落地生长着一片胡杨木，往北越渐茂盛，南方
的就是西域大城疏勒。
LONG
	);

	set("exits", ([
		"north" : __DIR__"huyang3",
		"south" : __DIR__"shule",
	]));
	set("outdoors","xingxiu");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}

