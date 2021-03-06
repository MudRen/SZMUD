// Code of ShenZhou
// Room: /d/newdali/riverbank.c

inherit ROOM;

void create()
{
	set("short", "金汁河畔");
	set("long", @LONG
这里位处金汁河畔，原本建有一座地藏寺，如今寺院早废。唯有一座
石刻经幢(jinzhuang)半埋土中。此幢为方锥状，七层石雕。高约丈五尺，
基座为八角形的磐石，边上刻有莲花；层与层之间有界石。即是本层之盖
檐，又是上层之基石。
LONG
	);
	set("cost", 1);
       set("fjing", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"road7",
  "east" : __DIR__"dian2",
  "enter" : __DIR__"tower1",
]));
       set("objects", ([ /* sizeof() == 1 */
  "/d/dali/npc/sengren" : 2,
]));

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
