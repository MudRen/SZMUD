// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "��С·");
        set("long", @LONG
��ǰ��һ��һ����С·���ش�Խ��ԽƫƧ��·��Խ��Խ���ء�
LONG
        );
        set("exits", ([
                "east" : __DIR__"xiaolu"+(random(5)+4),
                "north" : __DIR__"xiaolu6",
                "west" : __DIR__"xiaolu7",
		"south" :__DIR__"danfeng",
        ]));


	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
}
int valid_leave(object me, string dir)
{
                me->move(__DIR__"aili");
		message("vision", me->query("name") + "����������˹�����\n", environment(me), me);
		return notify_fail("�����Ժ�����֪�������߽�����ɳȺ�� \n");
}
