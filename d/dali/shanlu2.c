// Code of ShenZhou
// AceP

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
һ��ɽ·���������ï�ܵ����ֺ����಻���Ĵ�ɽ����·���Լ�
��ɼ�һЩ����Ĵ�������һƬ��ɽ�������ƣ�ɽ�߰�ѩ��������
��������·������ɽ��һ����·���������š�
LONG
	);

	set("exits", ([
		"east" : __DIR__"shanlu1.c",
		"westup" : __DIR__"minov49.c",
		"south" : __DIR__"shanlu3.c",
		]));


	set("cost", 2);
	set("outdoors", "dali");
	setup();
}
