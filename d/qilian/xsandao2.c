// Code of ShenZhou
// Room: /d/gaibang/xsandao1.c
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
			"out" : __DIR__"underxs",
			"northeast" : __DIR__"xsandao1",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}



