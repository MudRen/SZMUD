// Code of ShenZhou
// Room: /d/dali/road8.c

inherit ROOM;

void create()
{
	set("short", "太和东街");
	set("long", @LONG
太和街连贯阳苜咩城南北门，延伸三里，是城内主要街道。街面是由碗口大
的彩色石块铺成，青兰紫绿，煞是好看。城内居民族裔繁杂，习俗各异，饮食穿
着无不异于中原。北面是薛氏成衣铺，南面是药铺。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	set("cost", 1);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"chengyipu",
  "south" : __DIR__"yaopu",
  "east" : __DIR__"shipu.c",
  "west" : __DIR__"taihejie4",
]));

	setup();
	replace_program(ROOM);
}
