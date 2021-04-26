//Modified by Lisser
// Room: test.c 检测室

inherit ROOM;

void reset();
int valid_leave();

void create()
{
    set("short", "修行检测室");
    set("long", @LONG
这里从修葺开始便用于检测武馆弟子功夫，保证出师弟子能在江湖上
立足。墙上到处都是真气划过的伤痕，应该是武馆出师的前辈们留下的。
现在负责检测修行的武馆新聘来的高手杨风。
LONG
    );
    
	set("objects", ([
		__DIR__"npc/tester" : 1,
	]));

	set("no_clean_up", 0);
	set("sleep_room", 0);
	set("no_fight", 1);
	set("no_steal", 1);
	set("cost", 1);

	setup();
}
