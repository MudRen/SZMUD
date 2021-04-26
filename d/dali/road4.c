// Code of ShenZhou

inherit ROOM;

void create()
{
	set("short", "太和南街");
	set("long", @LONG
    太和街连贯阳苜咩城南北门，延伸三里，是城内主要街道。街面是由碗口大
的彩色石块铺成，青兰紫绿，煞是好看。城内居民族裔繁杂，习俗各异，饮食穿
着无不异于中原。
    西面是清池，东面是兵营。
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");

	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
