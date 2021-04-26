// Room: /d/chengdu/nandajie1.c
// By Jpei

inherit ROOM;

void create()
{
        set("short", "提督街");
        set("long", @LONG
提督街就是因为通往提督府而得名。这一带来往行人很少，做生
意的就更是绝迹了。提督大人好象有甚麽想不开的，派了好多兵在这
里守卫，连江湖人物都不敢轻率踏入。
LONG );
        set("outdoors", "chengdu");

	set("exits", ([
		"south" : __DIR__"nandajie2",
		"north" : __DIR__"center",
	]));
        set("objects", ([
            "/d/city/npc/bing" : 3,
        ]));

	setup();
	replace_program(ROOM);
}

