// Room: /d/chengdu/chenggenlu3.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�Ǹ�·");
	set("long", @LONG
���ǳɶ�������ǽ����һ��С·��С·�������߲�Զ���۶��������ڶ���
�߲�Զ���۶����ϡ�
LONG
	);
        set("outdoors", "chengdu");
        set("cost", 1);
	set("exits", ([
		"northwest" : __DIR__"chenggenlu2",
		"southeast" : __DIR__"chenggenlu4",
	]));

	setup();
	replace_program(ROOM);
}

