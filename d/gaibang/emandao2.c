// Code of ShenZhou
// Room: /d/gaibang/wdandao1.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����ؤ�Ｋ�����ܵĵ���ͨ��������ؤ�Ｘ����֮��Ѫ��ɡ� 
LONG
	);

	set("exits", ([
			"west" : __DIR__"underem",
			"northeast" : __DIR__"emandao1",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}



