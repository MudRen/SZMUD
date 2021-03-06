// Cracked by Jiuer
// huakai.c 绵掌之「花开并蒂」
// xQin 11/00
// by snowyu 增加内力限制

//修改描述, 计算率, 成功率, 多重失败的定义, 以及双方制衡的描述

#include <ansi.h>
inherit F_SSERVER;

void remove_effect(object me);

int perform(object me, object target)
{       
        string msg;
        int skill;
        
        if( !target ) target = offensive_target(me);
        
        if( !target
    ||  !target->is_character()
    ||  !me->is_fighting(target) )
        return notify_fail("花开并蒂只能带动战斗中的对手。\n");
                
                if( me->query_temp("mian-zhang/yunhuakai") )
                                return notify_fail("你现在不能使出「花开并蒂」。\n");

    if( me->query_temp("yield") )
                return notify_fail("你不出掌，怎么能出「花开并蒂」？\n");

        if( me->query_temp("huakai"))
                return notify_fail("你已经在出「花开并蒂」了。\n");
        
        if( objectp(me->query_temp("weapon")) ) 
                return notify_fail("空手才能施展花开并蒂！\n");
        
        if( me->query_skill_mapped("strike") != "mian-zhang" )
                return notify_fail("你所用的并非花开并蒂，不能施展花开并蒂！\n");

        if( me->query_skill_prepared("strike") != "mian-zhang" )
        return notify_fail("你所备的并非花开并蒂，不能施展花开并蒂！\n");

        if( me->query_skill_mapped("force") != "taiji-shengong" )   // i add
                return notify_fail("你所用的并非太极神功，使不出花开并蒂！\n");

        if( me->query_skill("mian-zhang", 1) < 99)
                return notify_fail("你的绵掌不够纯熟，尚未能出此绝招。\n");
        
        if( me->query_skill("taiji-shengong", 1) < 79)
                return notify_fail("你的太极神功修为不够，不能出「花开并蒂」。\n");
        if (me->query("max_neili") < 500)
                return notify_fail("你的内力修为不足,无法使用「花开并蒂」\n");
        if (me->query("neili") < 300)
                return notify_fail("你的内力不够,无法使用「花开并蒂」\n");
        if( (int)me->query("jiali") > 2 || (int)me->query("jiajin") > 2)
                return notify_fail("你发现加力后无法把绵掌中若有若无，借力打力的要决发挥出来。\n");
                
//        msg = HIM "\n$N一招「花开并蒂」左手挥掌猛击$n的右颊，右手出指疾点$n的「缺盆穴」。\n"NOR;
//        msg += "这一掌“花开并蒂”，巧运内功掌式微转，但掌风猛增，将敌手拍的犹如飞花翻舞。\n\n";
		msg = HIW"\n$N双掌一翻，使出一招「云手」，双掌柔到了极处，空明若虚，将$n的外家莽劲尽数化去。\n同时，下盘却已进“未济”，又进“复”位，再进“震”位，左掌「拨云见日」，向旁掠出，\n$n只觉一股劲气扑面而来，不得不跃开半步，转入守势。\n\n"NOR;
		
		msg += HIY"紧接着，$N下盘疾退“无妄”，双掌同时抱元归一，$n见你复入守势，大惑不解，确已不及细想，\n大喝一声向$N攻来。$N上盘采的是守势，下盘却步步进逼，左腿「横云断峰」，掠地扫去，\n$n一惊，向后掠开，已然让$N抢入“讼”位，$n攻不得，守不得，顿时陷入险恶之境。\n\n"NOR;
		msg += HIC"$N猛提一口真气，右掌蓄势，左掌向$n心口直直拍出，内家真力发出破空之声，随掌而至。\n"NOR;
		msg += HIW"这以攻复守，以守诱敌，暗合阴阳消长之律，最后以浑厚真力伤敌，掌风中暗藏两记杀招，\n这一路招式，即是武当绝学" + HIM + "「花开并蒂」。\n\n"NOR;


        message_vision(msg, me, target); 

        me->add("neili", -50);
        me->add("jingli", -40);
        me->set_temp("huakai/using", 1);
        me->set_temp("huakai/target", target);
        me->start_busy(1);

        call_out("huakai", 1, me, target);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me:), skill/15);

        return 1;
}

int huakai(object me, object target)
{
        int damage, tjsg, mz, nl, skill;
        
        if( !me->is_fighting(target) || !living(target) ) 
        {       
                remove_effect(me);
		if (wizardp(me))
		tell_object(me,HIR"attack!!\n"NOR);
                return;
        }
  else 
  {
        tjsg = (int)me->query_skill("taiji-shengong");
        mz = (int)me->query_skill("strike");
        nl = (int)me->query("neili");



		if( me->query("combat_exp") > target->query("combat_exp") * 2)
		{
			damage = mz * 3 + tjsg * 3 + random(400);

			message_vision(HIR"$n只觉退无可退，避无可避，突见左侧似有生机一线，不由抢攻向左。\n"NOR, me, target);
			message_vision(HIR"$N见$n向左躲闪，早已蓄势的右掌陡然拍出，后发先至，震向$n左肩，同时左掌也以攻到，震中$n胸口。只听一声巨响，$n向后竟直飞出数丈之远。\n"NOR, me, target);

			target->receive_damage("qi", damage, me);
            target->receive_wound("qi", damage/2, me);
            target->add("neili", -(damage/3));
			COMBAT_D->report_status(target);
			me->add("neili", -200 + random(40));
			me->delete_temp("huakai");
			target->start_busy(random(2));
			me->start_busy(1 + random(2));
			return 1;
		}

		else if( me->query_skill("force") * me->query("neili") / 100 > target->query_skill("force") * target->query("neili") / 250)
		{
			damage = mz*2 + tjsg*2 + random(300);

			message_vision(HIY"$n只觉退无可退，避无可避，只得运功硬挺这记杀招。$N见$n竟不退不避，「花开并蒂」的第二记杀招竟也无法使出。\n"NOR, me, target);
			message_vision(HIR"$N左掌震向$n胸口，只听一声轻响，$n站立不稳，向后踉跄了数步方才站定。\n"NOR, me, target);

			target->receive_damage("qi", damage, me);
            target->receive_wound("qi", damage/2, me);
            target->add("neili", -(damage/3));
			COMBAT_D->report_status(target);
			me->add("neili", -damage/10);
			me->delete_temp("huakai");
			target->start_busy(1 + random(2));
			me->start_busy(1 + random(2));
			return 1;
		}

		else
		{
			switch(random(3))
			{
			case 0:
				message_vision(HIR"$n只觉退无可退，避无可避，只得运得全身内劲，出招硬接。\n"NOR, me, target);
				message_vision(HIR"一声巨响之后，两人同时向后飞出，看来都伤得不轻。\n"NOR, me, target);
				
				target->receive_damage("qi", 200 + random(200), me);
				target->receive_wound("qi", 200 + random(200), me);
				target->add("neili", -200 + random(200));
				
				me->receive_damage("qi", 200 + random(200), me);
				me->receive_wound("qi", 200 + random(200), me);
				me->add("neili", -200 + random(200));

				COMBAT_D->report_status(target);
				COMBAT_D->report_status(me);
				me->add("neili", -damage/10);
				me->delete_temp("huakai");
				
				target->start_busy(2 + random(2));
				me->start_busy(2 + random(2));
				break;

			case 1:
				message_vision(HIR"$n只觉退无可退，避无可避，只得运得全身内劲，出招硬接。\n"NOR, me, target);
				message_vision(HIR"一声巨响之后，两人同时向后飞出，看来都伤得不轻。\n"NOR, me, target);
				
				target->receive_damage("qi", 200 + random(200), me);
				target->receive_wound("qi", 200 + random(200), me);
				target->add("neili", -200 + random(200));
				
				me->receive_damage("qi", 200 + random(200), me);
				me->receive_wound("qi", 200 + random(200), me);
				me->add("neili", -200 + random(200));

				COMBAT_D->report_status(target);
				COMBAT_D->report_status(me);
				me->add("neili", -damage/10);
				me->delete_temp("huakai");

				target->start_busy(2 + random(2));
				me->start_busy(2 + random(2));
				break;
			case 2:
    message_vision(HIC"\n只觉退无可退，避无可避，只能就地扑倒，翻身滚开，样子狼狈之至。$N不料$n会以这种招式躲闪，又是好气，又是好笑，只得收招而退。\n"NOR, me, target );
				me->add("neili", -100);
				me->delete_temp("huakai");
				me->start_busy(2 + random(3));
				break;
			case 3:
				message_vision(HIC"\n只觉退无可退，避无可避，只能就地扑倒，翻身滚开，样子狼狈之至。$N不料$n会以这种招式躲闪，又是好气，又是好笑，只得收招而退。\n"NOR);
				me->add("neili", -100);
				me->delete_temp("huakai");
				me->start_busy(2 + random(3));
				break;
			}


			return 1;
		}
	}
}

		/*
        if( random(me->query_skill("taiji-shengong") * me->query("neili")/100 > 
                (int)target->query_skill("force") * (int)target->query("neili") /200 ) )
        {
                damage = mz + tjsg/random(2);
                
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/2, me);
                target->add("neili", -(damage/3));

                me->add("neili", -damage/10);
            me->delete_temp("huakai");
                return 1;
        }
        else
        {
                me->start_busy(1+random(2));
                damage = mz + tjsg/random(3);
                
                message_vision(RED"结果只见$p轻哼一声，后退三步，吐出了一口鲜血。\n"NOR, me, target);
                
                if(wizardp(me))
            tell_object(me,sprintf("damage : %d  \n", damage));
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/3, me);
                target->add("neili", -(damage/4));
                
                me->add("neili", -damage/9);
                me->delete_temp("huakai");

                                
                                //ADD BY SCATTER  1/4/2002
                                COMBAT_D->report_status(target);

                return 1; 
        }
  }
}

  */

void remove_effect(object me)
{
  object target;

  if( me->query_temp("huakai") )
  {
    target = me->query_temp("huakai/target");
    me->delete_temp("huakai");
    if( me->is_fighting() )
      message_vision(HIY "\n$n慢慢的适应了$P花开并蒂的掌风。\n" NOR, me, target);
  }
}
