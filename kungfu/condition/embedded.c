// Code of ShenZhou
// embedded.c
// last updated by April 2001.09.28 add 玉蜂针 and time result

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	object ob; 
	string result;

	if(me->query_condition("embedded") > 0){
	message_vision(RED"鲜血顺着$n从$N的伤口处一滴一滴滴到地上。\n\n"NOR,
			me, me->query_temp("armor/embed"));
	me->receive_wound("qi", 100 - duration, "出血过多死了");
	if (me->query_temp("armor/embed") == "玉蜂针")
		me->apply_condition("yf_zhen_poison",
			me->query_condition("yf_zhen_poison")+5);
	}
	
	if (!userp(me) && me->query("race") == "人类"
	&& living(me) && !me->is_fighting() 
	&& ob=me->query_temp("armor/embed")){
		COMMAND_DIR"std/remove"->do_remove(me, ob);
		result = COMBAT_D->eff_status_msg((int)me->query("qi") * 100 /(int)me->query("max_qi"));
        	message_vision("($N"+result+")\n", me);
	return 1;
	}
	
	me->apply_condition("embedded", duration - 1);
	if( !duration ) return 0;

	return CND_CONTINUE;
}

void create() {
	seteuid(getuid());
}
