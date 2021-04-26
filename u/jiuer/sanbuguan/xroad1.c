//Cracked by shenzhou
// /d/sanbuguan/xroad1.c 小路

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
这里是陕西境内的一条静悄悄的黄土路，两旁有些小土屋，疏疏落落的。路
上行人很少，都行色匆匆地向前赶路。北边有一座小村庄，过了小村就是西岳华
山了。
LONG
        );
        set("exits", ([
                "southeast" : __DIR__"road6",
                "west" : __DIR__"xroad2",
                "north" : "/d/village/hsroad3",
                "south" : __DIR__"house1",
        ]));

        set("no_clean_up", 0);

        set("outdoors", "sanbuguan");

        set("cost", 1);
        setup();
        replace_program(ROOM);
}
