//Cracked by Roath
// Room: /d/beijing/zijincheng/jingrengong.c

inherit ROOM;

void create()
{
	set("short", "���ʹ�");
	set("long", @LONG
������֮һ�������������������Ǿ�ס�ĵط���
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"tongdao4",
  "south" : __DIR__"chengsudian",
  "east" : __DIR__"gzxd8",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
