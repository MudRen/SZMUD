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
		"west" : __FILE__,
		"south" : "/d/city/dongmen",
		"north" : __DIR__"ml3",
	]));
	set("cost", 3);
	setup();
//	replace_program(ROOM);
}
