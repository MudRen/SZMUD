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
		"east" : __DIR__"ml2",
		"west" : __FILE__,
		"south" : "/d/city/dongmen",
		"north" : __FILE__,
	]));
	set("cost", 3);
	setup();
//	replace_program(ROOM);
}
