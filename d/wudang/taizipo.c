// Code of ShenZhou
// taizipo.c �䵱̫����
// by Fang 8/19/96

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", YEL"̫����"NOR);
	set("long", @LONG
	�˴��ش�����֮����������Ҫ������̫���£�����һ���ˮܽ�أ�ӿ��
�̲�����������������Զ�����·ת���������𣬾�������֮�С�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southdown" : __DIR__"shiliang",
		"northdown" : __DIR__"shanlu",
                "east" : __DIR__"wuceng",
	]));

	set("cost", 3);
        set("fjing", 2);
	setup();
	replace_program(ROOM);
}

