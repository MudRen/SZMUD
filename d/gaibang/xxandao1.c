// Code of ShenZhou
// Room: /d/gaibang/xxandao1.c
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
			"west" : __DIR__"xxandao2",
			"east" : __DIR__"undertre",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}



