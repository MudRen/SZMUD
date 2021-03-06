// Code of ShenZhou
// Room: /d/newdali/tan.c

inherit ROOM;

void create()
{
	set("short", "黑龙潭");
	set("long", @LONG
黑龙潭碧泉如镜，分前后二池，中以一桥相隔，一泉水清，广约半亩，
水深四十余丈，呈黝黑色；一泉水浊，广约一亩，水色微黄。两泉仅隔数
步，而水色徊异，一黑一皇，对比鲜明。似如道家的太极图，游人多感神
秘。两池皆围以烟柳石栏，清水池中游鱼出没，游人围栏管赏，悠然自得。
LONG
	);
	set("cost", 1);
	set("outdoors", "dali");
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"ling",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
