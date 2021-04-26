// room /d/wulin/xiaolu7.c
//updated by Lara 2001/10/17
inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
山路延伸到这里，又变得开阔，天然形成一个平台。你向山下望去，只
见群山环绕，满是郁郁葱葱的森林，百里美景尽收眼底，不由得豪气顿生。
北面似乎有很庞大的一所建筑。

LONG
        );

        set("exits", ([
         "west" : __DIR__"xiaolu6",
         "north" : __DIR__"xiaolu8",
        ]));

        set("no_clean_up", 0);
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
