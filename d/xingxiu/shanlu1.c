// Code of ShenZhou
// shanlu1.c
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "ɽ·");
	set("long", @LONG
����ɽʯ���࣬��·���ۣ�����һ����ɫɽ��ΡȻ������
LONG
	);

	set("exits", ([
		"east" : __DIR__"caoyuan5",
		"west" : __DIR__"shanlu2",
	]));
	set("outdoors","xingxiu");
	set("cost", 3);
	setup();
	replace_program(ROOM);
}

