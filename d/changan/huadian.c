//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","花店");
	set("long",@LONG
这里是长安城最有名的花店，众多的富家小姐，太太都来这里买花。听说
这家花店是大理国的一个分店，因此这里有许多中原不常见的花种。几位衣着
鲜艳的小姐正在赏花，旁边的恶奴正打发店内的几个穷酸汉子。
LONG
	);
	set("exits",([

                "northwest" : __DIR__"xuyuanan",
                "northeast" : __DIR__"dayanta",
		"south" : __DIR__"wroad3",
	]));

	setup();
}
