// Code of ShenZhou
// Room: /d/dali/garden4.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIB"茶花院"NOR);
	set("long", @LONG
这里满地遍是茶花，五颜六色，绚丽夺人。花丛中时时有
蜜蜂采蜜其间。碎石路边却长了一，两品异种茶花(flower)。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "flower" : HIB"八仙过海
八仙过海，是八朵茶花开于一株，八色各不相同，其中必
须有深紫和淡红的各一朵，那是铁拐李与何仙姑。没有那两种
特别颜色的，及便是八花异色也不能算是“八仙过海”了，叫
做“八宝妆”，就次了一品。
"NOR,
]));
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"garden5",
  "southeast" : __DIR__"garden2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
