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
                "east" : __DIR__"xiaolu9",
                "north" : __DIR__"xiaolu7",
                "west" : __DIR__"xiaolu10",
		"south" :__DIR__"danfeng",
        ]));


	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
}
int valid_leave(object me, string dir)
{
        if( random((int)me->query_skill("dodge")) <= 30)
        {
                me->receive_damage("jingli", 50);
                me->receive_wound("qi",  10);
		me->move(__DIR__"aili");
		message("vision", me->query("name") + "����������˹�����\n",environment(me), me);
                return notify_fail("�����Ժ�����֪�������߽�����ɳ��\n");
        }
	return ::valid_leave(me, dir);
}
