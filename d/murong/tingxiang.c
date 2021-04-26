// Code of ShenZhou
// Room: /d/murong/tingxiang
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "听香水榭");
	set("long", @LONG
    水榭前后左右处处都是杨柳，但阵阵粗暴的轰脚声不断从屋中
传出来。这等叫嚷吆喝，和周遭精巧幽雅的屋宇花木实是大大不称
LONG
	);
	set("cost", 1);
	set("outdoors", "murong");
	set("exits", ([ 
        "south" : __DIR__"mantuo1",
                      ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
