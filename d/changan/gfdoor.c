//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","衙门");
	set("long",@LONG
衙门口站着几位衙役，近年的国泰民安，衙役们也少了很多进油水的地方，
他们正说笑着，衙门口没有一点的严肃感，不过平常老百姓要想从这过，那可
那可就不容易了。
LONG
	);
	set("exits",([
		"southeast" : __DIR__"xfroad2",
		"northwest" : __DIR__"qianyuan",
	]));

      set("objects",([__DIR__"npc/bing":3,]));
	setup();
}
