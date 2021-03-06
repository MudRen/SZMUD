// room /d/wulin/dianmen.c
//updated by Lara 2001/10/14
inherit ROOM;

void create()
{
        set("short", "殿门");
        set("long", @LONG
你终于来到了武林同盟正殿的殿门，朱漆的大门上雕刻着飞禽走兽，
两个硕大的金环闪闪发光。在大门的两边各放着一个威武雄壮的石狮，让
人感到一种庄严萧肃之气。门口的两个同盟义士正不停的打量着你。再往
里走就是武林同盟的正殿了。

LONG
        );

        set("exits", ([
                "south" : __DIR__"shangwu",
                "north" : __DIR__"zoulang",
                "east" : __DIR__"xiaolu5",
                "west" : __DIR__"xiaolu1",
        ]));

        set("objects",([
                __DIR__"npc/yishi" : 2,
        ]));

        set("no_clean_up", 0);
        set("cost", 3);
        setup();
        replace_program(ROOM);
}
