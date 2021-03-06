// /d/jueqing/tanbian.c 潭边
// By jiuer

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIY"潭边"NOR);
	set("long",@LONG 
打量山谷周围的情势，但见四下削壁环列，宛似身处一口大井之底
，头来，云雾封谷，难见天日。看潭边情景，只见大树上排列着数十个
蜂巢。一条长索(suo)从谷口直悬下来， 水潭旁又有许多纵横错杂的脚
印，潭边生着一个火堆，余烬未熄。
LONG);
	set("outdoors","jueqing");
	set("item_desc", (["suo" : 
	                 "这是一条用韧皮搓成的绳索(climb)。\n"])); 
	set("cost",1);
	setup();
}
void init()
{
	add_action("do_jump","jump");
	add_action("do_climb","climb");
}
int do_jump(string arg)
{
	object me = this_player();
	if(!arg)
		return 0;

	if(arg == "tan") 
	{
		message_vision("$N纵身入潭，直往深处潜去。\n",me);
		me->add("jingli",-50);
		message_vision("$N急沉而下，猛地里只觉一股急流卷冲过去，光亮处果然是一洞。\n",me);
		set("exits/up",__DIR__"bingyao");
		remove_call_out("close_door");
		call_out("close_door",5,me);
		return 1;
	}
}

int do_climb(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" )
                return notify_fail("你要跟哪儿爬？\n");

        if (me->query_busy())
                return notify_fail("你正忙着呢。\n");

        if( arg=="suo")
        {
        message_vision("$N左手抓着绳索，微一运动，身子已蹿上削壁丈余。\n", me);
        me->start_busy(5);

        if (random(me->query_skill("dodge")) < 50){
        remove_call_out("drop_down");
        call_out("drop_down", 5, me);
        return 1;
        }
        
        message("vision", me->name()+"一会儿便消失在云气里了。\n", environment(me), ({me}) );
        remove_call_out("climb_up");
        call_out("climb_up", 5, me);
        return 1;
        }
}
void drop_down(object me)
{
        tell_object(me, "突然你一失手，从峭壁上掉了下来，屁股重重地摔在地上。\n");
        message("vision", me->name() + "突然一失手，从峭壁上掉了小来，屁股重重地摔在地上。\n",
                             environment(me), ({me}) );
        me->receive_damage("qi", 50, "从峭壁上掉了下来摔死了");
        me->receive_wound("qi",  50, "从峭壁上了下来摔死了");
}
void climb_up(object me)
{
        tell_object(me, "你手抓绳索，巧运轻功攀绳而上，不多时便爬出了深谷。\n");
        me->add("jingli", -50);
        me->move(__DIR__"duanchang");
        message("vision", me->name() + "气喘吁吁地从下面爬了上来。\n",
                             environment(me), ({me}) );
}
