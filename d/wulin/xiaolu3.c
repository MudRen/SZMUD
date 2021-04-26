// room /d/wulin/xiaolu3.c
//updated by Lara 2001/10/17
inherit ROOM;
void create()
{
        set("short", "小路");
        set("long", @LONG
至此已无去处，转而向北，路两旁树木整齐排列，在风中哗哗作响。
北面即是赏善居。由此向东三里是武林同盟的殿门所在。
LONG
        );

        set("exits", ([
         "east" : __DIR__"xiaolu2",
         "north" : __DIR__"xiaolu4",
        ]));

        set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
