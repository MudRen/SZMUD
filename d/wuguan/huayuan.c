//Cracked by snso k1-7-6
// Room: huayuan.c 后花园

inherit ROOM;

void reset();
int valid_leave();

void create()
{
    set("short", "后花园");
    set("long", @LONG
这是武馆的后花园，庭院清幽，异种花卉甚是不少。百花争放，山石古拙，
杨柳垂清，苍松翠竹，景致煞是宜人。再往东北面去就是后山了。
LONG
    );

    set("exits", ([
	"south" : __DIR__"kaojiao",
	"northeast" : __DIR__"houshan1",
    ]));

    set("no_clean_up", 0);

	set("cost", 1);
       set("no_fight", 1);
       set("no_steal", 1);
       set("no_hit", 1);
    setup();
    //replace_program(ROOM);
}
