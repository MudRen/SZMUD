// Code of ShenZhou
// room: /d/baituo/dushi.c
// Jiuer

inherit ROOM;

void create()
{
	set("short", "炼毒室");
	set("long", @LONG
这是白驼山庄的炼毒室，白驼弟子常在这里用新孵化出的小怪蛇
来配置白驼的百毒丸。
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"shechang",
	]));

	set("cost", 2);
	setup();
}
