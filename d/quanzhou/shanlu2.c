// Code of ShenZhou
// shanlu1.c ɽ·
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ɽ·");
	set("long", @LONG
������Դɽ������ʯС�����������ѣ�������ľïʢ��������ա�������
Ҷ������ϡ�ɡ������ౡ�����ϰϰ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
		"westup" : __DIR__"liandan",
		"northup" : __DIR__"huru",
		"southdown" : __DIR__"shanlu3",
	]));

	set("objects", ([ 
		__DIR__"npc/dog" : 1,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 2);
        setup();
	replace_program(ROOM);
}
