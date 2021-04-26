// Code by April
// /gumu/huawu.c

inherit ROOM;

void create()
{
        set("short","花房树屋");

        set("long",@LONG
你一矮身钻进花丛，但见花丛如一座大屏风，红瓣绿枝，煞是好看，
四下树荫垂盖，便似天然结成的一座花房树屋。你四下张望，见东南西北
都是一片清幽，只闻泉声鸟语，杳无人迹，确是个上好的练功所在。
LONG);

        set("exits", ([
        "out" : __DIR__"milin10",
                      ]));
		set("resource/water", 1);	

		set("cost",1);
		set("outdoors", "gumu");
        setup();
        replace_program(ROOM);
}
