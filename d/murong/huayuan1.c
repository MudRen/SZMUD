// Code of ShenZhou
// Room: /d/murong/huayuan1
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "后花院");
	set("long", @LONG
花院不大，但布置得甚为精巧。二三株柳树随风轻舞，柳叶
不时地吹拂在假山石上，姿态万千。
LONG
	);
	set("cost", 1);
	set("outdoors", "murong");
	set("exits", ([ 
        "south" : __DIR__"qing6",
        "east" : __DIR__"huayuan3",
                      ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
