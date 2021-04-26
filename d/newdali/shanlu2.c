// Code of ShenZhou
// Room: /d/dali/shanlu2.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
һ��ɽ·��������ï�ܵ����֣����������಻���Ĵ�ɽ��������һ���޼ʵ�
��˫���ɴ�ɭ�֣���˵��а�̽��������л����·���Լ��ɼ�һЩ����Ĵ�
��ɽ·ת�������š�
LONG);
	set("objects", ([
		__DIR__"npc/snbz": 1,
		]));
	set("exits", ([
		"northwest" : __DIR__"shanlu1.c",
		"eastdown" : __DIR__"shanlu3.c",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
