// Code of ShenZhou
// xiqiao.c ���ŵ���
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���ŵ���");
	set("long", @LONG
����Ȫ�������һ�����ţ��Ӱ��Ž��Ӷ����ĳ�¥����������������άϵ��
  �ճ����µ��ţ�������𡣹������������߿ɴ����Ϲ㶫��
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"citong_w2",
		"west" : "/d/foshan/qzroad7",
	]));

        set("objects", ([ 
		__DIR__"npc/xunbu" : 1,
        ]));

        set("no_clean_up", 0);
	set("outdoors", "quanzhou");

	set("cost", 1);
        setup();
	replace_program(ROOM);
}
