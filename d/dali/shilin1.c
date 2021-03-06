// Code of ShenZhou
// Room: /d/newdali/shilin1.c

inherit ROOM;

void create()
{
	set("short", "路南石林");
	set("long", @LONG
在绿树丛中随处可见峭石插天，石笋丛集，石柱挺立，奇异诡质，各呈异姿。
这里石峰攒聚，如剑戟排空，莽莽苍苍，俨然一片林海，蔚为壮观。更加丛山之
中或飞瀑直泻，成叠水喷云，或山泉汇聚，成明镜长湖。
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"cangshan",
  "northup" : __DIR__"shilin5",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
