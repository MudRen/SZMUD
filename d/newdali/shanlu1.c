// Code of ShenZhou
// Room: /d/dali/shanlu1.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
һ��ɽ·��������ï�ܵ����֣����������಻���Ĵ�ɽ����·���Լ��ɼ�
һЩ����Ĵ���ɽ·���������š�
LONG);
	set("objects", ([
		__DIR__"npc/wujian": 1,
		]));
	set("exits", ([
		"northwest" : __DIR__"minov46",
		"northeast" : __DIR__"minov43",
		"southeast" : __DIR__"shanlu2",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
