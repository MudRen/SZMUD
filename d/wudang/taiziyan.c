// Code of ShenZhou
// taiziyan.c  ̫����
// by Fang 8/19/96

inherit ROOM;

void create()
{
	set("short", "̫����");
	set("long", @LONG
	������Ⱥɽ�����е�̫���ң�������һ������ʯ��һ��̫��ͤ��
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"shanlu3",
		"southdown" : __DIR__"langmei",
	]));
	set("cost", 3);
        set("fjing", 1);
	setup();
	replace_program(ROOM);
}

