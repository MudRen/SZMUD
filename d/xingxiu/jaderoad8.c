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
		"westup" : __DIR__"jaderoad7",
		"westdown" : __DIR__"jaderoad9",
	]));

	set("cost", 1);
	setup();
}
