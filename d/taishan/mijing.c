// Code of ShenZhou
// mijing2.c �ܾ�
// qfy July 10, 1996

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "�ܾ�");
        set("long", @LONG
һ��խ�����ܾ��������ʯ���롣ͷ���Ϲ��ߴ���ʯ�ķ�϶��Ͷ�룬
�������ܲ�����̫������֪�ܾ�ͨ���δ���
LONG
        );

	set("exits", ([
                "out" : __DIR__"shixin",
		"north" : __DIR__"dongqian",
        ]));

	set("cost", 2);
        setup();
}
