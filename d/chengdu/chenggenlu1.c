// Room: /d/chengdu/chenggenlu1.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�Ǹ�·");
	set("long", @LONG
���ǿ����ɶ����ų�ǽ����һ��С·�����������ϣ��������ᶽ����
LONG
	);
        set("outdoors", "chengdu");

	set("exits", ([
		"east" : __DIR__"chenggenlu2",
		"west" : __DIR__"tidugate",
	]));

	setup();
	replace_program(ROOM);
}

