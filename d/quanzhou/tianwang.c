// Code of ShenZhou
// tianwang.c ������
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "������");
	set("long", @LONG
����ɽ�ż�����������������������һ��ŭĿͦ����״�����͡���
������һƬ���Ĵ�ʯͥ��ͨ������Ĵ��۱��
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"north" : __DIR__"dxbaodian",
		"south" : __DIR__"kaiyuan",
	]));

        set("objects", ([ 
		__DIR__"npc/monk" : 1,
        ]));

        set("no_clean_up", 0);

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
