//by snowyu
//updated by lara 2001/12/07
//五罗轻烟掌
/*
   段正淳不答，站起身来，忽地左掌向后斜劈，飕的一声轻响，身后一枝红烛随
掌风而灭，跟着右掌向后斜劈，又是一枝红烛陡然熄灭，如此连出五掌，劈熄了五
枝红烛，眼光始终向前，出掌却如行云流水，潇洒之极。
木婉清惊道：“这……这是‘五罗轻烟掌’，你怎样么也会？”
*/
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	string weapon;
	int strike, force, amount; 
	strike = me->query_skill("qingyan-zhang",1);
	force  = me->query_skill("kurong-changong",1);
	amount = (strike+force)/3;
	
        if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("五罗轻烟只能对战斗中的对手使用。\n");
	
	if ( me->query_temp("weapon") )
                return notify_fail("五罗轻烟必须空手方可施展。\n");
             if( me->query_temp("piaomiao") ) 
      return notify_fail(HIW "你正在使用云烟飘渺！\n"); 
	
  	if( me->query_skill_mapped("strike") != "qingyan-zhang" )
                return notify_fail("你所用并非五罗轻烟掌!");

	if( me->query_skill_prepared("strike") != "qingyan-zhang" )
                return notify_fail("你所备并非五罗轻烟掌!");
          
        if( me->query_skill_prepared("cuff") != "jinyu-quan" )
                return notify_fail("五罗轻烟需和金玉拳配合使用!");

	if( me->query_skill_mapped("force") != "kurong-changong")
                return notify_fail("你所用并非枯荣禅功,无法施展五罗轻烟！\n");

	if( me->query_skill("kurong-changong",1) < 120 )
		return notify_fail("你的枯荣禅功修为不够，无法施展五罗轻烟！\n");

	if( me->query_skill("qingyan-zhang",1) < 120 )
		return notify_fail("你五罗轻烟掌功力不够，无法施展五罗轻烟！\n");
		
	if (me->query("dali/betrayer")>=1)
	        return notify_fail("你已叛出大理，还好意思使用大理绝学！\n"); 	
	
	if (me->query("dali/qingyan") !=1)
	        return notify_fail("你未经段正淳指点，不会使用五罗轻烟！！\n");
	   
	if( (int)me->query("max_neili") <1000)
	        return notify_fail("你的内力修为不足，无法施展五罗轻烟！\n");
	        
	if( me->query("neili") < 300 )
		return notify_fail("你的内力不够使用五罗轻烟！\n");

        if( me->query("jingli") < 200 )
                return notify_fail("你的精力不够使用五罗轻烟！\n");
       
               

        message_vision(WHT "$N突然间纵身越起，忽地左掌向后斜劈，跟着右掌向后斜劈，瞬间向$n连劈五掌,出掌却如行云流水，潇洒之极!\n\n" NOR, me, target);

	amount = (amount + random(amount*4))/2; //降低固定值，提高随机性

        if(amount > 350 ) amount =350;  
        if(amount < 100 ) amount =100;
        
        if(wizardp(me))
                       
        printf("amount=====%d", amount);
             
	me->add_temp("apply/damage", amount/2); //降低一半伤害
	me->add_temp("apply/attack", amount/2); //降低一半攻击
//         me->add_temp("apply/strike", amount);    //加入提高掌法^M$
	me->prepare_skill("cuff");
	
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	
	me->prepare_skill("cuff" , "jinyu-quan");
	
        me->add("neili", - amount+random(80));
        me->add("jingli", -amount+random(40));

	me->start_busy(1 + random(2));

        me->add_temp("apply/damage", -amount/2);
	me->add_temp("apply/attack", -amount/2);
//        me->add_temp("apply/strike", -amount);
// the above apply/strike did not get added, so do not remove it, by mariner.

	return 1;
}
