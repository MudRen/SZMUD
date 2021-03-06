//Cracked by Roath
// neiheal.c
// By Xuanyuan

#include <ansi.h>

int exert(object me, object target)
{
	int mode, duration_hot1, level, duration_hot2, duration_cold1, duration_cold2;
	if( target == me ) mode = 1;
	else mode = 2;

   	if( me->is_fighting() || target->is_fighting() )
		return notify_fail("战斗中无法运功疗伤！\n");

   	if ( mode == 1 ) {
		if ( (int)me->query_condition("hot_poison") < 0 )
			return notify_fail("你并未受寒梅暖阳劲内伤！\n");

		if ( (int)me->query_condition("cold_poison") < 0 )
			return notify_fail("你并未受混寒梅暖阳内伤！\n");

		if ( (int)me->query_skill("bahuang-gong", 1) < 80 ) 
			return notify_fail("你八荒六合唯我独尊功的造诣太浅，不能化解寒梅暖阳内伤！\n");

		if( (int)me->query("neili") < 350 )
			return notify_fail("你的真气不够。\n");

		if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
			return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

		message_vision(RED"$N盘膝坐下运动八荒六合唯我独尊功，只见头上舞气腾腾，吐出一口殷红的瘀血，脸色显得十分苍白。\n"NOR, me);
        	me->apply_condition("hot_damage", 0);
			me->apply_condition("cold_damage", 0);
        	me->add("neili", -200);
		me->receive_damage("qi", 100, "体力透支过度死了");
	}	
	else {
		if ( (int)target->query_condition("hot_poison") < 0 )
			return notify_fail("此人并未受寒梅暖阳内伤！\n");

		if ( (int)target->query_condition("cold_poison") < 0 )
			return notify_fail("此人并未受寒梅暖阳内伤！\n");

		if ( (int)me->query_skill("bahuang-gong", 1) < 100 )
			return notify_fail("你八荒六合唯我独尊功的造诣太浅，不能为他人化解寒梅暖阳内伤！\n");

		if( (int)me->query("max_neili") < 1000 )
			return notify_fail("你的内力修为不够。\n");

		if( (int)me->query("neili") < 500 )
			return notify_fail("你的真气不够。\n");

		if( (int)target->query("eff_qi") < (int)target->query("max_qi") / 5 )
			return notify_fail( target->name() +"已经受伤过重，经受不起你的真气震荡！\n");

		if( !living(target) )
			return notify_fail("此人已昏死或死了，不能救治！\n");

		message_vision(RED"$N坐下运起八荒六合唯我独尊功，连连拍按$n各处命门大穴，徐徐地将真气输入$n体内....\n"
				  "不久，$N额头上大汗淋漓，头上白气蒸腾，显得十分疲倦。\n"
				  "只见$n吐出一口殷红的瘀血，脸色却显得十分苍白。\n" NOR, me, target );

		tell_object(target,GRN"你感到一股与你一股真力在你五脏六腑间游走，渐渐地\n"
				      "在化解你的内伤，造成时麻时痒的感觉。\n"NOR);

		if( (int)target->query_skill("bahuang-gong", 1) > 20 ) {
			tell_object(target,GRN"你寒梅暖阳内伤被化解了。\n"NOR);
			target->apply_condition("hot_poison", 0);
			target->apply_condition("cold_poison", 0);
			target->receive_damage("qi", 100, "体力透支过度死了");
			me->add("neili", -200);
			me->receive_damage("qi", 100, "体力透支过度死了");
		}
		else {
			level = me->query_skill("bahuang-gong", 1);
			duration_hot1 = target->query_condition("hot_poison");
			duration_hot2 = duration_hot1 - me->query_skill("bahuang-gong", 1) / 20;
			duration_cold1 = target->query_condition("hot_poison");
			duration_cold2 = duration_cold1 - me->query_skill("bahuang-gong", 1) / 20;

			if ( duration_hot2 < 0 ) duration_hot2 = 0;
			if ( duration_cold2 < 0 ) duration_cold2 = 0;

			target->apply_condition("hot_poison", duration_hot2);
			target->apply_condition("cold_poison", duration_cold2);
			me->add("neili", -200);
			if ( target->query_condition("hot_poison") > 0 && target->query_condition("cold_poison") > 0 ) {
				tell_object(me,"你发觉"+target->name()+"无法完全吸收你八荒六合唯我独尊功的真力，看来得分几次治疗！\n");
				if( (int)target->query_skill("bahuang-gong", 1) > 0 )
					tell_object(target,"你的八荒六合唯我独尊功修为不够，无法与"+me->name()+"的真力融合，看来得分几次治疗！\n");
				else tell_object(target,"你内功心法与八荒六合唯我独尊功大相径庭，无法与"+me->name()+"的真力融合，看来得分几次治疗！\n");
			}
			else tell_object(target,GRN"你寒梅暖阳内伤被化解了。\n"NOR);
			target->receive_damage("qi", 150, "体力透支过度死了");
			me->receive_damage("qi", 100, "体力透支过度死了");
		}
	}

	return 1;
}
