// Room: /d/chengdu/chenggenlu5.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�Ǹ�·");
	set("long", @LONG
���ǿ����ɶ����ų�ǽ����һ��С·�����������������ϱ��Ƕ���֡�
LONG
	);
        set("outdoors", "chengdu");
        set("cost", 1);
	set("exits", ([
		"north" : __DIR__"chenggenlu4",
		"south" : __DIR__"dadongmen",
	]));

	setup();
	replace_program(ROOM);
}

