// Code of ShenZhou
// �����
// maco
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
һ����������������ͨ����
LONG
        );

	set("exits", ([
		"eastup" : __DIR__"jaderoad8",
		"eastdown" : __DIR__"jaderoad10",
	]));

	set("cost", 1);
	setup();
}
