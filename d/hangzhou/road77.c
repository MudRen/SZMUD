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
������������ϱ����ߣ������ǻ���Ȫ��������һ��ɽ·��
LONG	);

    set("exits", ([ /* sizeof() == 4 */ 
                   "north" : __DIR__"road76", 
                   "south" : __DIR__"road78", 
                   "west" : __DIR__"hupao1", 
                   "east" : __DIR__"yuhuang5", 
                 ])
       );
	set("objects",([
                "/d/taishan/npc/tiao-fu" : 1,
        ]));
	set("cost", 1);
        set("outdoors", "hangzhou");
    setup();
    replace_program(ROOM);
}
