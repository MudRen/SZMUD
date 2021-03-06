// Code of ShenZhou
// Room: /d/dali/quan2.c

inherit ROOM;

void create()
{
	set("short", "蝴蝶泉");
	set("long", @LONG
蝴蝶泉就显得更加清凉湿润，大量的蝴蝶，从四面八方，汇集在树荫下，
花丛中，翩翩起舞，成千上万只彩蝶，欢聚一处，使这里变得花团锦簇。特
别是在蝴蝶泉上，顺着那倒垂的扬柳，无数蝴蝶，一只咬着一只的尾部，形
成千百个蝶串，人来不惊，投石不散，构成令人惊叹的奇观。
LONG
	);
	set("no_clean_up", 0);
       set("fjing", 1);
	set("outdoors", "dali");
	set("cost", 1);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yuxuguan1",
  "east" : __DIR__"quan1",
]));

	setup();
	replace_program(ROOM);
}
