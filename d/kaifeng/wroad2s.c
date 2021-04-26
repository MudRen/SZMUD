//Room: /d/kaifeng/wroad2s.c
//by bravo
inherit ROOM;
void create()
{
        set("short", "西大街");
        set("long", @LONG
你正走在开封府的西大街上，这是一条宽敞开阔的大路，往北面
一直延伸。路上行人来来往往，好不热闹。小商小贩常在这里做些小
买卖，常常可见有人骑着高头大马穿行其间。
LONG
        );

        set("exits", ([
                "southwest" : __DIR__"xilin",
                "southeast":__DIR__"sroad2w",
                "north":__DIR__"wroad2",
              ]));

         set("objects",([
                __DIR__"/npc/liumang":1,
             ]));
         set("outdoors", "kaifeng");
        setup();
        replace_program(ROOM);
}
