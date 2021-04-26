// Code of ShenZhou

inherit ROOM;

void create()
{
	set("short", "感通寺");
	set("long", @LONG
    感通寺，又名荡山寺。山寺前满坡茶园，清翠碧绿，清香扑鼻。感通茶，在
南诏时代就有种植。举首看苍山，峰峦挺秀，感通寺一片，苍松古柏相间。
LONG
	);
	set("cost", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
