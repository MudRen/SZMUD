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
            "northup" : __DIR__"wangzhou",
            "southup" : __DIR__"cien",
	]));

        set("objects", ([ 
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 2);
        setup();
	replace_program(ROOM);
}
