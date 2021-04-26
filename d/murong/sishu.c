// Code of ShenZhou
// Room: /d/murong/lianwu
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "私塾");
	set("long", @LONG
    这间私塾是为慕容氏弟子的家眷开设的，聘请了一个
外地口音的老秀才授课。
LONG
	);
	set("cost", 1);
	set("exits", ([ 
        "west" : __DIR__"lianwu1",
                      ]));

	set("no_clean_up", 0);
       

        set("objects", ([
		"/d/city/npc/xiucai" : 1,
		]));

	setup();
	replace_program(ROOM);
}

