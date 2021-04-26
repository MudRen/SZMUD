// Code of ShenZhou
// 白玉峰
// maco
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "白玉通道");
	set("long", @LONG
一条长长的通道，四周白玉壁上映出你的影子。
LONG
	);

	set("exits", ([
		"south" : __DIR__"jaderoom1",
		"north" : __DIR__"jaderoad2",
	]));

	set("cost", 1);
	setup();
}
