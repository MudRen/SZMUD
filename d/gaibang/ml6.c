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
		"west" : __DIR__"ml7",
		"south" : "/d/city/dongmen",
		"north" : __FILE__,
	]));
	set("cost", 3);
	setup();
//	replace_program(ROOM);
}
