//Cracked by Roath
// Room: /d/beijing/zijincheng/neizuomen.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����ͨ������������Ҫ�Ż�,�ɴ������ǻʵۺͺ����Ǿ�ס�ĵط�.
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"rijingmen",
  "north" : __DIR__"tongdao4",
  "east" : __DIR__"zhaigong",
  "southwest" : __DIR__"qianqingmen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
