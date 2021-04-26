// Code of ShenZhou
// Room: /d/dali/wangfu12.c

inherit ROOM;

void create()
{
	set("short", "睡房");
	set("long", @LONG
进了房屋，雪洞一般，一色的玩器全无。案上只有一个土定
瓶，瓶中供著数枝菊，并两部书，茶奁、茶器而已；床上只吊著
青纱帐幔，衾褥也十分青素。上面左右两张榻，榻上都铺著锦茵
蓉簟，每一榻前两张雕漆几，也有海棠式的，也有梅花式的，也
有荷叶式的，也有葵花式的，也有方的，也有圆的；其式不一。
一个上头放著一分炉瓶，一个攒盒。
LONG
	);
	set("cost", 1);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"wangfu11",
  "east" : __DIR__"wangfu13",
]));
	set("no_clean_up", 0);
set("wangfu", 1);

	setup();
	replace_program(ROOM);
}
