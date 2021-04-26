//Room: /d/kaifeng/fumen.c
//by bravo
inherit ROOM;
void create()
{
        set("short", "开封府门");
        set("long", @LONG
这便是开封府门。巍峨雄伟的城墙上， "开封府衙" 四个大字
十分显眼，气势辉煌。几名亲兵立在两旁。
LONG
        );

        set("exits", ([
                "north":__DIR__"kaifengfu",
                "south":__DIR__"guangchang",
                ]));
        set("objects", ([
                __DIR__"npc/bing" : 4,
                __DIR__"obj/dagu" : 1,
        ]));
        set("cost", 1);
        set("outdoors", "kaifeng");
        setup();
}
/*
int valid_leave(object me, string dir)
{
                
        if (!wizardp(me) && objectp(present("guan bing", environment(me))) && dir == "north")
                return notify_fail("官兵拦住了你的去路。\n");
        return ::valid_leave(me, dir);
}
*/
