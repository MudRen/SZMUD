// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��Ƿһ¥");
        set("long", @LONG
�����Ǹ������ľ����������Ǽ�ľ���ı��������������ű��¾�
�ɵĹ��Ƽ�����ɫ���������ƿ����Ե�ׯ�Ϻ�����¥���Ƿ������޹���Ѱ��
ɮ�²���׼���ǲ�����ȥ�ġ����˰�Ƿ���Ǻ�Ժ�ˡ�
LONG
        );
        set("exits", ([
                "up" : __DIR__"angqian2",
                "south" : __DIR__"houyuan",
        ]));
	set("objects", ([
                __DIR__"npc/jiamu" : 1,
        ]));

	set("cost", 1);
        setup();
        replace_program(ROOM);
}
