// Code of ShenZhou
// jiuer 6/17/2002

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
房前是一条白砖砌墙的长廊，北边通往大厅，后面是白驼山庄众家丁
所住的房间。西南边另有一扇小门，那是家丁、婢女等下人们休息的所在。
东南边的走廊飘来阵阵香味，是白驼山庄的厨房。
LONG
	);
	set("exits", ([ 
	    "north" : __DIR__"changlang4",
	    "southwest" : __DIR__"bedroom3",
	    "southeast" : __DIR__"kitchen",
	]));
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
