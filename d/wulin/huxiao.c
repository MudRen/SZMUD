// room /d/wulin/huxiao.c
//updated by Lara 2001/10/17
inherit ROOM;

void create()
{
        set("short", "虎啸坪");
        set("long", @LONG
虎啸坪是一块擂台大小的平地，往上要爬一段陡峭的山路才能到达龙
吟坡。每当深秋，树叶凋零，一阵秋风吹过，四周回声有如猛虎咆哮，令
人不由的想起威猛肃杀的古战场。
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"shanmen",
                "northup" : __DIR__"longyin",
        ]));

        set("objects",([
                __DIR__"npc/yishi" : 1,
        ]));

        set("no_clean_up", 0);      
        set("cost", 1);
        setup();
}
