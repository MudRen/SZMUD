// Code of ShenZhou
// Room: /city/xixiang.c
// YZC 1995/12/04 
// Jay 2/3/97

inherit ROOM;

void create()
{
	set("short", "Ѿ���Է�");
	set("long", @LONG
����Ѿ�ߵķ��䡣���г���򵥣�ûʲô������
LONG
	);

	set("exits", ([
		"east" : __DIR__"houyuan",
	]));
	set("objects", ([
		__DIR__"npc/juyou" : 1,
	]));
	set("cost", 0);
	setup();
	replace_program(ROOM);
}

