// Code of ShenZhou
// Room: didao_s.c �ص���
// Zhangchi 7/00

inherit ROOM;
#include "didao.h"

void create()
{
	set("short", "�ص�");
	set("long", @LONG
����һ���ո��ڳɵĵص������������������졣
LONG
	);
	set("exits", ([
		"north": __DIR__"didao1",
]));
	set("no_clean_up", 1);
	set("cost", 1);
	set("valid_dig","south");

	setup();
//	replace_program(ROOM);
}

void init()
{
	int num=get_room("south");
	if (num >= 1)
		set("exits/south",__DIR__"didao_s_1");
	else
		delete("exits/south");

	add_action("do_dig","wa");
	add_action("do_dig","dig");
}