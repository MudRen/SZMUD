// July 31,2000
// Code by April
// /gumu/liangongshi2.c
// update april 01/08/19

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short","练功室");

        set("long",@LONG
这石室形状正好与前室相反，北宽南窄，成为梯形。西边半圆，东边
作三角形,室顶石壁(ceiling)上也刻满了诸般花纹符号。西边有一道铁门。
LONG);

                  set("item_desc",(["ceiling" : "
    室顶角落处刻著无数人形，不下七八十个，瞧模样似乎均是女相，姿
式各不相同，全身有一丝丝细线向外散射。
\n"]));

                set("exits",([ 
                                "northeast" : __DIR__"biaoshi2",
                                "northwest" : __DIR__"jianshi2",
                                "west": __DIR__"liangongshi4",
                                "south" : __DIR__"zhangshi2",
                                        ]));

                  set("objects", ([ 
                                "/kungfu/class/gumu/npc/baiyi1": 1, 
                                ]) );

                create_door("west", "铁门", "east", DOOR_CLOSED);
                
                set("cost",1);
                setup();
}
void init()
{
        add_action("do_study", "study");
        add_action("do_study", "du");
}
int valid_leave(object me, string dir)
{
	if ( me->query("gender") == "男性" && dir == "west" && !wizardp(me) )
		return notify_fail("看清楚点，那是女厢房！\n");
	if (dir =="west" && me->query("family/family_name")!="古墓派" ) {
		if (objectp(present("baiyi girl", environment(me))))
			return notify_fail("白衣少女伸手挡住了你的去路：此处本派禁地，请止步。\n");
	}      

        return ::valid_leave(me, dir);
}
int do_study(string arg)
{
        object me;
        int f1, f2;

        me = this_player();

        if ( !arg || ( arg != "ceiling" ) )
                return notify_fail("什么？\n");

		if (me->is_busy()) return notify_fail("你忙着呢！\n");
                
        if ( (int)me->query_skill("literate", 1) < 1){
            write("你不识字，先学点文化(literate)吧。\n");
                        return 1;
                }

        f1 = me->query_skill("yunu-xinjing", 1);
        f2 = me->query_skill("yunu-xinfa", 1);

        if ((f1 >= 30) || (f2>= 30)){
			write("你研究了半天一无所获。\n");
			command("sigh");
			write("这上面的武学对你来说太高深了。\n");
                return 1;
        }

        if (me->query("jing")<15) {
                write("你现在头晕眼花，看不清天花板上的字。\n");
                return 1;
        }

        me->receive_damage("jing", 10, "精力衰竭而死");

        message_vision("$N正专心研读天花板上的古墓心法。\n", me);

		me->improve_skill("yunu-xinfa", me->query_int()/3);
		write("你阅读天花板上的心诀，似乎对古墓武功更有心得了。\n");
        
                return 1;
}
