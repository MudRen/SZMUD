// Code of ShenZhou
// chu@xkx 7/27/98

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǹ�ͷ�������������ֻ�����߸ߵĹ��ţ�������������̴ľ���ӣ���
���Ǹ�����ְλ�ϸߵ�����׼���ġ����ò�����һ�����ľ���Ƶķ��壬����д
�˲��ٶ�����
LONG
        );
        set("exits", ([
                "out" : __DIR__"ft_room1",
        ]));
	set("objects", ([
	    __DIR__"npc/ftb_zhu":1,
	]));
        set("cost", 1);
        set("no_fight", 1);
        set("invalid_startroom", 1);
        setup();
        "/clone/board/futou_b"->foo();
        replace_program(ROOM);
}
