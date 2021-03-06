// Program make by fengyu, Describing by Jiuer.
// /d/gumu/obj/hanyu_chuang.c.
// 2002/8/12. by fengyu
// modify by april 01.09.14

#include <ansi.h>
inherit ITEM;

int exercising(object me);
int halt_exercise(object me);
int leavebed();

void create()
{
	set_name(HIW"古寒玉床"NOR, ({"hanyu chuang","chuang","bed"}));
	set_weight(200000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","这是古墓祖师婆婆花了七年心血，到极北苦寒之地，在数百丈坚冰之下挖出\n"
			+ "来的上古寒玉制成的一张寒玉床 (bed)，实为修习上乘内功的良助。睡在这\n"
			+ "玉床上练功，一年抵得上平常修练的十年。\n");
		set("unit", "张");
		set("material", "steal");
	} 
	setup();
}

void init()
{
	add_action("do_onbed", "on");
	add_action("do_onbed", "shang");
	add_action("do_leavebed","leave");
	add_action("do_leavebed","xia");
	add_action("do_exercise","exercise");
	add_action("do_exercise","dazuo");
	add_action("do_tuna","respirate");
	add_action("do_tuna","tuna");
}

int do_onbed(string arg)
{
	int i,j;
	object *inv;	// 储存 当前房间 inventory 物品（包括玩家）的数组。
	object pl = this_player();
	object ob = this_object();
	object here = environment(ob);

	if(!arg || (arg != "bed" && arg != "chuang")) return 0;

	if (pl->is_busy() 
		|| pl->query_temp("pending/exercising")
		|| pl->is_fighting())
		return notify_fail("你现在正忙着呢。\n");

	if (pl->query_temp("onbed") ||
		pl->query_temp("pending/exercise_hanyu")) 
		return notify_fail("你已经在寒玉床上了");

	inv = all_inventory(here);
	j=0;
	for(i=0; i<sizeof(inv); i++){
		if( (int)inv[i]->query_temp("onbed")
			|| inv[i]->query_temp("pending/exercise_hanyu"))
			j += 1;
	}
	if (j>3) return notify_fail("寒玉床上的人太多了，已经挤不下了。\n");

	if (pl->query("family/family_name") != "古墓派")
		return notify_fail("寒玉床冰冷刺骨，你只好走了下来。\n");

	message_vision("$N跳了上寒玉床。\n", pl);
	pl->set_temp("onbed",1);
	call_out("leavebed",5);
	return 1;
}

int do_leavebed(string arg)
{
	object pl = this_player();
	object ob = this_object();
	object here = environment(ob);

	if(!arg || (arg != "bed" && arg != "chuang")){
		return 0;
	}

	if (!pl->query_temp("onbed")) return 0;

	if (pl->is_busy() 
		|| pl->query_temp("pending/exercising")
		|| pl->is_fighting())
		return notify_fail("你现在正忙着呢。\n");

	pl->delete_temp("onbed");
	remove_call_out("leavebed");
	message_vision("$N跳下了寒玉床。\n", pl);
	return 1;
}


int do_exercise(string arg)
{
	object me = this_player();
	int exercise_cost;
	object here;

	seteuid(getuid());
	here = environment(me);

	if (!me->query_temp("onbed")) return 0;

	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("你现在正忙着呢。\n");

	if( me->is_fighting() )
		return notify_fail("战斗中不能练内功，会走火入魔。\n");

	if( !stringp(me->query_skill_mapped("force")) )
		return notify_fail("你必须先用 enable 选择你要用的内功心法。\n");

	if( !arg || !sscanf(arg, "%d", exercise_cost))
		return notify_fail("你要花多少气练功？\n");
	
	if (exercise_cost < 10)
		return notify_fail("你的内功还没有达到那个境界！\n");

	if( (int)me->query("qi") < exercise_cost )
		return notify_fail("你现在的气太少了，无法产生内息运行全身经脉。\n");

	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
		return notify_fail("你现在精不够，无法控制内息的流动！\n");

	write("你一边努力对抗着寒玉床上古寒气，一边运气用功，一股内息开始在体内流动。\n");

	remove_call_out("leavebed");
	me->set_temp("pending/exercise_hanyu", 1);
	me->set_temp("exercise_cost", exercise_cost);
	message_vision("$N盘膝坐下，开始修炼内力。\n", me);
	me->delete_temp("onbed");
	me->start_busy((: exercising :), (:halt_exercise:));
    
	return 1;
}

int exercising(object me)
{
	int exercise_cost = (int)me->query_temp("exercise_cost");
        int neili_gain = 1 + (int)me->query_skill("force") / 5;
	if (exercise_cost < 1) return 0;
	
	me->add("neili", neili_gain);
    me->set_temp("exercise_cost", exercise_cost -= neili_gain/2);

	me->receive_damage("qi", neili_gain/2, "打坐走火入魔死了");

    if (exercise_cost > 0) return 1;

	me->delete_temp("pending/exercise_hanyu");
	me->start_busy(2);
	message_vision("$N运功完毕，深深吸了口气，走下床来。\n", me);
	if ((int)me->query("neili") < (int)me->query("max_neili") * 2)
		return 0;
	else {
		if ((int)me->query("max_neili") > (int)me->query_skill("force") 
			* me->query("con") * 2 / 3 ) {
			write("你的内力修为似乎已经达到了瓶颈。\n");
			me->set("neili", (int)me->query("max_neili"));
			return 0;
		}
		else {
			me->add("max_neili", 1);
			me->set("neili", (int)me->query("max_neili"));
			write("你的内力增加了！！\n");
			return 0;
		}
	}
}

int halt_exercise(object me)
{
	if ((int)me->query("neili") > (int)me->query("max_neili") * 2)
		me->set("neili", (int)me->query("max_neili") * 2);
	me->delete_temp("pending/exercise_hanyu");
	message_vision("$N把正在运行的真气强行压回丹田，离开了寒玉床。\n", me);
    return 1;
}

int do_tuna(string arg)
{
	object me = this_player();

	if (me->query_temp("onbed")){
		write("你实在冻得不行，根本无法静下心来。\n");
		return 1;
	}

	return 0;
}


int leavebed()
{
	object pl = this_player();

	pl->delete_temp("onbed");
	remove_call_out("do_leavebed");
	message_vision("$N冻得实在受不了，连忙跳下了寒玉床。\n", pl);
	return 1;
}
