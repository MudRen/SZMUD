// Code of ShenZhou
// Room: /d/gaibang/xcandao2.c
// Date: Haa 96/03/22

#include <room.h>
inherit ROOM;




void create()
{
	set("short", "����");
	set("long", @LONG
����ؤ�� �������ܵĵ���ͨ��������ؤ�Ｘ����֮��Ѫ��ɡ� 
LONG
	);

	set("exits", ([
			"north" : __DIR__"underxc",
			"south" : __DIR__"xcandao1",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}



