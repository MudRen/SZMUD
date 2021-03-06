// Code of ShenZhou
// Room: /d/dali/garden8.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIR"茶花院"NOR);
	set("long", @LONG
这里满地遍是茶花，五颜六色，绚丽夺人。花丛中时时有
蜜蜂采蜜其间。碎石路边却长了一，两品异种茶花(flower)。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "flower" : HIR"眼儿媚
一本白花，花瓣儿上有两个橄榄核儿状黑斑的，叫作“眼儿
媚”，那两个黑斑，便好似美人儿的媚眼。
"NOR,
]));
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"garden9",
  "east" : __DIR__"garden6",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
