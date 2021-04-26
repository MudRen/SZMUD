// Room /d/wulin/jiulu.c
// updated by Lara 2001/10/17
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "狂放酒垆");
        set("long", @LONG
这是一个喝酒聚会的好去处，里面到处堆满了各地豪杰敬奉武林同盟
的美酒，空气中弥漫着狗肉、五香豆的香味。各路豪杰在这喝酒划拳，谈
论武林中的奇闻轶事。为了怕酒后忘事,这里特意提供了留言簿（board）
让你随时记录灵感。这里只欢迎“武”的话题，本游戏任何“武”的方面
的不足或不合理之处你都可以在这里提出，游戏管理者会在第一时间做出
恰当处理。对于热心推动武林同盟发展的玩家，除了给予玩家规则中规定
的奖励外，将会得到武林同盟授予头衔的特殊奖励（精神鼓励）。

LONG
        ); 
              set("exits", ([
		"west" : __DIR__"dating",
    ]));
                set("no_fight", "1");
                set("cost", 1);
                setup();
           call_other("/clone/board/jiulu_b", "???");
}
void init()
{
        add_action("do_exercise",  "exercise");
        add_action("do_exercise",  "dazuo");
        add_action("do_respirate",  "respirate");
        add_action("do_respirate",  "tuna");
        add_action("do_practice",  "practice");
        add_action("do_practice",  "lian");
        add_action("do_study",  "study");
        add_action("do_study",  "du");
}

int do_respirate(string arg)
{
        object me = this_player();
        tell_object(me, "呆在狂放酒垆里，你只觉得心慌意乱，全身精气再也无法凝聚起来！\n");
        return 1;
}
int do_practice(string arg)
{
     object me = this_player();
        tell_object(me, "你想站起来，却觉得浑身发软，全身提不起一丝劲儿来练功！\n");
        return 1;
}

int do_study(string arg)
{
        object me = this_player();
        tell_object(me, "你只觉得脑袋里发晕，书本上一个个字都飞来飞去，再也读不进去！\n");
        return 1;
}
