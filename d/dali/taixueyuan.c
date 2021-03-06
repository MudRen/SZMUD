// Code of ShenZhou
// Room: /d/newdali/taixueyuan.c

inherit ROOM;

void create()
{
	set("short", "太学院");
	set("long", @LONG
大理的太学院与之中原汴京的所差甚远。为天下首国的大宋时而派一些资深
的学者儒生来大理执教，加速大理的汉化。没有战火的大理几百年来倒也收集了
不少珍贵的书籍。太学生们大多是官吏或世富之后，望以博学而入主官场。学院
里学生随着朗朗之声有节奏地摆动着脑袋。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"taihejie5",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/teacher" : 1,
]));

	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
