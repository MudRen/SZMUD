//Cracked by Roath
// Room: /d/beijing/zijincheng/cininghu.c

inherit ROOM;

void create()
{
	set("short", "������԰");
	set("long", @LONG
����һ����԰���м���̫�����ڽ���������Ʒ�ֺܶ࣬ÿ�괺
���������ٻ���ţ�ɷ�Ǻÿ����Ա���һ�Ż��ܡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ciningmen",
  "east" : __DIR__"zaobanchu",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
