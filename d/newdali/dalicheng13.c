// Code of ShenZhou
// Room: /d/dali/dalicheng13.c

inherit ROOM;

void create()
{
	set("short", "��ͽ�");
	set("long", @LONG
����һ����ʯ��·���������˲��ٰ������Ե�ׯ�����¡������Ǵ���ǵ���
��פ�أ���������������ʿ�ǲ����ĺ�������������˾�����ǵ����̫������
һ�����Ϯ���š�
LONG);
	set("exits", ([
		"north" : __DIR__"tusi1",
		"south" : __DIR__"dalicheng14",
		"east" : __DIR__"dalicheng12",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
