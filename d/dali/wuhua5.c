// Code of ShenZhou
// Room: /d/dali/wuhua5.c

inherit ROOM;

void create()
{
	set("short", "贵宾室");
	set("long", @LONG
这是一间贵宾室，这里窗明几亮，用具考究。单是窗边一架
紫竹软榻已是价值不菲。凭窗眺望，隐隐于淡烟之中可见苍山?
玉局峰，只见山势清秀，翠碧欲滴，令人心旷神怡。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"wuhua6.c",
]));
	set("no_clean_up", 0);
set("cost", 1);

	setup();
	replace_program(ROOM);
}
