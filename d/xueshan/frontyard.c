// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "ǰԺ");
        set("long", @LONG
ǰԺ�����߼䣬���й��������޸ɲ��������ǹۿ��������ַ����
�ۿ�����֮�ء�ǰԺ�������д�������һ����ʮ�������澡�ǲʻ�𴫹���
ͼ���������Ϸ��ǿ�ȸ���������һ���������Ϸ��Ǵ�㳡��
LONG
        );
        set("exits", ([
                "north" : __DIR__"yanwu",
		"northup" :__DIR__"kongque",
                "east" : __DIR__"tower",
		"west" : __DIR__"frontyard2",
		"south" :__DIR__"guangchang",
        ]));

	set("objects", ([
		__DIR__"npc/fsgelun" : 2,
		__DIR__"obj/jitan" : 1,
	]));

	set("cost", 1);
        setup();
        set("outdoors","qilian-shan");
}
int valid_leave(object me, string dir)
{
	object ob;
	ob=(present("fa tan", (environment(me))));
        if ( me->query("name") == ob->query("pending")
	&& ob->query("burning"))
                return notify_fail("�㷨��û��������ߣ�\n");
	return ::valid_leave(me, dir);
}
