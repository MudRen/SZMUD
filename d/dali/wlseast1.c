// Code of ShenZhou
// Room: /d/dali/wlseast1.c
// AceP

inherit ROOM;

int do_drop(object);

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������һ��Сɽ�£�������ũ���������������Զ�������̣�
����ũ����������ҩ��
LONG );

	set("exits", ([
		"up"   : __DIR__"wlseast2",
		"west" : __DIR__"wlseast",
	]));

	set("objects", ([
		__DIR__"npc/snbz": 2,
		]));

	set("cost", 3);
	set("outdoors", "dali");
	setup();
}
