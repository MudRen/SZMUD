// Code of ShenZhou
// Room: /city/milin.c

#include "ml.h"

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
	����һƬï�ܵ������֣�һ�߽�������·���ʧ�˷���
LONG
	);

	set("exits", ([
		"east" : __FILE__,
		"west" : __DIR__"ml4",
		"south" : "/d/city/dongmen",
		"north" : __FILE__,
	]));

//	set("objects", ([
//		__DIR__"npc/zhangzi": 1,
//	]));

	set("cost", 3);
	setup();
//	replace_program(ROOM);
}
