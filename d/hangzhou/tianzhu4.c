// Code of ShenZhou
// ����ɽ·
// Dong  11/03/1996.
// modified by aln 2 / 98

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
СϪ���ɽ·����Ϫ��һ��Сʯ�š�Ϫ��ũ��С������Ϸ���֡�
���ϱ㵽�������á����¾��������á�
LONG
        );

        set("exits", ([ /* sizeof() == 2 */ 
                "southup" : __DIR__"tianzhu5", 
                  "northdown" : __DIR__"tianzhu3", 
        ]));

	set("objects", ([
                "/d/village/npc/boy" : 1,
        ]));

	set("cost", 2);
        set("outdoors", "hangzhou");

        setup();

        replace_program(ROOM);
}
