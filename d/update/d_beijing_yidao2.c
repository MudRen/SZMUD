// Code of ShenZhou
//ywz yidao2.c
inherit ROOM;

void create()
{
        set("short", "青石大道");
        set("long", @LONG
你走在一条青石大道上，四周静悄悄的。太阳正高挂在东方的天空中。西
北面就是京城的南门「永安门」。 
LONG
        );
        set("outdoors", "shenlong");
        set("exits", ([
		"southwest" : __DIR__"yidao1",
                "northwest" : __DIR__"yidao2",
		"northeast" : __DIR__"yidao3",
                "north" : __DIR__"gaoliangdi",
        ]));
	set("cost", 2);

        setup();
        replace_program(ROOM);
}
