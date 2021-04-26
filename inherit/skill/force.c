// Code of ShenZhou
// force.c

inherit SKILL;

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int damage, myneili, yourneili, my_max, your_max;
	string force_skill;
	mixed foo;
        string result;


	myneili = (int)me->query("neili");
	yourneili = (int)victim->query("neili");
	my_max = (int)me->query("max_neili")*2;
	your_max = (int)victim->query("max_neili")*2;
	myneili = my_max > myneili ? myneili : my_max;
	yourneili = your_max > yourneili ? yourneili : your_max;
	me->add("neili", - factor );
	damage = myneili/20 + factor - yourneili/25;

	if (force_skill = victim->query_skill_mapped("force") ) {
		foo = SKILL_D(force_skill)->hit_by(me, victim, damage, damage_bonus, factor);
		if (stringp(foo)) return (string)foo;
		else if (intp(foo)) damage = (int)foo;
		else if (mapp(foo)) return foo;
	}

	if ( damage > 0 )
                damage = damage * factor / (int)me->query_skill("force") * 2;

	if( damage < 0 ) {
		if( !me->query_temp("weapon")
		&&	random(victim->query_skill("force")) > me->query_skill("force")/2 ) {
			damage = - damage;
			me->receive_damage( "qi", damage * 2, victim);
			me->receive_wound( "qi", damage, victim );
			if( damage < 10 ) result = "$N�ܵ�$n�����������ƺ�һ����\n";
			else if( damage < 20 ) result = "$N��$n���������𣬡��١���һ������������\n";
			else if( damage < 40 ) result = "$N��$n������һ���ؿ������ܵ�һ���ش�����������������\n";
			else result = "$N��$n������һ����ǰһ�ڣ��������ɳ�������\n";
			result += "( $N"+ COMBAT_D->status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";
			damage_bonus = -5000; // just a number negative enough
			return ([ "result" : result, "damage" : damage_bonus ]);
		}
		if( damage_bonus + damage < 0 ) return - damage_bonus;
		return damage;
	}

	damage -= victim->query_temp("apply/armor_vs_force");
	if( damage_bonus + damage < 0 ) return - damage_bonus;
	if( random(me->query_skill("force")) < damage )
		return damage;
}

mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor)
{
	return damage;
}
