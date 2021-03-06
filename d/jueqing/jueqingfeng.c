// Filename:   /d/jueqinggu/jueqingfeng.c  绝情峰
// by Jiuer  08/15/2001

#include <ansi.h>
inherit ROOM;

void create()
{
	int i;
		set("short",WHT"绝情峰"NOR);

		set("long",
"这里极少人行，抬头见山峰笔立，峰顶深入云雾之中，不知尽头。
崖面光溜溜的寸草不生，终年云雾环绕，天风猛烈，便飞鸟也甚难在峰
顶停足。正是绝险之地的【"+WHT"绝情峰"NOR+"】。\n"
);
		set("outdoors","jueqing");

		i = random(2);
		    switch(i) {
		case 0:
			set("objects", ([
				__DIR__"obj/longhua" : 1,
				]));
		break;
		case 1:
			set("objects", ([
				"clone/herb/duanchang" : 1,
				]));
			break;
			}
		set("cost",2);
		setup();	
}

void init()
{
	add_action("do_climb","climb");
	add_action("do_climb","pa");
}

int do_climb(string arg)
{
	object me = this_player();
	if( !arg )
		return notify_fail("什么?\n" );

	if(me->query_busy())
		return notify_fail("漫漫爬！\n");
	
	if( arg != "down")
		return notify_fail("你只能往下爬! \n" );
	
	
	if( arg =="down")
	{
		
		message_vision("$N小心翼翼地往崖壁下爬了下去。\n", me);
	    me->start_busy(5);

		me->add("jingli",-50);
		
		me->move(__DIR__"duanchang");
		message("vision", me->name()+"缓缓地从峰顶上爬下来。\n", environment(me), me);

		return 1;
	}
}

void drop_down(object me)
{
        tell_object(me, "$N突然脚下一滑，从峭壁上掉了下来，摔了个鼻青脸肿。\n");
        message("vision", me->name() + "突然脚下一滑，从峭壁上掉了下来，摔了个鼻青脸肿。\n",
                             environment(me), ({me}) );
        me->receive_damage("qi", 100, "从峭壁上掉了下来摔死了。");
        me->receive_wound("qi",  100, "从峭壁上掉了下来摔死了。");
}

/*void climb_down(object me)
{
        tell_object(me, "$N深深地吸了一口气，手脚攀住崖缝。\n\n");
        me->add("jingli", -50);
        me->move(__DIR__"duanchang");
        message("vision", me->name() + "气喘吁吁地从下面爬了上来。\n",
                             environment(me), ({me}) );
}
*/