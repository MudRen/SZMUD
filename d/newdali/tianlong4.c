// Code of ShenZhou
// Room: /d/dali/tianlong4.c

inherit ROOM;

void create()
{
	set("short", "ɮ��");
	set("long", @LONG
һ���յ����ķ��䣬�Ľ������ĸ���ɮ���ڱ�Ŀ��˼��
����ǽ����һ�����š�
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"tianlong3.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
