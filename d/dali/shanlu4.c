// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
һ��ɽ·��������ï�ܵ����֣����������಻���Ĵ�ɽ����·
���Լ��ɼ�һЩ����Ĵ���ɽ·���������š�
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"shanlu3.c",
		"southeast" : __DIR__"shanlu6.c",
		]));

	set("objects", ([
		__DIR__"npc/wujian": 1,
	]));

	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
