// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov2.c

inherit ROOM;

void create()
{
	set("short", "ɽ��С��");
	set("long", @LONG
������Դɽ������ʯС�����������ѣ�������ľïʢ��������ա�������Ҷ��
����ϡ�ɡ������ౡ�����ϰϰ��
LONG);
	set("exits", ([
		"westdown" : __DIR__"minov1",
		"east" : __DIR__"minov4",
		]));
	set("area", "���ˮ�ٲ�");
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
