// yufeng_poison.c 玉蜂毒
// by April 01.08.31

#include <ansi.h>

int update_condition(object me, int duration)
{
	int damage = 1;

	if( !living(me) ) {
		message("vision", me->name() + "的鼻子眉毛仿佛拧到一块儿去了。\n", environment(me), me);
	}
	else {
		tell_object(me, HIW "忽然一阵奇痒从疮口寒袭来，你中的玉蜂毒发作了！\n" NOR );
		message("vision", me->name() + "的身子不停地颤抖起来，双手不住地四处乱抓。\n",
			environment(me), me);
	}

	damage = duration/3;
	damage *= damage;
	damage = random(damage);
	me->receive_wound("jing", damage ,"玉蜂毒攻心死了");
	
	if (duration == 10) 
		tell_object(me, HIW "忽然一阵奇痒攻心而去，你中玉蜂毒太深，已经不可能自然化解了！\n" NOR );
	else me->apply_condition("yufeng_poison", duration - 1);

	if( duration < 1 ){
		tell_object(me, HIW "你中玉蜂毒终于自然化解了！\n" NOR );
		return 0;
	}
	
	return 1;
}
