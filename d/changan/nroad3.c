//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","长安北大街");
	set("long",@LONG
走在大石板街上，长安的北街比较冷清,路上的行人较少。寒风吹过,让人毛骨悚然。
西面是个钱庄，往东走就是长安城的驿站，是人们给远在他方的亲人好友寄去慰问和关怀
的地方。再往前走就出了长安城了。
LONG
	);
	set("exits",([
		"east" : __DIR__"yizhan",
		"west" : __DIR__"qianzhuang",
		"south" : __DIR__"nroad2",
		"north" : __DIR__"beimen",
	]));
set("outdoors", "changan");
	setup();
}
