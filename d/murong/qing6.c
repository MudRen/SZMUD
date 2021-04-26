// Code of ShenZhou
// Room: /d/murong/qing6
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "内室");
	set("long", @LONG
    你一走进内室，就闻到一股脂粉味，看来已经来到内眷居住的地方。
你色心稍起，偷偷打量了一下四周，见床沿放着一两件短衣，色彩甚是
淡雅。
LONG
	);
	set("cost", 1);
	set("exits", ([ 
        "south" : __DIR__"qing5",
        "north" : __DIR__"huayuan1",
        "east" : __DIR__"qing7",
        "west" : __DIR__"qing8",
        "northwest" : __DIR__"qing9",
                      ]));

	set("no_clean_up", 0);
        

	setup();
	replace_program(ROOM);
}
