// Code of ShenZhou
// 白驼改版
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
一条白砖砌墙的长廊，北边的拱门通往侧厅，西边小屋是白驼山庄众
武师所住的房间。南边是一大间练功房，庄主常在这里给庄丁们教练哈蟆
功的技巧。
LONG
	);
	set("exits", ([ 
	    "north" : __DIR__"ceting",
	    "west" : __DIR__"bedroom2",
		"south" : __DIR__"liangongfang",
	  //  "southwest" : __DIR__"bedroom3",
	  //  "southeast" : __DIR__"kitchen",
	]));
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
