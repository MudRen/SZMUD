// Code of ShenZhou
// shanlu3.c �䵱ɽ· 
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
		"northdown" : __DIR__"shanlu2",
		"southup" : __DIR__"taiziyan",
	]));
	set("cost", 2);
	setup();
	replace_program(ROOM);
}

