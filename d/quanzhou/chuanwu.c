// Code of ShenZhou
// chuanwu.c ����
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
�������Ƽ���ȫ����õ��촬��ʦ�͹�����һ����ȥ���������깤�ͼ���
�깤�ĸ�����;�����ִ�С��ľ������������ææµµ��һƬ��æ����
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"gangkou2",
	]));

        set("objects", ([ 
		__DIR__"npc/kuli" : 2,
        ]));

        set("no_clean_up", 0);

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
