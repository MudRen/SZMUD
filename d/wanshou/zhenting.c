// Code of ShenZhou
// /d/wanshou/zhenting.c
// snowbird July 1999
// 1.1.1.1

#include "room.h"

inherit ROOM;

void create()
{
        set("short", "ɽׯ����");
        set("long", @LONG
��ǰ��������ɽׯ����������������һ�ź��صİ���������
��������̫ʦ���ӣ���Ȼ��ɽׯ��λׯ��������֮��������һ
������һֻ�ͻ�����˯���ѣ��·����ڴ������������ѱ�޳���
����һ�����ң�����ǰ���Ǻ�����
LONG
        );
        set("exits", ([
		        "north" : __DIR__"houting",
				"south" : __DIR__"qianting",
                "east" : __DIR__"mishi",
                "west" : __DIR__"xunshouchang",
        ]));

	    set("cost", 0);
        setup();
        replace_program(ROOM);

}
