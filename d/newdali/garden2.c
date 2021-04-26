// Code of ShenZhou
// Room: /d/dali/garden2.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", RED"�軨԰"NOR);
	set("long", @LONG
�⻨԰��ˮ��һ�Ŵ���֮��һ�ԴԻ���ӳˮ���죬������ϼ��һ����ȥ��
���Ǻ���ͷ׵Ĳ軨�����ƺ��������������޼�Ʒ��
LONG);
	set("exits", ([
		"northwest" : __DIR__"garden4.c",
		"northeast" : __DIR__"garden3.c",
		"out" : __DIR__"garden1.c",
		]));
 	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
