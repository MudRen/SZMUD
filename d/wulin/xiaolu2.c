// room /d/wulin/xiaolu2.c
//updated by Lara 2001/10/17
inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
小路继续向西延伸，景色越发清幽，路两旁草木逐渐多了起来，不时
有野兔在树丛中窜过。
LONG
        );

        set("exits", ([
         "east" : __DIR__"xiaolu1",
         "west" : __DIR__"xiaolu3",
        ]));

        set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}













