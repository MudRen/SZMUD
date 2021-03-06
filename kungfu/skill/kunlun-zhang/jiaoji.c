/* 
[396] re snowyu                                灵儿(lnere)(Fri Jan 25)
----------------------------------------------------------------------
昆仑掌的pfm.我也查了一些资料,但是没有找到很好的描述.下面我说一个我的想法，
大家共同来修改它吧。
特殊攻击：刚柔交济(jiaoji)
描述：$N暗自调运真气,凝气于掌。(仅自己可见)
只见$N一声清啸，双掌飞舞，连连进攻竟然是不要命的打法。$N此时的掌法时如轻如微风佛面飘浮不定,时如重锤击顶力透千钧令$n大吃一惊。
＜－－被逼无奈只得弃攻转守，以图自保。
$N趁$n手忙脚乱之际，纵身跃至$n身前劈面击出左掌,右掌同时按向$n的小腹。
$n已经退无可退，只得双掌骤起交错着使尽全力击向$N的双掌,试图以力抵力将自己从险境中摆脱出来。殊不知$N的掌力之中却分出了一刚一柔。$n只觉得自己击向自己小腹的一掌轻飘飘毫无力道。
$n暗想“糟糕”。
$n甫觉不妙，想撤力回掌，但为时已晚，猛地里一股巨力撞来已被$N的左掌重重的击中面门,$n的身体如断了线的风筝向摔了出去。
特殊攻击：蚀雪融冰(qinxue)
描述：$N向$n微微一笑,说道：“$n小心了”，令$n一愣。只见$N双掌肉色渐渐由红转青，由青转白,煞无血色。呼呼的掌风也令在场的人感到越来越寒冷。
$N双掌越舞越快，凌厉的掌风如昆仑极顶的雪风暴，刮在人脸上如刀割般疼痛。$n已被无形的掌风冻得浑身发抖，无奈只得运功于周身,抵抗这已经冰冷之极的掌风。
$n的身体微微颤抖，运功于身，抵抗寒冷。(pfm持续时间内对方的反应)
$n的身体渐渐暖了起来，动作也不似刚才那般僵硬。(pfm结束时的对方的描述,表示对方pfm结束。)
*/
// 刚柔交济 By snowyu 2002/2 thank lnere 

#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
     string msg;
	int damage;
	object weapon,ob;
	int skill, jiali, my_rate, your_rate;

	skill = me->query_skill("kunlun-zhang",1);
	jiali=(int)me->query("jiali");
	weapon = me->query_temp("weapon");

	if(me->is_busy())
		return notify_fail("你正忙着呢！\n");

        if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「刚柔交济」只能在战斗中使用。\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「刚柔交济」只能空手使用。\n");

	if( (int)me->query_skill("xuantian-wuji", 1) < 120 )
		return notify_fail("你的玄天无极修为不够，不会使用「刚柔交济」。\n");

	if( me->query_skill_mapped("force") != "xuantian-wuji" )
		return notify_fail("你所用的并非玄天无极，使不出「刚柔交济」！\n");

	if( (int)me->query("neili") < 1000 )
                return notify_fail("你的真气不够！\n");

    if( (int)me->query_skill("kunlun-zhang",1) < 120 )
                return notify_fail("你的昆仑掌火候不够，无法使用「刚柔交济」！\n");

    msg = WHT "\n$N暗自调运真气凝气于掌,只见$N一声清啸，双掌飞舞，连连进攻竟然是不要命的打法。\n" NOR;
    msg += HIY "\n$N此时的掌法时如轻如微风佛面飘浮不定,时如重锤击顶力透千钧令$n大吃一惊。\n"NOR;

    if( random( me->query("combat_exp") ) > random( target->query("combat_exp")*2 ) || !living(target) )
  {
			damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
			if(damage > 4000) damage = 4000;
			if(damage < 1000) damage = 1000;
			if(wizardp(me))
            printf("damage=====%d", damage);
			me->add("neili", -damage/2 );
			me->add("jingli", -me->query("jiajin")/2);

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage), me);
			target->start_busy(1+random(3));

		msg += HIC"\n$N趁$n手忙脚乱之际，纵身跃至$n身前劈面击出左掌,右掌同时按向$n的小腹。\n"NOR;

		msg += NOR;
		me->start_busy(2+random(2));
  }
  else if( random( me->query("combat_exp")*2 ) > random( target->query("combat_exp") )
				&&  random(target->query_skill("dodge")) < random( me->query_skill("strike") )  )
  {
			damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
			damage = damage / 2;
			if(damage > 2000) damage = 2000;
			if(damage < 500) damage = 500;
			if(wizardp(me))
            printf("damage=====%d", damage);

			me->add("neili", -damage/2 );
			me->add("jingli", -me->query("jiajin")/2);

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage), me);
			target->start_busy(1+random(3));

		msg += HIC"\n$n甫觉不妙，想撤力回掌，但为时已晚，猛地里一股巨力撞来已被$N的左掌重重的击中面门。\n"NOR;
        msg += RED"\n$n的身体如断了线的风筝向后摔了出去。\n"NOR;
		msg += NOR;
		target->add( "neili", -damage/4 );
		me->start_busy(2+random(2));
  }
  else if( random( me->query("combat_exp")*2 ) > random( target->query("combat_exp") ) &&
	  random( target->query_skill("dodge")*2 ) > random( me->query_skill("strike") ) )
  {
			damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
			damage = damage / 3;
			if(damage > 1000) damage = 1000;
			if(damage < 250) damage = 250;
			if(wizardp(me))
            printf("damage=====%d", damage);

			me->add("neili", -damage/2 );
			me->add("jingli", -me->query("jiajin")/2);

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage), me);
			target->start_busy(1+random(3));

			msg += HIR"\n$n已经退无可退，只得双掌骤起交错着使尽全力击向$N的双掌,试图以力抵力将自己从险境中摆脱出来。\n"NOR;
            msg += RED"\n殊不知$N的掌力之中却分出了一刚一柔。$n只觉得自己小腹被重重的打了一掌！\n"NOR;
		msg += NOR;
		target->add( "neili", -damage/4 );
		me->start_busy(2+random(2));
  }
  else {
	 msg += HIC"\n$n知道此掌不可招架，身行一转，逃出了$N的攻击范围。\n\n"NOR;
	 me->add("neili", -jiali*2 );
	 me->add("jingli", -me->query("jiajin") );
	 me->start_busy(2 + random(2));
	 message_vision(msg+"\n", me, target);
	 return 1;
  }

  message_vision(msg+"\n", me, target);
  COMBAT_D->report_status(target);
  return 1;
}

