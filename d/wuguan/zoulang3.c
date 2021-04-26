//Creatied by Zyu Snso on k1-8-4
// Room: zoulang3.c 走廊3

inherit ROOM;

void create()
{
    set("short", "走廊");
    set("long", @LONG
沿路走过来，饭香气越来越浓，从西面屋里散发出来，你情不自禁地
用鼻子使劲地嗅了嗅，看来厨房就在西边了！北面的房里传来金木撞击声
，想来就是各位前辈们所说的练功房。东北是一座漂亮的房子，总有人出
出进进的，你也不由往房子踱去。
LONG
    );

    set("exits", ([
	"north" : __DIR__"liangong",
	"south" : __DIR__"houting",
	"northeast" : __DIR__"xiulian",
	"west" : __DIR__"chufang",
    ]));

	set("no_fight", 1);
    set("no_clean_up", 0);
    set("resource/water", 1);	

	set("cost", 1);
    setup();
}
