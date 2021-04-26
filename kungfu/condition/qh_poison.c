//情花毒qh_poison
//黑豹Black/2001/8
// update by April 2001.09.15

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
//	int ml;
	
//	ml = me->query("max_neili")/1000;

	if( !living(me) ) message("vision", me->name() + "痛苦地哼了一声。\n", environment(me), me);
	else {
		tell_object(me, HIR"你偶然想起以前的甜蜜时光，突然被情花刺的地方一阵巨痛。\n"NOR);
		message("vision", me->name() + "脸上露出痛楚神情，浑身不由自主的颤抖起来。\n",
			environment(me), me);
	}

/*
	if(me->query("poisoner")){
		me->receive_damage("qi", 25, me->query("poisoner"));
		me->receive_wound("jing", 15, me->query("poisoner"));
	}
    else{
		me->receive_damage("qi", 25, "情花毒发作死了");
		me->receive_wound("jing", 15, "情花毒发作死了");
	}
*/
	if (!me->is_married()){
//		me->apply_condition("qh_poison", duration - 1);
		me->receive_damage("qi", duration, "情花毒发作死了");
		me->receive_wound("jing", duration*2, "情花毒发作死了");
	}
	else {
		me->receive_damage("qi", duration*3, "情花毒发作死了");
		me->receive_wound("jing", duration*5, "情花毒发作死了");
	}
	
	if(!userp(me)) me->receive_curing("jing", 12);

//  me->apply_condition("qh_poison", duration - 1);
//	if( duration == 1) me->delete("poisoner");

	if( duration < 1 ) return 0;
	return CND_CONTINUE;
}
