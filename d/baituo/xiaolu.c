// Code of ShenZhou
// room: /d/baituo/xiaolu.c
// Jay 10/8/96

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
这里是胡杨林西面的一条小路。西面隐隐约约显出一座白沙吹积而成
的山，山缝间飘出缕缕的柴烟，看来这里住有人家。
LONG
        );
        set("exits", ([ 
            "east" : "/d/xingxiu/huyang4",
            "west" : __DIR__"btgate",
        ]));
        set("outdoors","baituo");
        replace_program(ROOM);
		set("cost", 1);
		setup();
}

