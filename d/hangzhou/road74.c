// Code of ShenZhou
// ��ʯ���
// Dong  11/03/1996.
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{   set("short", "��ʯ���");
    set("long", @LONG
��������ˣ����У���ýΣ�����������ϲ�������������
����������򶫺��������ߣ���������һ�������
LONG	);

    set("exits", ([ /* sizeof() == 3 */ 
                   "north" : __DIR__"road54", 
                   "southwest" : __DIR__"road75", 
                   "east" : __DIR__"road73", 
                 ])
       );
	set("objects",([
                "/d/taishan/npc/dao-ke" : 1,
        ]));
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
