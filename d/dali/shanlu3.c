// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
һ��ɽ·��������ï�ܵ����֣����������಻���Ĵ�ɽ����·��
�Լ��ɼ�һЩ����Ĵ���ɽ·���������š�
LONG
	);

	set("exits", ([
		"north" : __DIR__"shanlu2.c",
		"southwest" : __DIR__"shanlu4.c",
		]));

	set("objects", ([
		__DIR__"npc/snbz": 1,
	]));

	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
