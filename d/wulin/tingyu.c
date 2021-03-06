// room /d/taishan/tingyu.c
// Fywen
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "听雨亭");
    
	set("long", @LONG
这是一个精巧别致的小亭子，飞檐翘翎，周围云雾缭绕，飘飘渺渺，
仿佛仙境一般，透过云雾向西望去，一天门隐约可见。在亭子中央摆放着
一张大理石桌，周围有几张石凳，一张石桌上面摆着一个小本子（board） 
旁边笔墨已经备好了。
LONG); 

	set("exits", ([
		"northwest" : __DIR__"yitian",
	]));
	set("no_fight", "1");
	set("cost", 1);
	setup();
    
	call_other("/clone/board/tingyu_b", "???");
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
        tell_object(me, "呆在听雨亭里，你只觉得心慌意乱，全身精气再也无法凝聚起来！\n");
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