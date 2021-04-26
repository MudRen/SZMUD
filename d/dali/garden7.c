// Code of ShenZhou
// Room: /d/dali/garden7.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIG"茶花院"NOR);
	set("long", @LONG
这里满地遍是茶花，五颜六色，绚丽夺人。花丛中时时有
蜜蜂采蜜其间。碎石路边却长了一，两品异种茶花(flower)。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "flower" : HIG"满月
满月，是一本大白花而微有隐隐的黑斑的，大白花好似一轮
明月，那些黑斑，便是月中的桂枝了。
"NOR,
]));
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"garden6",
]));

//        set("objects", ([
  //              __DIR__"npc/huajiang": 1,
    //

    
// ]));                                                                  
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
