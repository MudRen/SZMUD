// Code of ShenZhou
// Room: /d/murong/qing7
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "卧室");
	set("long", @LONG
    卧室很整洁。靠窗是一张圆桌，三四把红木座椅团团而靠。
见你进来，一个八九岁的女童正诧异地盯着你看，目光中流露
出一丝怒意。
LONG
	);
	set("cost", 1);
	set("exits", ([ 
        "west" : __DIR__"qing6",
                      ]));

	set("no_clean_up", 0);
        set("objects", ([
		"/d/murong/npc/buliang" : 1,
		]));

	setup();
	replace_program(ROOM);
}
