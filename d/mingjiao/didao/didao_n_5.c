// Code of ShenZhou
// Room: didao_n_5.c �ص���
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
		"south": __DIR__"didao_n_4",
]));
	set("no_clean_up", 1);
	set("cost", 1);
	set("valid_dig","north");

	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_dig","wa");
	add_action("do_dig","dig");
}

