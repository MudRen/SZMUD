//Created by RoomEditer on 02-1-3.
inherit ROOM;

void create()
{
	set("short","幸福大街");
	set("long",@LONG
这条街是通往衙门的必经之路，街上比较冷清，这几年治安良好，欺压百
姓的事件已经很少了，所以去衙门喊冤的也少了。街上有些落叶，一阵风吹来，
让人不寒而栗。
LONG
	);
	set("exits",([

		"northwest" : __DIR__"nroad1",
		"southeast" : __DIR__"xfroad5",
	]));
set("outdoors", "changan");
	setup();
}
