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
����������ȥ��Ȫ�µ�·������������򶫱ߺ����ϱߡ�
LONG);

    set("exits", ([ /* sizeof() == 4 */ 
                   "east" : __DIR__"road14", 
                   "westup" : __DIR__"yuquan", 
                   "southwest" : __DIR__"road31", 
                   "south" : __DIR__"road51", 
                 ])
        );
	set("objects", ([
                "/d/taishan/npc/tiao-fu" : 1,
		"/d/taishan/npc/dao-ke" : 1,
        ]));
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
