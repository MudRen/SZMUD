//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","大道");
	set("long",@LONG
道两旁树木众多，道路上的行人匆匆而过。这里热闹非凡，熙熙嚷嚷，边
上的店家在叫卖着，引得游人注意。再往前走就到了长安城著名的大雁塔，据
说大雁塔已建千年，和长安城另一个塔---小雁塔，名驰中原。
LONG
	);
	set("exits",([

		"south" : __DIR__"wroad2",
                "north" : __DIR__"dayanta",
	]));
set("outdoors", "changan");
	setup();
}
