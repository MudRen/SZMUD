// Code of ShenZhou
// Room: /d/gaibang/undertree.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;




void create()
{
	set("short","��������");
	set("long", @LONG
����ؤ����Ҫ�ܵ�֮һ���ɴ���������ֱ���������ܹ��߻谵��
�ƺ��м����ڰ��Ķ���������ߡ����µ�������������������ȥϤϤ
�������졣
LONG
	);

	set("exits", ([
		"up" : __DIR__"pomiao",
		"southwest":__DIR__"zlandao2",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}



