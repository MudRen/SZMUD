// Code of ShenZhou
// Room: /d/murong/qing8
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "女红间");
	set("long", @LONG
    这间屋子是阿碧做女红活的房间。正中的桌子上还有一件
为缝好的男式长袍，看来阿碧是准备为慕容公子做的。
LONG
	);
	set("cost", 1);
	set("exits", ([ 
        "east" : __DIR__"qing6",
                      ]));

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
