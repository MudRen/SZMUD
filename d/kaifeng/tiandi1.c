// Code of ShenZhou
// chchong 2002/02/01
// /d/kaifeng/tiandi1.c

inherit ROOM;

void create()
{
    int i;
        set("short", "田地");
        set("long", @LONG
这里林木渐渐稀疏，不远处有一些村庄，炊烟袅袅升起。村庄周围
是一块块的田地，田里有一些正在耕作的农人。
LONG
        );

        set("exits", ([
                "north" : __DIR__"nanmen",
                "south" : __DIR__"tiandi2",
        ]));

        set("outdoors","kaifeng");
	set("cost", 2);
        setup();
	replace_program(ROOM);
}

