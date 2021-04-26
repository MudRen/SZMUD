// Code of ShenZhou
// Room: /d/murong/qing9
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
    书房里挂着很多长兵器，看来主人文武双全。你有些猜不
透这里究竟是谁的住处。
LONG
	);

	set("cost", 1);
	set("exits", ([ 
        "southeast" : __DIR__"qing6",
                      ]));

	set("no_clean_up", 0);
        
	setup();
	replace_program(ROOM);
}
