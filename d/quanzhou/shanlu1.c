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
		"southup" : __DIR__"qingyuan",
		"north" : __DIR__"qzroad5",
	]));

        set("objects", ([ 
                "/clone/beast/banjiu" : random(2), 
		"/d/gaibang/npc/shanzeitou" : 2,
		"/d/gaibang/npc/shanzei" : 1,
		"/d/gaibang/npc/shanzei2" : 1,
		"/d/gaibang/npc/shanzei3" : 1,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 2);
        setup();
	replace_program(ROOM);
}
