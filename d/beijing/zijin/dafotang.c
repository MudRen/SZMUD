//Cracked by Roath
// Room: /d/beijing/zijincheng/dafotang.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����ã���һ���˼ҵķ���Ҫ��Ķࡣ����һ�����ǰ
����ֻ�㰸��������ż����㡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"cininggong",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
