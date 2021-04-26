//Modified by Zyu Snso on k1-8-4
// Room: zoulang2.c 走廊２
// qfy July 30, 1996.

inherit ROOM;

void create()
{
    set("short", "走廊");
    set("long", @LONG
这是连接武馆里大厅和后厅的走廊。平时寥无声息，只有一两个弟子
偶尔匆匆走过。
LONG
    );

    set("exits", ([
/*	"north" : __DIR__"zhuangbei",
	"south" : __DIR__"yiliaoshi",*/
	"east" : __DIR__"zhengting",
	"west" : __DIR__"houting",
    ]));

	set("no_fight", 1);
    set("no_clean_up", 0);
    set("resource/water", 1);	

	set("cost", 1);
    setup();
}
