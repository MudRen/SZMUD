// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov91.c

inherit ROOM;

void create()
{
	set("short", "���ɴ���");
	set("long", @LONG
������ɽ�Ļ��£������˰�ʯȥ�����������޳�һ��һ�����״��ƽ̨����
�ӷֱ��ڸ���ƽ̨�ϣ��������ӣ�������ʯ��Χǽ�����е�·Ҳ��ʯͷ�̳ɡ�
LONG);
	set("exits", ([
		"north" : __DIR__"minov92",
		"south" : __DIR__"minov93",
		"westdown" : __DIR__"minov89",
		"eastup" : __DIR__"minov94",
		]));
	set("area", "��Ū��");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
