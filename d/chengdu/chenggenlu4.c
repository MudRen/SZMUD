// Room: /d/chengdu/chenggenlu4.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�Ǹ�·");
	set("long", @LONG
���ǿ����ɶ����ų�ǽ����һ��С·���ϱ߲�Զ�����Ƕ���֡�
LONG
	);
        set("outdoors", "chengdu");
        set("cost", 1);
	set("exits", ([
		"northwest" : __DIR__"chenggenlu3",
		"south" : __DIR__"chenggenlu5",
	]));

	setup();
	replace_program(ROOM);
}

