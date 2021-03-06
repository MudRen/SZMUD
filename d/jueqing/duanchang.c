
// Filename:   /jueqinggu/duanchang.c
// by jiuer 08/2001

#include <ansi.h>
inherit ROOM;
string look_cliff();
string look_zi();
int do_jump(string arg);

void create()
{
	set("short",YEL"断肠崖"NOR);

	set("long",@LONG
这里前后风景清幽，但地势险峻，山崖下临深渊，自渊口下望，黑
黝黝的深不见底。崖面(cliff)刻有三个大字， 青苔石缝中隐隐约约的
还有一行小字(zi)。山石滑溜溜，极易掉入深渊。谷内居民相戒裹足，
便是身负武功的绿衣弟子也轻易不敢来此。
LONG);
    set("exits",([ 
		"southdown" : __DIR__"houshan",
		]));    
	set("item_desc", ([
		"cliff" : (:look_cliff:),
		"zi" : (:look_zi:),
		]));
	
	set("cost",6);          
	set("outdoors","jueqing");
	setup();      
}

string look_cliff()
{
        return
        "\n"
        "    ********        \n"
        "    *  断  * \n"
        "    *      * \n"
        "    *  肠  * \n"
        "    *      * \n"
		"    *  崖  * \n"
        "    ******** \n"
		             "\n\n";
}

string look_zi()
{
        return
                "\n"
				"   =================          \n"
                "   |   十     夫   |          \n"
                "   |   六     妻   |          \n"
                "   |   年     情   |     小 珍\n"
                "   |   后     深   |     龙 重\n"
                "   |               |     女 千\n"
                "   |   在     勿   |     书 万\n"
                "   |   此     失   |     嘱   \n"
                "   |   相     信   |     夫 务\n"
                "   |   会     约   |     君 求\n"
                "   |===============|     杨 相\n"
                "                         郎 聚\n\n";
}

void init()
{
  add_action("do_climb","climb");
  add_action("do_climb","pa");
  add_action("do_jump","jump");
}

int do_climb(string arg)
{
        object me = this_player();
        
        if( !arg )
                return notify_fail("性命攸关，你不能这麽爬！\n");
        if(me->query_busy())
                return notify_fail("慢慢爬!\n");
        if ( arg != "up" ) 
           return notify_fail( "你只能往上爬！\n" );

        if(arg =="up")
        {
        message_vision("$N手脚并用顺着峭壁往峰顶上爬去。\n\n\n", me);
        me->start_busy(5);
		
		if(random(me->query_skill("dodge")) <= 70) 
		{
			remove_call_out("drop_down");
			call_out("drop_down",5,me);
			return 1;
		}
                
        message("vision", me->name()+"一会儿便消失在云雾里了。\n", environment(me), ({me}) );
        remove_call_out("climb_up");
        call_out("climb_up", 5, me);
        return 1;
        }
}

void drop_down(object me)
{
        tell_object(me, "突然脚下一滑，从峭壁上掉了下来，摔了个鼻青脸肿。\n");
        message("vision", me->name() + "突然脚下一滑，从峭壁上掉了下来，摔了个鼻青脸肿。\n",
                             environment(me), ({me}) );
        me->receive_damage("qi", 100, "从峭壁上掉了下来摔死了");
        me->receive_wound("qi",  100, "从峭壁上掉了下来摔死了");
}

void climb_up(object me)
{
        tell_object(me, "你深吸一口气纵身跃起，几个起落间，攀上了绝情峰顶。\n\n");
        me->add("jingli", -50);
        me->move(__DIR__"jueqingfeng");
        message("vision", me->name() + "气喘吁吁地从下面爬了上来。\n",
                             environment(me), ({me}) );
}

int do_jump(string arg)
{
	object me = this_player();
    
	if(!arg||arg!= "cliff")
		return 0;

	if(arg == "cliff")
	{
		message_vision("$N感到心伤肠断，想从此一了百了，于是纵身跃入谷底。\n\n\n", me);

		if ( me->query("dex",1) <= 15 ) {
			message_vision("$N的身子摔在崖壁上，翻了几个滚，坠落进潭水里。\n", me);
			message_vision("一声惨嚎，$N被潭水吞噬了。\n", me);
		//	me->receive_damage("qi", 100, "从峭壁上掉在潭水里淹死了。");
		//	me->receive_wound("qi",  100, "从峭壁上掉在潭水里淹死了。");
			me->receive_wound("qi", me->query("max_qi")+100, "在潭水里淹死了");
		}
		if ( me->query("dex",1) > 15) {
			me->start_busy(10);
			message_vision("突然扑通一响，$N竟是摔下了一个水潭之中。\n",me);
			me->unconcious();			
			me->move("/d/jueqing/bishuitan");
		}
		return 1;	
	}
}