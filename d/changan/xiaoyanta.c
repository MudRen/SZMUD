//Created by RoomEditer on 02-1-3
//by bravo
inherit ROOM;

void create()
{
	set("short","小雁塔");
	set("long",@LONG
小雁塔是一座通高几十丈的砖塔，从底下向上看去，庄严而玲珑，塔身檐角密布，
一共有十五层之高，与西南边的大雁塔遥遥相望。塔的外表雕着许多龙凤，塔顶有一颗
圆润的巨石。
LONG
	);
	set("exits",([
		"southwest" : __DIR__"xiaolu",
	]));

	setup();
}
