// Code of ShenZhou
// Room: /d/dali/garden2.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", RED"茶花园"NOR);
	set("long", @LONG
这花园在水边一排垂柳之后，一丛丛花树映水而红，灿若
云霞。一眼望去，都是红白缤纷的茶花，但似乎胡乱生长，并
无佳品。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"garden3.c",
  "out" : __DIR__"garden1.c",
  "northwest" : __DIR__"garden4.c",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
