// Code of ShenZhou

#include <ansi.h>

int auto_perform_duwu()
{
	object me = this_object();
	object *target;
	int damage, poison, i;

	poison = me->query("snake_poison");
	target = all_inventory(environment(me));

	if( me->is_busy() ) return 0;

	if(me->query("jingli") < poison ) return 0;
	
	message_vision(HIR"���$NѪ�����ͷһ��һ������״�ɲ�����Ȼ�ſڣ��������һ�����\n\n"NOR,me);

	for(i=0; i<sizeof(target); i++) {

		if( !living(target[i]) || target[i]==me || target[i]->query("race") == "����" ) continue;

		if( random(poison) > target[i]->query_skill("force") || !living(target[i]) )
	{
			damage = random( poison*10 - target[i]->query("neili") ) ;
			if(damage > 800) damage = 800;
			if(damage < 100) damage = 100;

			target[i]->apply_condition("snake_poison", 
			20 + poison + target[i]->query_condition("snake_poison"));

			target[i]->receive_damage("qi", damage,  me);
			target[i]->receive_wound("qi", random(damage), me);
			target[i]->start_busy(1+random(2));
			message("vision", target[i]->name() + "������΢΢һ�Σ��е����㲻����\n", environment(me), target[i]);
			tell_object(target[i], RED"��ͻȻ�е�һ��ͷ�Σ�ԭ��"+me->name()+"������ĺ����Ǿ綾֮��ڿ�����ɢ���������������߶���\n"NOR);
		}
		else {
			tell_object(target[i], WHT"��������ס���������������߶���\n"NOR);
		}
	}
	me->start_busy(1);
	me->add("jingli",-(random(50)+poison/3));

	return 1;
}

int auto_perform_chan()
{
	object me = this_object();
	object target = me->select_opponent();
	object owner;
	object here = environment(me);
	int damage;

	if( me->query("jingli") < 500 ) return 0;

	if(target->query("race") == "����") return 0;
	if( me->is_busy() || target->query_temp("snake_chan") ) return 0;

	me->set_temp("try_chan",1);
	me->set("default_actions", (: call_other, __FILE__, "query_action" :));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->set("default_actions", (: call_other, "/adm/daemons/race/snake.c", "query_action" :));
	me->delete_temp("try_chan",1);
	return 1;
}

int auto_perform_double()
{
	object me = this_object();
	object target = me->select_opponent();

	if( me->is_busy() || !living(me) ) return 0;

	me->set("default_actions", (: call_other, __FILE__, "query_action" :));
	me->set_temp("double_hit",1);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->set_temp("double_hit",2);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->delete_temp("double_hit");
	me->set("default_actions", (: call_other, "/adm/daemons/race/snake.c", "query_action" :));

	return 1;
}

mapping query_action(object me)
{
	string msg1, msg2;
	msg1 = HIR"�����������죬$N���Ѵ�ǰ��"+(random(2)?"��":"��")+"�ߵ���ͷ˻˻���ţ���Ȼҧ��$n��$l"NOR;
	msg2 = RED"һ�ڲŸ�ҧ����ȴ��$N��һ��ͷҲת��������������ҧ��$n$l"NOR;

	if( me->query_temp("double_hit") )
	return ([
	"action": me->query_temp("double_hit") == 1 ? msg1 : msg2,
	"force" : 400,
	"dodge" : 10,
	"parry" : 10,
	"damage" : 400,
	"weapon" :"����",
	"damage_type":"ҧ��"]);

	else return ([
	"action": HIR"���$N���ɶ೤������һ�ˣ���Ȼ��$n���Ͼ���"NOR,
	"force" : 400,
	"dodge" : 0,
	"parry" : 0,
	"damage" : 400,
	"weapon" :"����",
	"damage_type":"����"]);
}
