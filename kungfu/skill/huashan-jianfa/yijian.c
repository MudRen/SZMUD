// yijian by snowyu, 2002/4 snowyu
/*
  岳夫人长剑使得兴发，突然间一声清啸，剑锋闪烁不定，
围着令狐冲身围疾刺，银光飞舞，众人看得眼都花了。猛地里
她一剑挺出，直刺令狐冲心口，当真是捷如闪电，势若奔雷。
   岳夫人右手向前疾送，长剑护手已碰到令狐冲的胸
膛，眼见这一剑是在他身上对穿而过，直没至柄。
*/

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string weapon  ;
        int damage , dodge_skill, str, lvl1 , lvl2, lvl3, lvl4, ap , dp;
		mapping myfam;

		if( !target ) target = offensive_target(me);

//                 if (! wizardp(me)) 
//                 return notify_fail("目前这功能还不开放！\n");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HIY "「宁氏一剑」只能对战斗中的对手使用。\n"NOR);

		if ( me->query("family/family_name") != "华山派" && (!wizardp(me)) )
                return notify_fail(HIY "你非华山弟子，怎能使用华山绝技！\n"NOR);

                if( me->query_temp("kuaijian",1) ) 
                      return notify_fail(HIY "你正在使用「狂风快剑」\n"NOR);

                if( me->query_temp("sanxianjian",1) ) 
                      return notify_fail(HIY "你正在使用「夺命连环三仙剑」！\n"NOR);
        if( me->query_temp("yijian",1) )
                return notify_fail(HIY "你已在使用「宁氏一剑」！\n"NOR);

        if( me->query_skill_mapped("force") != "zixia-gong" && !wizardp(me))
                return notify_fail(HIY "你所用的并非紫霞神功，无法施展「宁氏一剑」！\n"NOR);
		
		if( me->query_skill("ziyin-yin",1) <150 )
                return notify_fail(HIY "你紫氤吟修为不足，还不会使用「宁氏一剑」！\n"NOR);

		if( me->query_skill("zhengqi-jue",1) <150 )
                return notify_fail(HIY "你的正气诀修为不足，还不会使用「宁氏一剑」！\n"NOR);

        if( (lvl1 = me->query_skill("zixia-gong", 1 )) < 200 )
                return notify_fail(HIY "你的紫霞神功火候未到，无法施展「宁氏一剑」！\n"NOR);

	    if( me->query_skill_mapped("parry") != "huashan-jianfa" )
                return notify_fail(HIY "你没有将华山剑法运用于招架中，无法施展「宁氏一剑」！\n"NOR);

        if( (lvl2 = me->query_skill("huashan-jianfa", 1)) < 200 )
                return notify_fail(HIY "你的华山剑法修为不足，还不会使用「宁氏一剑」！\n"NOR);
		if( me->query("neili") <= lvl1*3 )
                return notify_fail(HIY "你的内力不够使用「宁氏一剑」！\n"NOR);
        if( me->query("jingli") <= lvl1*3 )
                return notify_fail(HIY "你的精力不够使用「宁氏一剑」！\n"NOR);
        

		lvl3 = (target->query_skill("dodge",1) );
		lvl4 = (target->query_skill("force",1) );

        
        ap = (lvl1 + lvl2) + ((int)(me->query("neili")*40) + 1);

	    dp = (lvl3 + lvl4) + ((int)(target->query("neili")*30) + 1);

	    ap = ap/100;
        dp = dp/100;
	    if (wizardp(me))
		printf("ap = %d , dp = %d .\n",ap , dp);
        
		weapon = me->query_temp("weapon");
		
        dodge_skill = target->query_skill_mapped("dodge");

	    message_vision(HIY "$N突然间一声清啸，"+ weapon->name() +HIY"剑锋闪烁不定，围着$n身围疾刺，银光飞舞,猛地里$N一剑挺出\n\n"NOR, me, target);
		message_vision(HIY "直刺$n心口，当真是捷如闪电，势若奔雷。当真是捷如闪电，势若奔雷。。\n\n"NOR, me, target);
        if( me->query_temp("zixia",1) ) // 为以后开运紫霞做好准备
		message_vision(MAG "$N将紫霞神功发挥到极致，只觉得内力源源不断的输送到剑身，手上剑招已是迅若雷快如电。\n\n"NOR, me, target);
		me->add("neili" , -(lvl1+lvl2)/3);
	    me->add("jingli", -(lvl1+lvl2)/4);
        me->set_temp("yijian",1);
		
     
        call_out("delay",1800/(lvl1+lvl2),me);

        me->add_temp("yijian",1);
        if (random(ap) < dp ) {
                message_vision(WHT "$n见状大惊，想要格挡无耐此剑挟雷电之势已然刺到胸前,$n全力施展"+ to_chinese(dodge_skill) +"才堪力躲过了这一剑！\n\n" NOR, me,target);
       	        me->start_busy(3+random(3));
                return 1;
        }
        if (random (ap) > dp/2 ) {
                
                damage=(me->query_str()+me->query("jiali")/10)*lvl2/100*(9+random(21));
				
                me->add("neili" , -(lvl1+lvl2)/3);
	            me->add("jingli", -(lvl1+lvl2)/4);
                
                
                if ((int)damage/target->query("eff_qi")*100>=100) {
                        
                        message_vision(HIR "$N右手向前疾送，"+ weapon->name() +HIR"护手已碰到$n的胸膛，$n一声惨叫这一剑已在$n胸前穿过，直没至柄。。\n\n" NOR, me,target);
						target->die();
                        return 1;
                }
                if ((int)damage/target->query("eff_qi")*100>=50&&(int)damage/target->query("eff_qi")*100<100)
					   
                        message_vision(HIR "$n忙纵身闪躲，但还是被$N所发出的凌厉剑气所伤，只听“嗤”的一声没入胸口，鲜血如泉涌般喷出。。\n\n" NOR, me,target);
                if ((int)damage/target->query("eff_qi")*100<50)
					    
                        message_vision(HIR "这一剑势道之凌厉，端的是匪夷所思，只是闪电般一亮，$n已被刺中胸膛，鲜血如泉涌般喷出。\n\n" NOR, me,target);
                target->receive_damage("qi",damage,me);
                target->receive_wound("qi", damage, me);
                str = COMBAT_D->status_msg((int)target->query("eff_qi") * 100 /(int)target->query("max_qi"));
                message_vision("($N"+str+")\n", target);
                return 1;
        }
        if (random(ap) > dp/3 ) {
                damage=me->query_str()*me->query("jiali")/target->query_con();
				
                
                 if (damage<=100) message_vision(WHT "$n$n见这一剑来势凶猛，急忙避开,但已吓得一身冷汗。\n\n" NOR, me,target);
				 
                 else {
					    
                        // 加力效果体现紫霞功，以后可改为yun zixia 体现效果, 不加力对手busy 
					
				        message_vision(WHT "$n心知这一剑内力浑厚奋力闪躲。虽然避过了致命一击，不了$N这一剑用上了"+MAG"紫霞神功"NOR+WHT"剑气已在$n胸口划出一道伤口。\n\n" NOR, me,target);
                        
						target->receive_damage("qi",damage,me);
                        str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
                        message_vision("($N"+str+")\n", target);
                }
                target->start_busy(3+random(3));
                me->add("neili" , -(lvl1+lvl2)/3);
	            me->add("jingli", -(lvl1+lvl2)/4);
                return 1;
        }
        
}

int delay(object me)
{
        me->delete_temp("yijian");
        return 1;
}
