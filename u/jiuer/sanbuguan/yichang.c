//Cracked by shenzhou
// Room: /d/sanbuguan/yichang.c
//Modified by jiuer 5/27/2002

inherit ROOM;

void create()
{
        set("short", "异娼庙");
        set("long", @LONG
这里是“英烈夫人庙”，供奉的是韩世忠夫人梁红玉，扬州人又称之
为“异娼庙”。梁红玉年轻时做过妓女，风尘中识得韩世忠。扬州妓女每
年必到英烈夫人庙烧香许愿，祈祷这位宋朝的安国夫人有灵，照顾后代
的同行姐妹。
LONG
        );
        set("exits", ([
			"east" : __DIR__"hill",
			]));
		
		set("outdoors", "sanbuguan");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
