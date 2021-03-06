/***********************************************************************************
creat by Karlopex@sz
by 21/05/2002
华山身法perform yanhui （燕徊朝阳）
 条件：华山身法有效等级120，紫霞功有效等级120级。
 功能：提高临时jifa dodge 5%。
       有效时间：5-10 tick。
 限制：不可与独孤九剑同使。
       不可与yun zixia同使。

  描述：空缺
************************************************************************************/
#include <combat.h>
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
void remove_effect(object me, object target, int lvl1, int lvl2);
void check(object me, object target, int lvl1, int lvl2);
int perform(object me, object target)
{
        string msg;
	int lvl1, lvl2, amount;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「燕徊朝阳」轻功绝技只能对战斗中的对手使用。\n");

        if( me->query_temp("zixia/lvl"))
                return notify_fail("你已经施展出「紫霞神功」，无法再使用「燕徊朝阳」。\n");
                
        if( me->query_skill_mapped("sword") == "dugu-jiujian" )
                return notify_fail("「独孤九剑」的招式奇特，不溶于普通武功。\n");

        if( me->query_skill_mapped("parry") == "dugu-jiujian" )
                return notify_fail("「独孤九剑」的招式奇特，不溶于普通武功。\n");

        if( me->query_temp("hssf-yanhui") )
                return notify_fail("你正在运用「燕徊朝阳」轻功绝技！\n");

        if( me->query_skill_mapped("force") != "zixia-gong")
                return notify_fail("你所用的内功与「燕徊朝阳」轻功绝技运气方式相悖！\n");

        if( me->query_skill_mapped("dodge") != "huashan-shenfa")
                return notify_fail("你所用的身法与「燕徊朝阳」招式不同，无法使用！\n");
                
        if( me->query_skill("dodge") < 119 )
                return notify_fail("你的身法修为不够，还无法施展「燕徊朝阳」轻功绝技！\n");
                
        if( me->query_skill("force") < 119 )
                return notify_fail("你的内功修为火候未到，无法施展「燕徊朝阳」轻功绝技！\n");

        if( me->query("neili") < 600 )
                return notify_fail("你的内力不够，劲力不足以施展「燕徊朝阳」轻功绝技！\n");
        
        msg = MAG "$N运起紫霞功，紫气遍布周围，$N的身影犹如燕子一般在$n的身旁穿梭。\n\n" NOR;

        lvl1 = (int)me->query_skill("dodge");
        lvl2 = (int)me->query_skill("force");

        me->add_temp("apply/dodge", lvl1 / 12);
        me->add_temp("apply/speed", (lvl1 + lvl2)/24);
        me->add_temp("apply/defense", lvl1 / 16);
	
        me->add("neili", -(lvl1+lvl2) / 3);
        me->add("jingli", -(lvl1+lvl2) / 4);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, target, lvl1, lvl2:), (lvl1+lvl2)/20);
        message_vision(msg, me, target);
	call_out("check", 1, me, target, lvl1, lvl2);
        me->set_temp("hssf-yanhui",1);
        return 1;
}

void remove_effect(object me, object target, int lvl1, int lvl2)
{
        if (!me || !me->query_temp("hssf-yanhui")) return;
        if( me->is_fighting() && objectp(target))
		message_vision(HIY "\n$N深吸一口气，收回「燕徊朝阳」轻功绝技，$n顿时感到压力减轻了不少。\n" NOR, me, target);
        else if( me->is_fighting() && !objectp(target))
                message_vision(HIY "\n$N深吸一口气，收回「燕徊朝阳」轻功绝技。\n" NOR, me); 
        else message_vision(HIY "\n$N停住身形，深吸了一口气，收回了「燕徊朝阳」轻功绝技。\n" NOR, me, target);
        me->delete_temp("hssf-yanhui",1);
        me->add_temp("apply/dodge", -lvl1 / 12);
        me->add_temp("apply/speed", -(lvl1 + lvl2)/24);
        me->add_temp("apply/defense", -lvl1 / 16);
}

void check(object me, object target, int lvl1, int lvl2)
{
        if (!me) return;
	else if( !me->is_fighting()){	
		remove_effect(me, target, lvl1, lvl2);
		return;
        }else if( me->query_skill_mapped("dodge") != "huashan-shenfa"){
		message_vision(HIY "\n$N的轻功已经不再是华山身法，「燕徊朝阳」轻功绝技顿时消失。\n" NOR, me, target);    	
		remove_effect(me, target, lvl1, lvl2);
		return;
	}
	call_out("check", 1, me, target, lvl1, lvl2);
}

