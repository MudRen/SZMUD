// Code of ShenZhou
// luanshi.c ��ʯ��
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ʯ��");
	set("long", @LONG
������ľ��ɭ����ʯ��ᾣ��¶����������Ҫ�������������̾ݵĵط���
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"south" : __DIR__"shisun",
	]));

        set("objects", ([ 
		__DIR__"npc/tufeitou" : 1,
		__DIR__"npc/tufei1" : 1,
		__DIR__"npc/tufei2" : 2,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 2);
        setup();
	replace_program(ROOM);
}
