// Code of ShenZhou
// shanlu.c �䵱ɽ·
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
		"southup" : __DIR__"taizipo",
		"northup" : __DIR__"haohanpo",
                "east": __DIR__"mozhen",
	]));
	set("cost", 1);
	setup();
	replace_program(ROOM);
}

