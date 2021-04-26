// Code of ShenZhou
// jiuer 6/17/2002

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
这是灵蛇阁后面的一个大院子，向北面远眺是那两座白沙堆积而成的
白驼山，山峰高高隆起象是骆驼的脊背，再往西远眺便是那险恶无比的昆
仑山，山顶依稀可见终年不化的皑皑白雪。
LONG
	);
	set("exits", ([ 
	  //  "north" : __DIR__"btshan",
	    "east" : __DIR__"lingshege",
		"south" : __DIR__"kongdi2",
	  //  "southwest" : __DIR__"bedroom3",
	  //  "southeast" : __DIR__"kitchen",
	]));
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
