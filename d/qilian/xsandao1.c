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
			"southwest" : __DIR__"xsandao2",
			"east" : "/d/gaibang/undertre",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

