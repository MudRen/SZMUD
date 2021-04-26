//Room: /d/kaifeng/sroad2.c
//by bravo
inherit ROOM;
void create()
{
        set("short", "南大街");
        set("long", @LONG
你正走在开封府的南大街上，这是一条宽敞开阔的大路，一直向
两边延伸。路上行人来来往往，好不热闹。一些小商小贩常在这里做
些小买卖。南面是南门，北边一条大道名叫开封街，你一看就知到为
啥那麽安静了。
LONG
        );

        set("exits", ([
                
                "east":__DIR__"sroad2e",
                "west":__DIR__"sroad2w",
                "south":__DIR__"nanmen",
                "north":__DIR__"sroad1",
        ]));

           set("outdoors", "kaifeng");
        setup();
        replace_program(ROOM);
}
