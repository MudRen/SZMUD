// Filename:   /d/jueqinggu/dongkou.c 小溪洞口
// Jiuer 08/ 2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",HIW"筏子上"NOR);

	set("long",@LONG
你四下眺望，只见西首出现一条极窄的溪水。溪水入口处有一大丛
树木遮住，你急忙倒转皮筏，从那树丛中划了进去。溪洞山石离水面不
过三尺， 你必须得横卧(lay)舱中(raft)始能划入，河水湍急，皮筏差
点漂走(drift)。
LONG);
	
	set("outdoors", "/d/jueqing");		
	set("cost",1); 
	setup();
}

void init()
{
  add_action("do_lay","lay");
  add_action("do_drift","drift");
}

int do_lay(string arg)
{ 
	object me = this_player();
	if (!arg|| arg !="raft")            
		return 0;

	if(arg =="raft")
	{		
		message_vision("$N仰面横卧船中，手掌抵住两壁岩石，小船逆流而行...\n\n", me);
		me->add("jingli",-20);		
		message_vision(
			"$N划了一阵，头顶露出一丝光线，两边山峰壁立见露，抬头望天，真乃一线天。\n"
			+"$N已驶进了山谷地带。\n\n",me);
		me->move("/d/jueqing/shangu");
		remove_call_out("close_door");
		call_out("close_door",5,me);
		return 1;
	}	 
	return notify_fail("你一头撞在了石洞口上，立刻脑门肿起一个大包\n");
}

int do_drift()
{
	object me = this_player();
	message_vision(HIW"$N握紧船弦，皮筏顺河颠簸漂流而下。\n"NOR,me);
	me->move("/d/jueqing/river");
	message_vision(HIW"河水卷着$N的皮筏，颠簸着从上游翻流而下。\n"NOR,me);
	message_vision(HIW"河水把皮筏卷走了，$N被扔到了岸边。\n"NOR,me);
	return 1;
}

void close_door()
{
	tell_room(this_object(),"过了一会儿，传来一阵山风，洞口被树丛盖住了。\n");
}
