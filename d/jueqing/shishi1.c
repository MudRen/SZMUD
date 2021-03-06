// Filename:   /d/jueqinggu/shishi1.c 石室1
// Code:       Jiuer
// Date:       Aug 15, 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","石室");
	set("long",@LONG
这是一间不大的石室，里面只摆放一张大木头桌子。石室的东面
是长廊，再过去就是大厅，南面是剑房，但是房门(door)却紧闭着。
LONG);
	set("exits",([ 
		"east" : __DIR__"changlang2",
		]));

	set("item_desc", ([
			"door" :   "一扇紧闭着的房门。\n",
		  ]));
	set("cost",1);
	setup();	
}

void init()
{
	add_action("do_push","push");
}

int do_push(string arg)
{
	object me= this_player();
	if(!arg)
		return 0;
	
	if(arg=="door"|| arg =="men")
	{
		message_vision(HIY"$N猛听得嗤嗤声响，眼前白光闪动，八柄利剑自房门上下左右挺出。\n"NOR,me);
			
			if((int)me->query_dex()> (20+random(5))) 
			{
				message_vision("$N左足踏在门槛之外，右足跨过门槛往地板上一点，立即往外跳回。\n",me);
				message_vision("门「咯吱」一声开了。\n",me);	
				set("exits/enter",__DIR__"jianfang");

				remove_call_out("close_door");
				call_out("close_door",10,me);
				return 1;
			}
			else if ( (int)me->query_dex() > (20+random(1))) 
			{
                message_vision("$N欲闪身避开，却已被其中一柄利剑横穿右臂，你一声惨叫。\n", me);
                me->add("qi", -50);
                me->unconcious();
                return 1;
			}

        else {
                message_vision("$N躲避不及，八柄利剑在身上对穿而过，倒在地上。\n", me);
                me->receive_damage("qi", 50, "被利剑刺死了");
                me->die();
                return 1;
		}
	}
	return 0;
}

void close_door()
{
   tell_room(this_object(),"过了一会儿，门又「咯吱」一下关上了。\n");
   delete("exits/enter");
}