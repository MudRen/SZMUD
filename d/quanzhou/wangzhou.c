// Code of ShenZhou
// wangzhou.c ����ͤ
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����ͤ");
	set("long", @LONG
����ĵ��ƻ�Ȼ���ʣ��������ʯ������������ͷ�������ʳơ���ʯ����
������ǰ̽�����ƺ�Ҳ�ڼ����½��������ʯ��һͤͻأ���������ʣ��ֳ�
������ͤ����ƾ��Զ����Ȫ��ȫ���������۵ס�
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"northdown" : __DIR__"ruixiang",
		"southdown" : __DIR__"shanlu4",
	]));

        set("objects", ([ 
                __DIR__"npc/jiarenda" : 1,
        ]));


	set("outdoors", "quanzhou");

	set("cost", 1);
     set("fjing", 1);
        setup();
	replace_program(ROOM);
}
