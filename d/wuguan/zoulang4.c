//Cracked by snso k1-8-5-6
// Room: zoulang4.c 走廊 4

inherit ROOM;

void reset();
int valid_leave();

void create()
{
    set("short", "走廊");
    set("long", @LONG
走到这里你顿觉得宽敞了很多，不住的有人来来往往，再往西面走就到了
任务控制室，东南面便是玩家切磋武功的试功室了。
LONG
    );                                                                                         

    set("exits", ([
	"north" : __DIR__"houting",
	"southeast" : __DIR__"shigong",
//	"west" : __DIR__"renwu",
    ]));
      set("no_fight", 1);
      set("no_clean_up", 0);
      set("cost", 1);
    setup();
    //replace_program(ROOM);
}
