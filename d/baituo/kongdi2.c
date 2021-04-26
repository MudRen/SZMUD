// Code of ShenZhou
// jiuer
// d/baituo/kongdi2.c

inherit ROOM;

void create()
{
	set("short", "空地");
	set("long", @LONG
这是一大片非常平整的沙石空地，地上稀稀拉拉地长着些戈壁植被，
地上有些大大小小的褐色石子和红色的干硬土块，北边通往山庄的后院，
再往前走就是白驼山庄的训蛇场和工具房。
LONG
	);
	set("exits", ([ 
	    "north" : __DIR__"houyuan",
		"southeast" : __DIR__"toolroom",
		"southwest" :__DIR__"trainroom",
	]));

	set("outdoors","baituo");
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
