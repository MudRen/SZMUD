// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov57.c

inherit ROOM;

void create()
{
	set("short", "���ɵ�");
	set("long", @LONG
���������ķ�֧�����������۾ӵ����ӣ����������ɵ�����ݡ�������Ϫ��
������ˮ������ı��������ũҵ��Թ������������Ϸ�����о���Щ��ª��
��ӣ�Ҳ�������̹�����
LONG);
	set("objects", ([
		__DIR__"npc/wygirl" : 1,
		]));
	set("exits", ([
		"northwest" : __DIR__"minov58",
		"southup" : __DIR__"minov44",
		"west" : __DIR__"minov54",
		]));
	set("area", "��³��");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
