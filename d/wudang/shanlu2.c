// Code of ShenZhou
// shanlu1.c �䵱ɽ·
// by Fang 8/19/96

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
	�����ڵ�ɽ��·���ϣ�·�����Ҹ���һ����������������������ɽ��ɽ
��������ȥ����������ľ�е�����������Ļ�С�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"west" : __DIR__"shanlu1",
		"southup" : __DIR__"shanlu3",
	]));
	set("cost", 2);
	setup();
	replace_program(ROOM);
}

