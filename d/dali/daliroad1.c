// Code of ShenZhou
// daliroad1.c
// by Lyu

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С�����ͨ�����
LONG
	);
        set("outdoors", "dali");

	set("exits", ([
		"west" : __DIR__"eastgate",
		"east" : __DIR__"daliroad2",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

