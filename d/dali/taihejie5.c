// Code of ShenZhou
// Room: /d/newdali/taihejie5.c

inherit ROOM;

void create()
{
	set("short", "太和街口");
	set("long", @LONG
太和街连贯阳苜咩城南北门，延伸三里，是城内主要街道。街面
是由碗口大的彩色石块铺成，青兰紫绿，煞是好看。城内居民族裔繁
杂，习俗各异，饮食穿着无不异于中原。太学生们的朗朗之声透室可
闻。西面是平南王府，东面是定安府。北面出城门有官道通中原。
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([
		"south" : __DIR__"taihejie4.c",
		"north" : __DIR__"northgate.c",
//		"enter" : __DIR__"taixueyuan",
		"west" : __DIR__"wangfu1.c",
		"east" : __DIR__"dinganfu.c",
		]));

	set("no_clean_up", 0);

	set("objects", ([
//		__DIR__"npc/collector" : 1,
		]));

	setup();
}







