// Code of ShenZhou
// Room: /d/beijing/zjchengmen.c

inherit ROOM;

void create()
{
        set("short", "紫禁城城门");
	set("long", @LONG
这是京城里皇帝住的地方。普通百姓来到这里就不能在向里面走了。
门边站着多名侍卫把守着这里，看起来庄严肃穆，给人一种神秘感。
LONG
	);
        set("exits", ([
                "east" : __DIR__"wangfudajie",
]));
	set("no_clean_up", 0);
        set("fanhua", 2);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
