// Code of ShenZhou
// Room: /d/newdali/wanrenzhong.c

inherit ROOM;

void create()
{
	set("short", "万人冢");
	set("long", @LONG
大唐天宝年间，两次出兵南诏，首次丧师六万，第二次丧师十万，连主将李
宓也死了。战后，阁逻风派人收集唐军阵亡将士遗骸，“祭而葬之”，名为“大
唐天宝战士冢”，当地人称之为“万人冢”。
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"chongs",
  "southwest" : __DIR__"southgate",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
