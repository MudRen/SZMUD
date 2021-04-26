//Cracked by shenzhou
// Room: /d/sanbuguan/hill.c
//Modified by jiuer 5/27/2002

inherit ROOM;

void create()
{
        set("short", "得胜山");
        set("long", @LONG
这里是扬州城西三十里大仪乡的得胜山，南宋绍兴年间，韩世忠曾在
此处大破金兵，因此山名“得胜”。其实那山只有七八丈高，不过是个小丘
而已。山上孤零零长着棵很粗壮的老柳树。
LONG
        );
        set("exits", ([
			"east" : __DIR__"road2",
			"west" : __DIR__"yichang",
			]));
		
		set("objects", ([ 
			"/d/sanbuguan/npc/mao" : 1,
			]));
		
		set("outdoors", "sanbuguan");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
