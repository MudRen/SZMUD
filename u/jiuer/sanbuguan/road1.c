// Craked by shenzhou
// Room: /d/sanbuguan/road1.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���");
        set("long", 
"������һ����ֱ����ʯ����ϡ�����ͨ���ϵ�һ�������ݳǣ���
���˽�����������ԶԶ�����Ѿ��ܿ��������Ͽ��ŵ���������"+HIW"�����š�"NOR+"��\n"
        );
        set("exits", ([
			"east" : "/d/city/ximen",
			"west" : __DIR__"road2",
			]));

		set("no_clean_up", 0);
		set("outdoors", "sanbuguan");

		set("cost", 1);
		setup();
		replace_program(ROOM);
}

