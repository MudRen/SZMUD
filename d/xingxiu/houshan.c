// Code of ShenZhou
// houshan.c �������ɽ
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "��ɽС·");
	set("long", @LONG
���ǰ�����µ�С·�������ɴ˴�����������С�
LONG
	);

	set("exits", ([
		"east" : __DIR__"gucheng5",
		"west" : __DIR__"caoyuan1",
	]));
	set("outdoors","xingxiu");
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

