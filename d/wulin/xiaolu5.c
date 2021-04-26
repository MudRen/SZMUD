// room /d/wulin/xiaolu5.c
//updated by Lara 2001/10/17
inherit ROOM;
void create()
{
        set("short", "小路");
        set("long", @LONG
这里是一条山间小路。但因常有人走，路面已非常平整，一路上怪石嶙
峋，边走边看，也颇有一番情趣。
LONG
        );

        set("exits", ([
         "west" : __DIR__"dianmen",
         "east" : __DIR__"xiaolu6",
        ]));

        set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
