//Cracked by shenzhou
// Room: /d/sanbuguan/road2.c
// jiuer 05/23/2002

inherit ROOM;

void create()
{
        set("short", "大道");

        set("long", @LONG
青石大道往西北方延伸。两旁并没有什么特别的景致可以吸引你驻足。
东面隐隐约约的可以看到扬州城的西城垛口。道旁是一小茶亭，卖茶老汉
和他小闺女正忙活着给大伙儿沏茶上饭。
LONG
    );
        set("exits", ([
			"east" : __DIR__"road1",
			"northwest" : __DIR__"road3",
			"west" : __DIR__"hill",
			]));
	
		set("objects", ([ 
			"/d/sanbuguan/npc/seller" : 1,
			"/d/sanbuguan/npc/girl" : 1,
			]));

		set("outdoors", "sanbuguan");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}
