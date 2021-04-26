// Code of ShenZhou
// Room: /d/mingjiao/di.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "地字门");
	set("long", @LONG
此乃光明左使属下地字门。不大的厅中有一股肃杀威严之气。四周桌
上点着明晃晃的巨烛，正中摆着一张虎皮交椅。地字门教众出出进进，都
是屏息静气地低头走过。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"guangchang70",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
