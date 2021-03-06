// Code of ShenZhou
// Room: /d/dali/wuhua.c

inherit ROOM;

void create()
{
	set("short", "大门");
	set("long", @LONG
这里是五华楼的大门，两扇红木门上雕满了各种南疆的珍禽
异兽。这里是南诏大王接待西南各族首领的地方，门上一块乌木
大牌，有三丈来长，一丈八尺高，上面用金粉漆了三个大字“
五华楼”。据闻是南诏王劝丰佑的手迹。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/weishi4" : 2,
]));
	set("cost", 2);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"droad5",
  "enter" : __DIR__"wuhua1.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
