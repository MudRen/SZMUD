// Code of ShenZhou
// Room: /d/dali/dalicheng12.c

inherit ROOM;

void create()
{
	set("short", "ʮ��·��");
	set("long", @LONG
���Ǵ�����ڵ���Ҫ��ó����������ɫɫ�Ľ������ڶ��ߴ���˷������಻
����·�ϳ�ˮ��������ɫ����Ħ����࣬���ַǷ���������Ը���������¥�ƣ�
���������־���פ�أ�����������ӡ�
LONG);
	set("exits", ([
		"north" : __DIR__"dalicheng9",
		"south" : __DIR__"southgate",
		"west" : __DIR__"dalicheng13",
		"east" : __DIR__"dalicheng16",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}








