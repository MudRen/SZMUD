// Room /d/wulin/shishe.c
// updated by Lara 2001/10/17
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "豪情诗社");
        set("long", @LONG
这是一个清新典雅的去处，有几个客人正在饮茶品茗，谈天说地，好
不自在。如果你腹有经纶、胸有豪气，可以在这泼墨题诗。即使你文采不
够，你也可以在这留下你的大作，笔纸（board） 已经为您准备好了。请
注意，这里只欢迎“文”的话题，本游戏任何“文”的方面的不足或不合
理之处你都可以在这里提出，游戏管理者会在第一时间做出恰当处理。对
于热心推动武林同盟发展的玩家，除了给予玩家规则中规定的奖励外，将
会得到武林同盟授予头衔的特殊奖励（精神鼓励）。
LONG
        ); 
              set("exits", ([
		"east" : __DIR__"dating",
    ]));
                set("no_fight", "1");
                set("cost", 1);
                setup();
           call_other("/clone/board/shishe_b", "???");
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
        tell_object(me, "呆在豪情诗社里，你只觉得心慌意乱，全身精气再也无法凝聚起来！\n");
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
