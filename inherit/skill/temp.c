// Code of ShenZhou
// force.c
#include <ansi.h>

inherit SKILL;

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int damage;

	if ((int)victim->query_skill("beiming-shengong",1)>50
			&& (int)me->query_skill("beiming-shengong",1)<50
			&& !me->query_temp("weapon")
			&& me->query("id")!="mu ren"
			&& me->query("max_neili")>100
			&& victim->query("combat_exp")>me->query("combat_exp")
			&& (victim->query("combat_exp")*100/me->query("combat_exp")-50)>random(149))
	{
		victim->add("max_neili", 1*(1+((int)victim->query_skill("beiming-shengong",1)/100)));
		me->add("max_neili", -1*(1+((int)victim->query_skill("beiming-shengong",1)/100)));

		if ((int)me->query("potential")-(int)me->query("learned_points")<97)
			victim->add("potential",  3);
		victim->add("combat_exp", 10);
		return HIY "$N��������һ�����У�ȴ����ֻ��Ϣ��һ����һ������$n�����˹�ȥ��\n" NOR;
	}

	me->add("neili", - factor );
	damage = (int)me->query("neili")/20 + factor
		- (int)victim->query("neili")/25;
	if( damage < 0 ) {
		if( !me->query_temp("weapon")
		&&	random(victim->query_skill("force")) > me->query_skill("force")/2 ) {
			damage = - damage;
			me->receive_damage( "qi", damage * 2 );
			me->receive_wound( "qi", damage );
			if( damage < 10 ) return "$N�ܵ�$n�����������ƺ�һ����\n";
			else if( damage < 20 ) return "$N��$n���������𣬡��١���һ������������\n";
			else if( damage < 40 ) return "$N��$N������һ���ؿ������ܵ�һ���ش�����������������\n";
			else return "$N��$n������һ����ǰһ�ڣ��������ɳ���������\n";
		}
		if( damage_bonus + damage < 0 ) return - damage_bonus;
		return damage;
	}

	damage -= victim->query_temp("apply/armor_vs_force");
	if( damage_bonus + damage < 0 ) return - damage_bonus;
	if( random(me->query_skill("force")) < damage )
		return damage;
}