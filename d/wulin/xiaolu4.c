// room /d/wulin/xiaolu4.c
//updated by Lara 2001/10/17
inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
小路至此已到尽头。赏善居共分两处，依山而建，分布于两侧。其布
局极佳，与周围树木浑然一体。
LONG
        );

        set("exits", ([
         "east" : __DIR__"shangjue",
         "west" : __DIR__"shangjuw",
         "south" : __DIR__"xiaolu3",
 ]));

        set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

