// Code of ShenZhou
// embedded.c
// last updated by April 2001.09.28 add ����� and time result

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
	object ob; 
	string result;

	if(me->query_condition("embedded") > 0){
	message_vision(RED"��Ѫ˳��$n��$N���˿ڴ�һ��һ�εε����ϡ�\n\n"NOR,
			me, me->query_temp("armor/embed"));
	me->receive_wound("qi", 100 - duration, "��Ѫ��������");
	if (me->query_temp("armor/embed") == "�����")
		me->apply_condition("yf_zhen_poison",
			me->query_condition("yf_zhen_poison")+5);
	}
	
	if (!userp(me) && me->query("race") == "����"
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
