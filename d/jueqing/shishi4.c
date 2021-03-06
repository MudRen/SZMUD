// Filename:   /d/jueqinggu/shishi4.c 石室4
// by Jiuer 08/15/2001


inherit ROOM;

void create()
{
		  set("short","石室");
		  set("long",@LONG
这是间丈许见方的石室，平时关押犯人的地方。墙壁有些凌乱的刻
画，地上有片烂草席，地上丢着些碎鸡骨头，你待了一会儿就已大汗淋
漓，热得喘不气来。
LONG);

		  set("no_fight",1);
		  set("cost",3);
		  setup();	
}

void init()
{
	add_action("do_break","break");  
}

int do_break(string arg)          
{
	object weapon, me = this_player();

	if( !arg || arg != "wall")					
		return notify_fail("你想干什么？ \n");
	
//无武器打击目标
	if(!objectp(weapon = me->query_temp("weapon"))    
		|| (string)weapon->query("skill_type") != "sword")
	{
		message_vision(
			"$N运足手掌之力，对准墙面猛击过去。\n", me);
		message_vision(
			"结果石壁未破，$N自己反而内力反震，顿时一口鲜血喷口而出。\n", me);
		me->add("neili",-200);
		me->receive_damage("qi",200,"体力透支过度死了");
	}
	else {        //with weapon and break wall;
		if((int)me->query("neili")>=200)  //多于内力和气的限制
		{
			message_vision("$N运足内力，大喝一声，挥剑对准墙面劈了过去。\n",me);
			message_vision("墙上顿时被击了一个大洞。\n",me);			
			set("exits/out",__DIR__"huowanshi");
			me->add("neili", -200);	// 花费内力200点
			remove_call_out("close_door");
			call_out("close_door", 10,me);
}
		else														//少于内力和气力限制
		{
			message_vision("$N内力太弱，掌力侵心，结果剑断人伤，一口鲜血喷口而出。\n",me);
			me->set("neili",0);
			me->receive_damage("qi",200, "体力透支过度死了");

			destruct(weapon);
		}

		return 1;
	}
	
	return 1;
}

void close_door()
{
	tell_room(this_object(),"外面的工人很快地又用砖把墙补好了! \n");
	delete("exits/out");
}