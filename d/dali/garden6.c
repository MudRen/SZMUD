// Code of ShenZhou
// Room: /d/dali/garden6.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", GRN"茶花院"NOR);
	set("long", @LONG
这里满地遍是茶花，五颜六色，绚丽夺人。花丛中时时有
蜜蜂采蜜其间。碎石路边却长了一，两品异种茶花(flower)。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "flower" : GRN"落第秀才
落第秀才，虽有十七朵不同色的茶花生于一株，但论颜色，
比十八学士少了一色，偏又是驳而不纯，开起来或迟或早，花朵
有大有小。处处东施效颦，学那十八学士却又学不象，于是就被
叫做了“落第秀才”。
"NOR,
]));
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"garden8",
  "south" : __DIR__"garden5",
  "east" : __DIR__"garden7",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
