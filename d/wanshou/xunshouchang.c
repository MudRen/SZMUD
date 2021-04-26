// Code of ShenZhou
// /d/wanshou/xunshouchang.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "ѱ�޳�");
        set("long", @LONG
���������ɽׯ��ѱ�޳����㳡�쳣����������ʮͷҰ����
Ϸ�����ţ��������쳾������������ɽׯ���Ӵ������Ƶ�ţƤ��ñ
������Ұ���м䡣ѱ�޳�����һ��С����ͨ��ɽׯ��������֣���
�����л�Х�������ﴫ����
LONG
        );
        set("exits", ([
		        "north" : __DIR__"shulin",
				"east" : __DIR__"zhenting",
        ]));

        set("outdoors", "wanshou-shanzhuang");

        set("objects", ([
                __DIR__"npc/bowei" : 1,
        ]));

	    set("cost", 1);
        setup();
        replace_program(ROOM);

}
