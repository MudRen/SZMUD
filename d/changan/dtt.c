//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
        set("short","断头台");
	set("long",@LONG
这里就是刽子手行刑的地方，一个高大的台子上挂着两把雪亮的大砍刀。
让人感觉到一种阴森森的恐怖。北面一座大铁门常年紧闭着。
LONG
	);
	set("exits",([
        "northdown":__DIR__"xiaolu",
        "eastdown":__DIR__"luanfd",
	]));
set("outdoors", "changan");
	setup();
}
