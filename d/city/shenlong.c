// Code of ShenZhou
// Room: /city/shenlong.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
shen long
��Ҫ�����˵������
LONG
	);

	set("exits", ([
		"west" : __DIR__"road7",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}
