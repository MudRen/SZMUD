//Modified by Zyu Snso on k1-8-4
// Room: zoulang2.c 走廊２
// qfy July 30, 1996.

inherit ROOM;

void create()
{
    set("short", "后厅");
    set("long", @LONG
这是一般人到不了的武馆后厅。南北都有走廊，也不知道沿着路走
会到达什么地方。北面不时传来阵阵香气，想必也是厨房的所在了。西
边静悄悄的，大异于其他地方闹哄哄的氛围，相信也是休息室了。
LONG
    );

    set("exits", ([
	"north" : __DIR__"zoulang3",
	"south" : __DIR__"zoulang4",
	"east" : __DIR__"zoulang2",
	"west" : __DIR__"bedroom",
    ]));

    set("no_clean_up", 0);
    set("resource/water", 1);	

	set("cost", 1);
    setup();
}
