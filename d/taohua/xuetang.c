// Code of ShenZhou
// xuetang.c ѧ��

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "�һ�ѧ��");
        set("long", @LONG
�����������ǻƵ����ļ��͡�ǰ����ĸ�����ʣ��뵺��ɥ�ոջ�������ҩʦ��
��һƬ���Ķ�����ִ��ˣ����������һ����Ͽ��ݽ��顣�һ���������Ҳ����
�һ�����ѧЩ�Ļ���
LONG
        );

        set("exits", ([
                "east" : __DIR__"bibochi",
        ]));

	set("objects",([
                __DIR__"npc/xueshi" : 1,
        ]));

	set("cost", 1);
        setup();
}

int valid_leave(object me, string dir)
{
        me->set_temp("mark/��", 0);
        return 1;
}
