//room /d/wulin/zoulang.c 
// updated by Lara 2001/10/14
inherit ROOM;
void create()
{
        set("short", "走廊");
        set("long", @LONG
这是一道长长的由翠绿青竹搭成的走廊，周围种满翠竹，凤尾森森，
龙吟细细，令人精神为之一振。走廊的两旁摆满了精巧盆景，别有一番情
趣。再往北走就是侠义堂了。
LONG
        );

        set("exits", ([
                "south" : __DIR__"dianmen",
                "north" : __DIR__"xiayitang",
        ]));

        set("no_clean_up", 0);
        set("cost", 1);
        setup();
       replace_program(ROOM);
}
