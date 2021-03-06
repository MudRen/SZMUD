// Code of ShenZhou
// Room: /d/newdali/tusi2.c

inherit ROOM;

void create()
{
	set("short", "门堂");
	set("long", @LONG
门堂以及其他一些附属建筑，如谷仓，厨房，坚狱，外有二米多高重修
的围墙。主体建筑是规模最大的议事厅，三层大屋系三重蟾歇山顶干栏式建
筑，长六十尺，宽四十有五，高三十尺。二楼是宣抚召集大小头领议会地点，
也是审判室。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "up" : __DIR__"tusi3",
  "north" : __DIR__"tusi4",
  "out" : __DIR__"tusi1",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
