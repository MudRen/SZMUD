// Code of ShenZhou
// xiaojing2.c С��
// qfy July 12, 1996

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
һ��������С����Զ�������ͱڣ��羰���ѡ�
LONG
        );

	set("exits", ([
		"east" : __DIR__"dongqian",
		"west" : __DIR__"qiaobi0",
        ]));

	set("cost", 1);
        setup();
}

void init()
{
	this_player()->set_temp("marks/С", 1);
}
