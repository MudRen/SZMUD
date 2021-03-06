// Code of ShenZhou
// Room: /d/xixia/ypshui.c

inherit ROOM;

void create()
{
	set("short", "营盘水");
	set("long", @LONG
这里是当年蒙恬修长城时驻军的地方，蒙恬治军有方，当年他亲
自带人在驻地挖了好几口甜水井，使士卒们不用喝又苦又涩的咸水，
后来此地的百姓们叫这里为营盘水，称这里的井为“蒙恬井”。
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"oldwall",
  "southwest" : __DIR__"bcwan",
]));
       set("fjing", 1);
	set("no_clean_up", 0);
	set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

	setup();
	replace_program(ROOM);
}
