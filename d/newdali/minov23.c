// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov23.c

inherit ROOM;

void create()
{
	set("short", "ũ��");
	set("long", @LONG
�����Ѿ���ƽԭ�ľ�ͷ����������վ���ɽ���ˣ�һЩ��ũ�����٤������
�ķ������ǵطֲ���ɽ���£�һЩ�����������������������·�򶫱���ɽ����
�Ѷ�ȥ��
LONG);
	set("objects", ([
		__DIR__"npc/bynong.c" : 1,
		]));
	set("exits", ([
		"northeast" : __DIR__"minov24",
		"west" : __DIR__"minov20",
		]));
	set("area", "��٤��");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
