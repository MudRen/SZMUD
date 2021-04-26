// Code of ShenZhou
// Room: /city/beidajie1.c
// YZC 1995/12/04
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǽ�����������ĵط�����̯���и��ָ���������Ӧ�о��С����Ͽ�ͨ
�����ݳǵ����Ĵ�֡������¥��д�š��챦�󡱣����������Ƕ�����ǲ�ĺ�ȥ
����������һ��������¡�Ŀ�ջ�����Ը��ص����ǽ�����������˵Ҳ�������ǵ�
�Ļ�ص㡣
LONG
	);
	set("outdoors", "city");

        set("fanhua", 2);
	set("exits", ([
		"west" : __DIR__"kedian",
//                "wiz" : "/u/final/workroom",
		"south" : __DIR__"guangchang",
		"northwest" : __DIR__"majiu",
		"east" : __DIR__"tianbaoge",
		"north" : __DIR__"beidajie2",
	]));
	set("objects", ([
		__DIR__"npc/xunbu" : 1,
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

