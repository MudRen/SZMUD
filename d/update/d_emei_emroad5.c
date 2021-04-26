// Code of ShenZhou
// /d/emei/emroad5.c 小路
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "青石大路");
        set("long", @LONG
这里是一条通向长安城的青石大路，两旁有些小土屋，疏疏落落的。路上行
人很少，都行色匆匆向北赶路。争取早点到长安城。
LONG
        );
        set("exits", ([
                "east" : __DIR__"emroad6",
                "north" : "/d/changan/nanmen",
                "southwest" : __DIR__"emroad4",
        ]));

        set("no_clean_up", 0);

	set("outdoors", "emei");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}

