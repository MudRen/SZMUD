// Code of ShenZhou
// Room: /d/dali/dalicheng16.c

inherit ROOM;

void create()
{
	set("short", "��ͽ�");
	set("long", @LONG
����Ե������������ֹ��ӣ������۴��αȣ���������������һƬ̫ƽ����
����·���������Ŵ���������һ̤�����У�����軨�����˱Ƕ�����
LONG);
	set("exits", ([
		"north" : __DIR__"dalicheng17",
		"south" : __DIR__"dalicheng18",
		"west" : __DIR__"dalicheng12",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}









