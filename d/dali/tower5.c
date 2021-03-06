// Code of ShenZhou
// Room: /d/newdali/tower5.c

inherit ROOM;

void create()
{
	set("short", "第五层");
	set("long", @LONG
球状，无人像，四角挂有黄铜铸灵鹫。四只灵鹫，口角噙有一枚
两头有孔的铜管，管内有金属簧片，鹫口、鹫颈、鹫腹皆是空心。每
当劲风吹来，经鹫嘴内铜管，在鹫腹内空气回旋荡扬，便发出悦耳的
鸣叫。不但平增灵鹫的神密气氛，亦可想见能工巧匠们的精湛技艺。
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tower6",
  "down" : __DIR__"tower4",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
