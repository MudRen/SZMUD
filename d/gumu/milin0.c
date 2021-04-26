// July 31,2000 
// Code by April
// /gumu/milin0.c

inherit ROOM;

void create()
{
	set("short","树林外");

    set("long",@LONG
你走向树林，只闻泉水叮咚，小鸟啼莺。一股淡淡薄雾带着极甜的花香，
自密林深处传出。几只乳白色的蜜蜂从林中嗡嗡飞来，在你身旁转了一圈
又飞回去了。往南进入树林，北面是一块空地。
LONG);
	
	set("exits",([ "south" : __DIR__"milin1",
		"north" : __DIR__"kongdi",
		]));

	set("objects", ([
                "/kungfu/class/gumu/npc/huangyi" : 1,
                ]));

	set("cost",2);
	set("outdoors", "gumu");

	setup();
	replace_program(ROOM);
}
