// yf_zhen_poison.c 玉蜂针毒
// by April 2001.09.26

#include <ansi.h>

int update_condition(object me, int duration)
{
	int damage = 1;

	if( !living(me) ) {
		message("vision", me->name() + "不停地在地上扭动。\n", environment(me), me);
	}
	else {
		tell_object(me, HIW "忽然一阵奇痒迅速从疮口袭满全身，你中的玉蜂针毒发作了！\n" NOR );
		message("vision", me->name() + "不停地在身上乱抓，满身的红印触目惊心。\n",
			environment(me), me);
	}

	damage = duration;
	damage *= damage;
	damage = random(damage);
	me->receive_wound("jing", damage/2 ,"玉蜂针毒攻心死了");
	me->receive_wound("qi",damage,"玉蜂针毒攻心死了");
	
	if (duration >= 10) me->apply_condition("yf_zhen_poison", duration - 1);

	if( duration < 1 ){
		tell_object(me, HIW "你中的玉蜂针毒终于化解了！\n" NOR );
		return 0;
	}
	
	return 1;
}
