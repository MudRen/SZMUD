// Code of ShenZhou
// Room: /d/dali/wangfuroad1.c

inherit ROOM;

void create()
{
	set("short", "�·");
	set("long", @LONG
ֻ�����ߴ����·�������²�̦�������м���һ��ʯ����
���·��
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"wangfu4.c",
  "east" : __DIR__"wangfuroad2.c",
]));
	set("no_clean_up", 0);
set("wangfu", 1);

	setup();
	replace_program(ROOM);
}
