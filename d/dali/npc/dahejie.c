// Code of ShenZhou
// Room: /d/newdali/dahejie.c

inherit ROOM;

void create()
{
	set("short", "��ͽ�");
	set("long", @LONG
����һ����ʯ��·���������˲��ٰ������Ե�ׯ�����¡������Ǵ����
���ؾ�פ�أ���������������ʿ�ǲ����ĺ�������������˾�����ǵ����
̫������һ�����Ϯ���š�
LONG	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"tusi1",
  "south" : __DIR__"bingying.c",
  "east" : __DIR__"crossing.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}








