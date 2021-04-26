// room /d/wulin/shanlu.c
//updated by Lara 2001/10/17
inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
这里又是一段曲折的山路，路边长满了花草，空气中充满了沁人的清
香，不时的有蝴蝶、蜜蜂从你的面前翩翩飞过，让你暂时忘记了登山的疲
劳。东面是剑气泉，再往上爬，就到尚武轩了。
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"longyin",
                "northup" : __DIR__"shangwu",
                "east" : __DIR__"jianquan",
        ]));     

        set("no_clean_up", 0);        
        set("cost", 1);
        setup();
}








