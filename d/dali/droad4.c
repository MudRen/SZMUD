// Code of ShenZhou
// Room: /d/newdali/droad4.c

inherit ROOM;

void create()
{
	set("short", "林间小道");
	set("long", @LONG
这是一条卵石铺成的小道，曲曲折折地通向前方。两边是密密的树林这里
人迹罕至，惟闻足底叩击路面，微风吹拂树叶，沙沙作响。
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"ling",
  "west" : __DIR__"southgate",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
