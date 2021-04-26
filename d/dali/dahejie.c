// Code of ShenZhou
// Room: /d/dali/dahejie.c

inherit ROOM;

void create()
{
	set("short", "��ͽ�");
	set("long", @LONG
����һ����ʯ��·���������˲��ٰ������Ե�ׯ�����¡�������
����ǵ��ؾ�פ�أ���������������ʿ�ǲ����ĺ�������������˾
�����ǵ����̫������һ�����Ϯ���š�
LONG
	);
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	set("exits", ([
		"north" : __DIR__"tusi1",
		"south" : __DIR__"bingying.c",
		"east" : __DIR__"crossing.c",
		]));

	setup();
}
