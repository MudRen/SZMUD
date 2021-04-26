// Code of ShenZhou
// room: /d/baituo/btroad
// Jay 10/8/96

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
这里是胡杨林西面的一条小路。西面通往白驼山。
LONG
        );
        set("exits", ([ 
            "east" : "/d/xingxiu/huyang4",
            "west" : "/d/baituo/btgate",
        ]));
        set("outdoors","baituo");
        replace_program(ROOM);

	set("cost", 1);
        setup();
}

