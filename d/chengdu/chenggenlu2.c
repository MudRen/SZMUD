// Room: /d/chengdu/chenggenlu2.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�Ǹ�·");
	set("long", @LONG
���ǿ����ɶ����ų�ǽ����һ��С·�����߲�Զ�����Ǳ���֡�
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
		"west" : __DIR__"chenggenlu1",
		"southeast" : __DIR__"chenggenlu3",
	]));

	setup();
	replace_program(ROOM);
}

