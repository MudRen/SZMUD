// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov50.c

inherit ROOM;

void create()
{
	set("short", "����ɽ����");
	set("long", @LONG
�����Ǹ���ɽ�Ķ��£��򶫸��ӱ��ʶ����Ķ���ˮ��ԶԶ���������Եı�
��ѩɽ����ȥ������ȫ�ǳ�ɽ���룬����ϡ�١�ɽ�������޶࣬����������˾�
����ɽ���ԡ�
LONG);
	set("objects", ([
		__DIR__"npc/goat" : 1
		]));
	set("exits", ([
		"eastdown" : __DIR__"minov49",
		"west" : __DIR__"minov51",
		]));
	set("area", "��ˮ�ذ�");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
