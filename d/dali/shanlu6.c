// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
һ��ɽ·��������ï�ܵ����֣����������಻���Ĵ�ɽ��������һ
���޼ʵ���˫���ɴ�ɭ�֣���˵��а�̽��������л����·���Լ��
�ɼ�һЩ����Ĵ���ɽ·ת�������š�
LONG
	);

	set("exits", ([
		"northwest" : __DIR__"shanlu4.c",
		"east" : __DIR__"shanlu7.c",
		]));

	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
