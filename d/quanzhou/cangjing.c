// Code of ShenZhou
// cangjing.c �ؾ���
// qfy Nov 3, 1996

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�ؾ���");
	set("long", @LONG
�ؾ����ǿ�Ԫ�µ���ߴ�������һ��Сɽ���ϡ�������㣬������һС��
���ա��Ǹ�ƾ������˫����գ���̳���أ��ĸ�ʫ�⡣���ϲؾ������
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"southdown" : __DIR__"ganlu",
		"northdown" : __DIR__"houshan",
	]));

        set("objects", ([ 
		__DIR__"npc/monk" : 1,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 0);
        setup();
	replace_program(ROOM);
}
