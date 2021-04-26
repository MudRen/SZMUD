// Code of ShenZhou
// jiangfu.c ʩ�Ž�����
// qfy Nov 3, 1996

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ʩ�Ž�����");
	set("long", @LONG
����һ�����ƻֺ�Ĵ�լԺ�������߶������ܶ�����������졣������
���Ϸ�����һ����ң������ĸ���������ġ�������������ǻ������֮լ��
����ʩ�Ž�������̨��Ĺ�����
LONG
        );

        set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"dxxiang",
		"south" : __DIR__"gtxiang",
		"north" : __DIR__"jiangfu1",
	]));

        set("objects", ([ 
		__DIR__"npc/wujiang" : 1,
                __DIR__"npc/bing" : 2,
        ]));

        set("no_clean_up", 0);

	set("cost", 1);
        setup();
}
int valid_leave(object me, string dir)
{
        if (objectp(present("guan bing", environment(me))) &&
                dir == "north")
                return notify_fail("�ٱ���ס�����ȥ·��\n");
	if (objectp(present("wu jiang", environment(me))) &&
                dir == "north")
                return notify_fail("�佫��ס�����ȥ·��\n");
        return ::valid_leave(me, dir);
}
