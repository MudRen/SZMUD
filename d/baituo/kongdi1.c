// Code of ShenZhou
// jiuer
// d/baituo/kongdi1.c

inherit ROOM;

void create()
{
	set("short", "空地");
	set("long", @LONG
这是一大片非常平整的沙石空地，地上稀稀拉拉地长着些戈壁植被，
地上有些大大小小的褐色石子和红色的干硬土块，西北边通往山庄的前院
东边飘来阵阵酒菜香气。东南和西南两个角上各有一扇小门通到蛇室。
LONG
	);
	set("exits", ([ 
	    "northwest" : __DIR__"road2",
		"southwest" : __DIR__"barn4a",
		"southeast" :__DIR__"barn5a",
	]));
	create_door("southeast", "木门", "northwest");
	create_door("southwest", "竹门", "northeast");

	set("outdoors","baituo");
	set("cost", 1);
	setup();
}

int valid_leave(object me, string dir)
{
    if (dir == "southeast" || dir == "southwest") 
	{
		if (me->query("family/family_name")!="白驼山")
		{ 
			return notify_fail("蛇室毒气太重，你还是不要进去为好！\n");
		}
    }
    return ::valid_leave(me,dir);
}
