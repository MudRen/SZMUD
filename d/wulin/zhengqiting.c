// room /d/wulin/zhengqiting.c
//updated by Lara 2001/10/17
inherit ROOM;

void create()
{
        set("short", "正气厅");
        set("long", @LONG
    这里是武林同盟的正气厅，武林同盟罚恶使者平时不下山时，通常都
是在这里处置武林公案。上首正中放着把虎皮椅，罚恶使者就坐在上面开
堂审理。东面就是罚恶处。
LONG
        );

        set("exits", ([
                "south" : __DIR__"xiayitang",
                "north" : __DIR__"dating",
                "east" : __DIR__"fachu",
        ]));

        set("objects",([
                __DIR__"npc/yishi" : 3,
        ]));

        set("no_clean_up", 0);
        set("cost", 2);
        setup();
}
 

