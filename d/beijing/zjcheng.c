// Code of ShenZhou
// Room: /d/beijing/zjcheng.c

inherit ROOM;

void create()
{
        set("short", "紫禁城城门");
	set("long", @LONG
这是紫禁城城门。向里面望去就是京城里第一大的皇帝住的宫殿，普通百姓
要想进去那里面简直比登天还要难。门口站了几名威武的守卫，让人感觉庄严肃
穆，不时的见到有大官在这里出入。
LONG
	);
        set("exits", ([
                "north" : __DIR__"jingshan",
                "south" : __DIR__"changanjie",
                "east" : __DIR__"wangfudajie",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
