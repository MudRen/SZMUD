/*
狂风快剑

封不平仰天一声清啸，斜行而前，长剑横削直击，迅捷无比，未到五六招，剑势中已发出隐隐风声。
封不平吸一口气，登时连环七剑，一剑快似一剑，如风如雷般攻上。
封不平脸上一红，一柄长剑更使得犹如疾风骤雨一般。
封不平长剑连划三个弧形，险些将自己右臂齐肩斩落，实在凶险之极
*/
#include <ansi.h>
#include <skill.h>
#include <combat.h>

inherit F_DBASE;
inherit F_SSERVER;

void force_finish(object me, int damage, int attack, int speed, int mem_damage, int mem_attack, int mem_speed);
void check_attack(object me, object target, int damage, int attack, int speed, int mem_damage, int mem_attack, int mem_speed);
void remove_effect(object me, int damage, int attack, int speed, int mem_damage, int mem_attack, int mem_speed);

int perform(object me, object target)
{
        object weapon, weapon1 ;
        string msg;
        int level, mem_speed, mem_attack, mem_damage, attack, damage, speed;
        object tester = find_player("snowyu");

        if (!target) target = offensive_target(me);

        
		weapon = me->query_temp("weapon");

//         if(me->query("huashan_kuaijian")!=1 && !wizardp(me))
//                 return notify_fail(HIC "你为经高人指点还不会使用「狂风快剑」！\n"NOR);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HIC "「狂风快剑」只能对战斗中的对手使用。\n"NOR);

		if ( me->query("family/family_name") != "华山派" && (!wizardp(me)) )
                return notify_fail(HIC "你非华山弟子，如何使用华山剑宗绝学！\n"NOR);

        if( me->query_temp("kuaijian",1) )
                return notify_fail(HIC "你已在使用「狂风快剑」！\n"NOR);
        if( me->query_temp("yijian",1) )
                return notify_fail(HIC "你正在使用「宁氏一剑」！\n"NOR);
        if( me->query_temp("sanxianjian",1) )
                return notify_fail(HIC "你正在使用「夺命连环三仙剑」！\n"NOR);
        if( me->query_skill_mapped("force") != "zixia-gong" && !wizardp(me))
                return notify_fail(HIC "你所用的并非紫霞神功，无法施展「狂风快剑」！\n"NOR);
		
		if( me->query_skill("ziyin-yin",1) <101 )
                return notify_fail(HIC "你紫氤吟修为不足，还不会使用「狂风快剑」！\n"NOR);

		if( me->query_skill("zhengqi-jue",1) <101 )
                return notify_fail(HIC "你的正气诀修为不足，还不会使用「狂风快剑」！\n"NOR);

        if( me->query_skill("zixia-gong", 1 ) < 120 )
                return notify_fail(HIC "你的紫霞神功火候未到，无法施展「狂风快剑」！\n"NOR);

	    if( me->query_skill_mapped("parry") != "huashan-jianfa" )
                return notify_fail(HIC "你没有将华山剑法运用于招架中，无法施展「狂风快剑」！\n"NOR);

        if( (level = (int)me->query_skill("huashan-jianfa", 1)) < 120 )
                return notify_fail(HIC "你的华山剑法修为不足，还不会使用「狂风快剑」！\n"NOR);
		
		if( me->query("neili") <= 800)
                return notify_fail(HIC "你的内力不够使用「狂风快剑」！\n"NOR);
        
		if( me->query("jingli") <= 800 )
                return notify_fail(HIC "你的精力不够使用「狂风快剑」！\n"NOR);
       
        if( me->query_str() < 35 ) 
			   return notify_fail(HIC "你天生两臂无力，无法运剑成风！\n" NOR);

        if( me->query_con() < 35 ) 
			   return notify_fail(HIC "你气嘘体弱，无法运剑成风！\n" NOR);
        
		if( me->query_dex() < 35 ) 
			   return notify_fail(HIC "你身形呆胖，无法运剑成风！\n" NOR);

		
        
        message_vision(HIR"$N仰天一声清啸，斜行而前，"+ weapon->name() +HIR"横削直击，迅捷无比，剑势中已发出隐隐风声,正是华山剑宗绝学「狂风快剑」!\n" NOR, me);

        level = (int)me->query_skill("huashan-jianfa", 1); 
        mem_attack = (int)me->query_temp("apply/attack",1);
        mem_damage = (int)me->query_temp("apply/damage",1);
        mem_speed = (int)me->query_temp("apply/speed",1);
        speed = level/2 + random(level/2); // 狂风快剑强调速度
        attack = level/5 + random(level/2);
        damage = level/5 + random(level/2);
        me->add("neili", -500);
        me->add("jingli", -300);
        me->set_temp("kuaijian", 1);
        me->add_temp("apply/attack", attack);
        me->add_temp("apply/damage", damage);
        me->add_temp("apply/speed", speed);
        //检查用
        if (wizardp(me)) 
	    tell_object(me, sprintf(WHT"原本攻击力：%d，原本命中率：%d，原本速度：%d，增加攻击力：%d，增加命中率：%d，增加速度：%d。\n"NOR, mem_damage, mem_attack, mem_speed, damage, attack, speed));

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("kuaijian", 2);
        me->start_call_out( (: call_other, __FILE__, "check_attack", me, target, damage, attack, speed, mem_damage, mem_attack, mem_speed :), 1);
        me->start_call_out( (: call_other, __FILE__, "force_finish", me, damage, attack, speed, mem_damage, mem_attack, mem_speed :), 14);
        return 1;
}
void force_finish(object me, int damage, int attack, int speed, int mem_damage, int mem_attack, int mem_speed)
{
        if (wizardp(me)) tell_object(me, "强迫停止\n");
        if (me->query_temp("kuaijian"))
        {
                
                me->delete_temp("kuaijian");
                me->add_temp("apply/speed", -speed);
                me->add_temp("apply/attack", -attack);
                me->add_temp("apply/damage", -damage);
                me->start_busy(1);
                
                if (wizardp(me)) tell_object(me, sprintf(WHT "调节后：原本攻击力：%d，原本命中率：%d，原本速度：%d，目前攻击力：%d，目前命中率：%d，目前速度：%d。\n"NOR, mem_damage, mem_attack, mem_speed, me->query_temp("apply/damage"), me->query_temp("apply/attack"), me->query_temp("apply/speed")));
                if((int)me->query_temp("apply/speed",1) != mem_speed)
                {
                        me->set_temp("apply/speed",mem_speed);
                }
                if((int)me->query_temp("apply/attack",1) != mem_attack)
                {
                        me->set_temp("apply/attack",mem_attack);
                }
                if((int)me->query_temp("apply/damage",1) != mem_damage)
                {
                        me->set_temp("apply/damage",mem_damage);
                }
                if (wizardp(me)) 
				tell_object(me, sprintf(WHT "再调节：原本攻击力：%d，原本命中率：%d，原本速度：%d，目前攻击力：%d，目前命中率：%d，目前速度：%d。\n"NOR, mem_damage, mem_attack, mem_speed, me->query_temp("apply/damage"), me->query_temp("apply/attack"), me->query_temp("apply/speed")));
        }
}
void check_attack(object me, object target, int damage, int attack, int speed, int mem_damage, int mem_attack, int mem_speed)
{
        int used, max_use;
        max_use = 1 + (int)me->query_skill("huashan-jianfa", 1)/80;
        used = me->query_temp("kuaijian");

        if (!target || !me->is_fighting(target)) target = offensive_target(me);
        if (used > max_use || used > 5)
        {
                message_vision(HIC "\n$N深吸一口气，将剑势慢慢收回。\n"NOR, me);
                remove_effect(me, damage, attack, speed, mem_damage, mem_attack, mem_speed);
                me->start_busy(1);
               
                return;
        }
        if (!living(me) || me->is_ghost())
        {
                remove_effect(me, damage, attack, speed, mem_damage, mem_attack, mem_speed);
                return ;
        }
        if( !me->is_fighting() )
        {
                message_vision(HIC "\n$N深吸一口气，将剑势慢慢收回。\n"NOR, me);
                remove_effect(me, damage, attack, speed, mem_damage, mem_attack, mem_speed);
               

                return;
        }
        if (me->query_skill_mapped("force") != "zixia-gong")
        {
                message_vision(HIR "\n$N中途转换内功心法，一口气提不起来。\n"NOR, me);
                message_vision(WHT "\n$N脸色突然转白，跟着口吐"NOR MAG"紫血"NOR WHT"。\n"NOR, me);
                me->receive_damage("qi", 800, "吐血身亡");
                me->receive_damage("jingli", 1000, "吐血身亡");
                me->add("eff_qi",-300);
                remove_effect(me, damage, attack, speed, mem_damage, mem_attack, mem_speed);
                return;
        }
        
        if (me->query_skill_mapped("dodge") != "huashan-shenfa" && "dugu-jiujian")
        {
                message_vision(WHT "\n$N脚步一个不稳，只感气血不顺，只好收回剑势。\n"NOR, me);
                remove_effect(me, damage, attack, speed, mem_damage, mem_attack, mem_speed);
                return;
        }
        if (me->query("neili") < 100)
        {
                message_vision(WHT "\n$N感觉到气血不顺，一口气提不起来，只好收回剑势。\n"NOR, me);
                remove_effect(me, damage, attack, speed, mem_damage, mem_attack, mem_speed);
                return;
        }
        if (!me->query_temp("kuaijian"))
        {
                remove_effect(me, damage, attack, speed, mem_damage, mem_attack, mem_speed);
                message_vision(HIC "\n$N深吸一口气，将剑势慢慢收回。\n"NOR, me);
                return;
        }
        call_out("check_attack", 1, me, target, damage, attack, speed, mem_damage, mem_attack, mem_speed);

        return;
}       
void remove_effect(object me, int damage, int attack, int speed, int mem_damage, int mem_attack, int mem_speed)
{
        if (!me) return;
        me->delete_temp("kuaijian");
        me->add_temp("apply/speed", -speed);
        me->add_temp("apply/attack", -attack);
        me->add_temp("apply/damage", -damage);
        if (wizardp(me)) tell_object(me, sprintf(WHT "原本攻击力：%d，原本命中率：%d，原本速度：%d，目前攻击力：%d，目前命中率：%d，目前速度：%d。\n"NOR, mem_damage, mem_attack, mem_speed, me->query_temp("apply/damage"), me->query_temp("apply/attack"), me->query_temp("apply/speed")));
        if((int)me->query_temp("apply/speed",1) != mem_speed)
        {
                me->set_temp("apply/speed",mem_speed);
        }
        if((int)me->query_temp("apply/attack",1) != mem_attack)
        {
                me->set_temp("apply/attack",mem_attack);
        }
        if((int)me->query_temp("apply/damage",1) != mem_damage)
        {
                me->set_temp("apply/damage",mem_damage);
        }
        if (wizardp(me)) tell_object(me, sprintf(WHT "再调节：原本攻击力：%d，原本命中率：%d，原本速度：%d，目前攻击力：%d，目前命中率：%d，目前速度：%d。\n"NOR, mem_damage, mem_attack, mem_speed, me->query_temp("apply/damage"), me->query_temp("apply/attack"), me->query_temp("apply/speed")));
        me->start_busy(1);
}
