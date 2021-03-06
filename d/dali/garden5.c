// Code of ShenZhou
// Room: /d/dali/garden5.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", MAG"茶花院"NOR);
	set("long", @LONG
这里满地遍是茶花，五颜六色，绚丽夺人。花丛中时时有
蜜蜂采蜜其间。碎石路边却长了一，两品异种茶花(flower)。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "flower" : MAG"风尘三侠
风尘三侠，有正品和副品之分，凡是正品，三朵花中必须紫色
者最大，那是虬髯可，白色者次之，那是李靖，红色者最小且最娇
艳，那是红拂女。如果红花大过了紫花白花，那便是副品了，身份
就差得多了。
"NOR,
]));
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"garden3",
  "north" : __DIR__"garden6",
  "southwest" : __DIR__"garden4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
