// Code of ShenZhou
// �����
// maco
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "ͨ��");
	set("long", @LONG
һ����С��ͨ����ת�䴦��һ��С�š�
LONG
	);

	set("exits", ([
		"south" : __DIR__"jadehall2",
		"west" : __DIR__"jaderoom2",

	]));

	set("cost", 1);
	setup();
}
