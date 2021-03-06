/* 他当即将紫霞神功都运到了剑上，呼的一剑，当头直劈。令狐冲斜身闪开。岳不群圈 
转长剑，拦腰横削。令狐冲纵身从剑上跃过。岳不群长剑反撩，疾刺他后心，这一剑变招 
快极，令狐冲背后不生眼睛，势在难以躲避。众人"啊"的一声，都叫了出来。令狐冲身 
在半空，既已无处借势再向前跃，回剑挡架也已不及，却见他长剑挺出，拍在身前数尺外 
的木柱之上，这一借力，身子便已跃到了木柱之后，噗的一声响，岳不群长剑刺入木柱。 
剑刃柔韧，但他内劲所注，长剑竟穿柱而过，剑尖和令狐冲身子相距不过数寸。 
    众人又都"啊"的一声。这一声叫唤，声音中充满了喜悦、欣慰和赞叹之情，竟是人 
人都不禁为令狐冲欢喜，既佩服他这一下躲避巧妙之极，又庆幸岳不群终于没刺中他。岳 
不群施展平生绝技，连环三击，仍然奈何不了令狐冲，又听得众人的叫唤，竟是都在同情 
对方，心下大是懊怒。这"夺命连环三仙剑"是华山派剑宗的绝技，他气宗弟子原本不知 
。当年两宗自残，剑宗弟子曾以此剑法杀了好几名气宗好手。当气宗弟子将剑宗的弟子屠 
戮殆尽、夺得华山派掌门之后，气宗好手仔细参详这三式高招"夺命连环三仙剑"。诸人 
想起当日拚斗时这三式连环的威力，心下犹有余悸，参研之时，各人均说这三招剑法入了 
魔道，但求剑法精妙，却忘了本派"以气驭剑"的不易至理，大家嘴里说得漂亮，心中却 
无不佩服。*/
//Cracked by Kafei
//duoming.c 夺命连环三仙剑 
#include <combat.h>
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
void chkpfm(object me, object target, int amount);
int perform(object me, object target)
{
        object weapon, weapon1;
        int lvl1, lvl2, amount, amount2;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("夺命连环三仙剑只能对战斗中的对手使用。\n");

        weapon = me->query_temp("weapon");
        if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
                return notify_fail("你手中无剑，如何使得夺命连环三仙剑？\n");

        if (!living(target))
                return notify_fail("他已经晕倒了，你可以轻易地杀了他！\n");
	if( me->query_temp("kuaijian",1) ) 
		return notify_fail("你正在使用「狂风快剑」!"); 
	
	if( me->query_temp("yijian",1) ) 
		return notify_fail("你正在使用「宁氏一剑」!"); 

        if( me->query_skill_mapped("force") != "zixia-gong" )
                return notify_fail("你所用的并非紫霞功，无法施展夺命连环三仙剑！\n");

        if( (lvl1=me->query_skill("zixia-gong", 1)) < 100 )
                return notify_fail("你的紫霞功火候未到，无法施展夺命连环三仙剑！\n");

        if( (lvl2=me->query_skill("sword")) < 200 )
                return notify_fail("你华山剑法修为不足，还不会使用夺命连环三仙剑！\n");

        if( (lvl2 - lvl1) < lvl2 / 4 && lvl1 < 200)
                return notify_fail("夺命连环三仙剑需要更精湛的剑术！\n");

        amount = lvl2 * (1 + random(2));

        if ( amount < 500 ) amount = 500;
        if ( amount > 1500 ) amount = 1500;

        if( me->query("neili") <= amount )
                return notify_fail("你的内力不够使用夺命连环三仙剑！\n");
        if( me->query("jingli") <= amount )
                return notify_fail("你的精力不够使用夺命连环三仙剑！\n");

        me->set_temp("sxj-c" , 1);
        message_vision(HIR "\n$N"+HIR+"鼓荡内劲，凝气聚于"+weapon->name()+HIR+"上，忽出杀着，一剑朝$n"+HIR+"当头直劈！！\n" NOR, me, target);
        chkpfm(me, target, amount);
	if(me->query_temp("sxj-d")=="fail_all"){
	        if (amount > 1000) amount2 = 1000;
	        me->add("jingli",-amount2 / 9);
	        me->add("neili",-amount2 / 6);
	        me->start_busy( 1+random(1) );
	        return 1;
	}
        me->set_temp("sxj-c" , 2);
        message_vision(HIW "\n$N"+HIW+(me->query_temp("sxj-d")=="ok"?"":"一剑不中，")+"次招随至，电光石火间圈转"NOR+weapon->name()+HIW"，朝$n"+HIW+"拦腰横削！！\n" NOR, me, target);
        chkpfm(me, target, amount);
	if(me->query_temp("sxj-d")=="fail_all"){
	        if (amount > 1000) amount2 = 1000;
	        me->add("jingli",-amount2 / 5);
	        me->add("neili",-amount2 / 3);
	        me->start_busy( 1+random(2) );
	        return 1;
	}
        me->set_temp("sxj-c" , 3);
        message_vision(HIY "\n$N"+HIY+"剑势连环，"+weapon->name()+HIY"反撩，疾刺$n"+HIY+"后心，这一剑变招极快，$n背后不生眼睛，势在难以躲避！！\n" NOR, me, target);
        chkpfm(me, target, amount);
        if((int)target->query("eff_qi") * 100 /(int)target->query("max_qi") <= 5
         && (int)target->query("qi") * 100 /(int)target->query("max_qi") <= 1
         && me->query_temp("sxj-c") == 3 && me->query_temp("sxj-d") == "ok")
        {
                message_vision(HIR "\n$N"+HIR+"这招内劲所注，力道强横之极，"+weapon->name()+HIR+"竟穿体而过，剑尖刺出$n"+HIR+"前胸数寸！！\n" NOR, me, target);
		target->receive_damage("qi", amount * 100, "被"+me->name()+"用夺命连环三仙剑一剑穿体刺死了！"); 
                if (wizardp(me))
                        tell_object(me,HIR"super attack!!\n"NOR);
        }
        if (amount > 1200) amount2 = 1200;
        me->add("jingli",-amount2 / 3);
        me->add("neili",-amount2 / 2);
	me->start_busy( 1+random(3) );
        return 1;
}
void chkpfm(object me, object target, int amount)
{
        object weapon2 = target->query_temp("weapon");
        string attack_skill, dodge_skill, parry_skill, result, sword_skill, msg = "";
        object weapon = me->query_temp("weapon");
        int ap, dp, pp, damage, level, level2;

        if( !me->is_fighting(target) || !living(target) ) 
                return;

        level = me->query_skill("sword");
        level2 = target->query_skill("sword");
        damage = amount * (1 + random(level / 150));
	sword_skill = target->query_skill_mapped("sword");
        ap = COMBAT_D->skill_power(me, "sword", SKILL_USAGE_ATTACK);
        if( ap < 1) ap = 1;
        dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
        if( target->is_busy() ) dp /= 3;
        if( dp < 1 ) dp = 1;
	if( level2*1/2 > level || (sword_skill == "dugu-jiujian" && level2 > 500)){
		msg += HIY"$n已经看破$N的连环剑招，";
		switch(random(2)){
			case 1:
		                dodge_skill = target->query_skill_mapped("dodge");
		                if( !dodge_skill ) dodge_skill = "dodge";
                		msg += "使出"+to_chinese(dodge_skill)+"的身法将$N的连环剑势躲了过去。\n"NOR+SKILL_D(dodge_skill)->query_dodge_msg();
				me->set_temp("sxj-d","fail_all");
				break;
			case 2:
				if( weapon2 ){
			                parry_skill = target->query_skill_mapped("parry");
			                if( !parry_skill ) parry_skill = "parry";
	                		msg += "使出"+to_chinese(parry_skill)+"的隔档之法将$N的连环剑势档住了。\n"NOR+SKILL_D(parry_skill)->query_parry_msg(weapon2, target);
					me->set_temp("sxj-d","fail_all");
				}else{
			                dodge_skill = target->query_skill_mapped("dodge");
			                if( !dodge_skill ) dodge_skill = "dodge";
	                		msg += "但$N剑势猛烈，空手无法隔挡，$n只好施展轻功躲避。\n"NOR;
					if( random(ap + dp) < random(dp*2) ){
						msg += SKILL_D(dodge_skill)->query_parry_msg();
						me->set_temp("sxj-d","fail_all");
					}else{
	                			msg += "$n还未来得及躲闪，$N的"+weapon->name()+"发招而至，剑势猛烈如初。\n"NOR;
			                        target->receive_damage("qi", damage/3, me);
			                        target->receive_wound("qi", damage/6, me);
			                        if (me->query_temp("sxj-c") == 3)
			                                result = COMBAT_D->damage_msg(damage, "刺伤");
			                        else result = COMBAT_D->damage_msg(damage, "劈伤");
			                        msg += result;
			                        result = COMBAT_D->status_msg((int)target->query("qi") * 100 /
			                                (int)target->query("max_qi"));
			                        msg += "( $n"+result+" )\n";
						me->set_temp("sxj-d","ok");
			                } 
				}
				break;
		}
        }else if( random(ap + dp) < random(dp*3/2) ){
                dodge_skill = target->query_skill_mapped("dodge");
                if( !dodge_skill ) dodge_skill = "dodge";
                msg += SKILL_D(dodge_skill)->query_dodge_msg();
		me->set_temp("sxj-d","fail");
        }else{
                pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);
                if( target->is_busy() ) pp /= 2;
                if( pp < 1 ) pp = 1;

                if( random(ap + pp) < random(pp*3/2) )
                {
 			
                        parry_skill = target->query_skill_mapped("parry");
                        if( !parry_skill || !SKILL_D(parry_skill)->parry_available()) 
                                parry_skill = "parry";
                        msg += SKILL_D(parry_skill)->query_parry_msg(weapon2, target);
			me->set_temp("sxj-d","fail");
                }else{
                        target->receive_damage("qi", damage, me);
                        target->receive_wound("qi", damage/3, me);
                        if (me->query_temp("sxj-c") == 3)
                                result = COMBAT_D->damage_msg(damage, "刺伤");
                        else result = COMBAT_D->damage_msg(damage, "劈伤");
                        msg += result;
                        result = COMBAT_D->status_msg((int)target->query("qi") * 100 /
                                (int)target->query("max_qi"));
                        msg += "( $n"+result+" )\n";
			me->set_temp("sxj-d","ok");
                }
        }
        if (me->query_temp("sxj-c") == 1)
                msg = replace_string( msg, "$l", "头顶" );
        if (me->query_temp("sxj-c") == 2)
                msg = replace_string( msg, "$l", "腰间" );
        if (me->query_temp("sxj-c") == 3)
                msg = replace_string( msg, "$l", "后心" );
        msg = replace_string( msg, "$w", (me->query_temp("weapon"))->name());
        message_vision(msg, me, target);
}
