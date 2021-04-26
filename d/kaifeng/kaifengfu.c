//Room: /d/kaifeng/kaifengfu.c
//by bravo
inherit ROOM;
void create()
{
        set("short", "开封府门");
        set("long", @LONG
这里便是开封府大人办公事的地方。正前方 (front)大红楠木案桌
后端坐着的，就是人称包青天的包拯大人。两边站立纹风不动的是他的
亲兵侍从，看上去都十分彪悍。
LONG
        );
        set("item_desc", ([
                      "front" : " 
    皇上御赐的牌匾上写的是“清正廉洁”。
\n",
]));

        set("exits", ([
                "south":__DIR__"fumen",
                ]));

        set("objects",([
              __DIR__"npc/bao":1,
              __DIR__"npc/wang":1,
              __DIR__"npc/ma":1,
                 ]));
        "clone/board/kff_b.c"->foo();
        setup();
        replace_program(ROOM);
}
int valid_leave(object me, string dir)

{
       if ( me->query_temp("kff/my") == "can" && dir == "south")
              me->delete_temp("kff/my");
        return ::valid_leave(me, dir);
}
