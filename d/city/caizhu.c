// Code of ShenZhou
// Room: /city/caizhu.c
// YZC 1995/12/04 
// Jay 2/3/97 redesign

inherit ROOM;

void create()
{
	set("short", "���ָ���");
	set("long", @LONG
һ�������ûʵĴ�լԺ����������ǰ����ͷ�ߴ��ʯʨ�������ڴ������࣬
�����ϵ��������������������һ���ң����顰���ָ����������֡�Ѱ������
��ʿ��������ȥ������͵͵̧��������������ʱ���������͵Ĵ��ǹ�������
������˹�����
LONG
	);

	set("exits", ([
		"south" : __DIR__"xidajie3",
		"north" : __DIR__"dayuan1",
	]));

	set("objects", ([
		__DIR__"npc/wolfdog" : 2,
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

