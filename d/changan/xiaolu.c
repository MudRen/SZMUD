//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","小路");
	set("long",@LONG
两边白石陵层，或如鬼怪，或如猛兽，纵横傲立，上面苔藓成斑，
藤萝掩映，其中微露羊肠小径。东北方向走就到小雁塔了，东南面是个
不吉利的地方，很少人敢去那里。正南面就是行刑的法场，平常大门紧
闭没人敢进去。
LONG
	);
	set("exits",([
        "northeast":__DIR__"xiaoyanta",
		"southeast":__DIR__"luansg",
                "west" : __DIR__"nroad2",
	]));
set("outdoors", "changan");
	setup();
}
