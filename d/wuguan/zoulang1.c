//Modified by Lisser
// Room: zoulang1.c 走廊１
// qfy July 7, 1996.

inherit ROOM;

void reset();
int valid_leave();

void create()
{
    set("short", "走廊");
    set("long", @LONG
走廊两旁都有矮墙，将武馆前后间隔起来。东北边是学基本功夫的请
教室。西南边也是请教室，可学各派的入门武功。
LONG
    );

    set("exits", ([
	"east" : __DIR__"qianting",
	"west" : __DIR__"zhengting",
	"northeast" : __DIR__"qingjiao1",
	"southwest" : __DIR__"qingjiao2",
    ]));

    set("no_clean_up", 0);

	set("cost", 1);
    setup();
    //replace_program(ROOM);
}
