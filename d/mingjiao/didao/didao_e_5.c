// Code of ShenZhou
// Room: didao_e_5.c �ص���
// Zhangchi 7/00

inherit ROOM;
#include "didao.h"

void create()
{
	set("short", "�ص�");
	set("long", @LONG
����һ���ո��ڳɵĵص����������Ѿ����˾�ͷ��
LONG
	);
	set("exits", ([
		"west": __DIR__"didao_e_4",
]));
	set("no_clean_up", 1);
	set("cost", 1);
	set("valid_dig","east");

	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_dig","wa");
	add_action("do_dig","dig");
}
