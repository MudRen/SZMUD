// Code of ShenZhou
// Room: /d/dali/dalicheng10.c

inherit ROOM;

void create()
{
	set("short", "̫�;�");
	set("long", @LONG
���Ǵ���������ľ�¥��¥����Щ�����С�ԣ��������˳���������·�ˡ�
¥����������
LONG);
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
		]));
	set("exits", ([
		"west" : __DIR__"dalicheng9",
		"up" : __DIR__"dalicheng11",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	setup();
	replace_program(ROOM);
}

