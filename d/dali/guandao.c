// Code of ShenZhou
// Room: /d/dali/guandao.c

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
你走在一条青石官道上，这里已经是南诏境内了，路上时时可以
看到各色各样的商人来来往往，络驿不绝。路边站了些个衣饰华艳的
摆夷女子，其中一个身穿白衣的显得格外秀丽。此去向南即是大理国
北关口太和城，沿官道向东北可达中原。
LONG
	);
	set("outdoors", "dali");
	set("no_clean_up", 0);
	set("cost", 2);
	set("objects", ([
		__DIR__"npc/baiyi" : 1,
		]));

	set("exits", ([
		"northeast" : "/d/dali/guandao5",
		"south" : __DIR__"nanbei",
		]));

	setup();
}
