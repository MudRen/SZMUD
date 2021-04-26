// /d/wizard/news_room.c
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", GRN"天界造物公告处"+NOR);  
        set("long", @LONG
这里是天界代理人通告凡界，这个世界新生事物的公告板。如果你想在第一
时间知道游戏的最新动态，比如新的谜题、新的工作、新的系统、新的门派武功，
就应该经常到这里来转转。这里人声嘈杂，大家都在竞相讨论游戏的新变化。
LONG
        );
        set("exits", ([
                "northeast": "/d/wizard/guest_room",
    ]));
        set("no_fight", "1");
        set("no_steal", 1);
        set("no_sleep_room", "1");
        set("valid_startroom", 1);
        set("cost", 0);
        setup();
        "/clone/board/toplayer_b"->foo();
}
void init()
{
        add_action("do_exercise",  "exercise");
        add_action("do_exercise",  "dazuo");
        add_action("do_exercise",  "respirate");
        add_action("do_exercise",  "tuna");
        add_action("do_practice",  "practice");
        add_action("do_practice",  "lian");
        add_action("do_study",  "study");
        add_action("do_study",  "du");
}
int do_exercise(string arg)
{
        object me = this_player();
        tell_object(me, "你是来看新闻还是来练功啊？\n");
        return 1;
}
int do_practice(string arg)
{
        object me = this_player();
        tell_object(me, "这里已经够吵的了，别再添乱了！\n");
        return 1;
}
int do_study(string arg)
{
      object me = this_player();
        tell_object(me, "你就是再用功也不差这一会吧？\n");
        return 1;
}
