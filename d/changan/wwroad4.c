//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","威武大路");
	set("long",@LONG
一群官兵骑马而过，扬起一团黄土，弄得街上的行人骂声连连，几个赌客
正疾步前进，走向他们的安乐窝。街上不时发生一些打架斗殴的事件，还有一
些年轻妇女在这一带寻找他们的丈夫。
LONG
	);
	set("exits",([
		"southwest" : __DIR__"sroad1",
		"northeast" : __DIR__"wwroad5",
	]));
set("outdoors", "changan");
	setup();
}
