//newjob/builder/
//jiuer 11/2001  石铺

inherit ROOM;

void create()
{
        set("short", "石铺");
        set("long", @LONG
这是一家门面不大的石铺，座落在泰山脚下一个村口山路的交界处，
门面很普通，这里专门出售采石工具和一些医伤的膏药，店主祖上曾是当
地有名的石匠。木柜上分类罗列着铁凿，大锤，炸药和一些膏药。
LONG);
        set("objects", ([
                __DIR__"npc/baiquan" : 1,
                ]));
        set("exits", ([
                "east" : __DIR__"hill2",
                ]));
        set("cost", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}