// Code of ShenZhou
// cangjing.c ��ɽ��
// qfy Nov 3, 1996

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��ɽ��");
	set("long", @LONG
���ǲؾ���󣬶���������С�š�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northeast" : __DIR__"chmiao",
		"southup" : __DIR__"cangjing",
	]));

        set("objects", ([ 
        ]));

	create_door("northeast", "С��", "southwest", DOOR_CLOSED);

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
