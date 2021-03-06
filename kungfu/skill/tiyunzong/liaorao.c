/***********************************************************************************
creat by Karlopex@sz
by 21/05/2002
梯云纵：perform liaorao （云雾缭绕）
                  条件：梯云纵150级，太极神功150级。
                  功能：增中jifa dodge 15%。
                        有效时间：5-10 tick。
                  描述：空缺

************************************************************************************/
#include <combat.h>
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
void remove_effect(object me, object target, int lvl1, int lvl2);
void chkpfm(object me, object target, int lvl1, int lvl2);
int perform(object me, object target)
{
        string msg;
	int lvl1, lvl2, amount;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「云雾缭绕」轻功绝技只能对战斗中的对手使用。\n");

        if( me->query_temp("tyz-liaorao") )
                return notify_fail("你正在运用「云雾缭绕」轻功绝技！\n");

        if( me->query_skill_mapped("force") != "taiji-shengong")
                return notify_fail("你所用的内功与「云雾缭绕」轻功绝技运气方式相悖！\n");

        if( me->query_skill_mapped("dodge") != "tiyunzong")
                return notify_fail("你所用的身法与「云雾缭绕」招式不同，无法使用！\n");
                
        if( me->query_skill("dodge") < 149 )
                return notify_fail("你的身法修为不够，还无法施展「云雾缭绕」轻功绝技！\n");
                
        if( me->query_skill("force") < 149 )
                return notify_fail("你的内功修为火候未到，无法施展「云雾缭绕」轻功绝技！\n");

        if( me->query("neili") < 600 )
                return notify_fail("你的内力不够，劲力不足以施展「云雾缭绕」轻功绝技！\n");
        
        msg = MAG "$N运起太极神功，$N的身影犹如云雾一般，在$N的身旁飘忽不定。\n\n" NOR;

        lvl1 = (int)me->query_skill("dodge");
        lvl2 = (int)me->query_skill("force");

        me->add_temp("apply/dodge", lvl1 / 10);
        me->add_temp("apply/speed", (lvl1 + lvl2)/25);
        me->add_temp("apply/defense", lvl1 / 15);
	
        me->add("neili", -(lvl1+lvl2) / 3);
        me->add("jingli", -(lvl1+lvl2) / 4);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, target, lvl1, lvl2:), (lvl1+lvl2)/30);
        message_vision(msg, me);
        me->set_temp("hssf-yanhui",1);
        return 1;
}

void remove_effect(object me, object target, int lvl1, int lvl2)
{
        if (!me) return;
	if( me->is_fighting())
		message_vision(HIY "\n$N深吸一口气，收回「云雾缭绕」轻功绝技，$n顿时感到压力减轻了不少。\n" NOR, me, target);
	else message_vision(HIY "\n$N见胜负已分，便收回了「云雾缭绕」轻功绝技。\n" NOR, me, target);
        me->delete_temp("hssf-yanhui",1);
        me->add_temp("apply/dodge", -lvl1 / 10);
        me->add_temp("apply/speed", -(lvl1 + lvl2)/25);
        me->add_temp("apply/defense", -lvl1 / 15);
}

void check(object me, object target, int lvl1, int lvl2)
{
        if (!me) return;
	else if( !me->is_fighting()){	
		remove_effect(me, target, lvl1, lvl2);
		return;
        }else if( me->query_skill_mapped("dodge") != "tiyunzong"){
		message_vision(HIY "\n$N的轻功已经不再是武当的梯云纵，「云雾缭绕」轻功绝技顿时消失。\n" NOR, me, target);    	
		remove_effect(me, target, lvl1, lvl2);
		return;
	}
	call_out("check", 1, me, target, lvl1, lvl2);
}

