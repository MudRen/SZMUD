//Cracked by Roath
// Room: /d/beijing/west/zhengyangdajie2.c

inherit ROOM;

void create()
{
	set("short", "ʮ��·��");
	set("long", @LONG
����һ��ʲ��Ҳû�еĿշ��䡣
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"yonganmen",
  "north" : __DIR__"zhengyangdajie",
  "east" : __DIR__"xitianmen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
