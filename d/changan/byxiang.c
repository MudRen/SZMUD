//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","背阴巷");
	set("long",@LONG
背阴巷位于长安西大街北面，住户大多是些贫苦人家。由于官府很少管这
，所以治安并不十分好。周围民居破落，路边杂草丛生，到处是沉闷的灰色，
不见一丝生机。来往的人大多是衣衫褴褛，满面愁色。北面是一家庙宇。
LONG
	);
	set("exits",([
        "north":__DIR__"xuyuanan",
		"south" : __DIR__"wroad4",
	]));

	setup();
}
