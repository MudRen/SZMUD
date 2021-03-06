// Code of ShenZhou
// suxing.c 玉女素心
// by sdong
// modified by scatter for ShenZhou
// updated by april 2001.12.20
//modified by Slow 2002.3.20

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void remove_effect(object me, int skill);

int perform(object me, object target)
{
	string weapon;
	int lvli,original,shenfa,skill;
         int num1,num2;

//          if( me->query("gender") != "女性")
//              return notify_fail("玉女素心只能是女的用！\n");
	if( !target ) target = offensive_target(me);

/*
     if( !target     || !target->is_character() || !me->is_fighting(target) )
            return notify_fail("玉女素心只能对战斗中的对手使用。\n");
*/

	if( (int)me->query_temp("gm_suxin") ) 
		return notify_fail("你已经发动了玉女素心！\n");

	if( me->query_skill_mapped("force") != "yunu-xinjing" )
		return notify_fail("你所用的并非玉女心经，无法施展玉女素心！\n");

	if( me->query_skill("yunu-xinjing", 1) < 90 )
		return notify_fail("你的玉女心经火候未到，无法施展玉女素心！\n");

	if( me->query_skill("suxin-jue", 1) < 60 )
		return notify_fail("你的玉女心经火候未到，无法施展玉女素心！\n");

	if( me->query_skill("sword") < 135 )
		return notify_fail("你的玉女剑法修为不足，还不会使用玉女素心！\n");

	if( me->query("neili") < 500 )
		return notify_fail("你的内力不够使用玉女素心！\n");
	if( me->query("jingli") < 300 )
		return notify_fail("你的精力不够使用玉女素心！\n");
	message_vision(HIM "$N突然目光一黯，无悲无喜，招式却愈加婀娜潇洒，灵动飘逸！\n\n" NOR,me);
	skill = (me->query_skill("sword") + me->query_skill("suxin-jue",1)) /2;

//        me->add_temp("apply/attack", skill/5);
//        me->add_temp("apply/damage", skill/50);
         me->add_temp("apply/dodge", skill);
        me->add_temp("apply/parry", skill/2);

/*
	if( target && target->is_character() && me->is_fighting(target) ){
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	}
*/
        me->add("neili", -skill/5);
        me->add("jingli", -skill/10);
	me->set_temp("gm_suxin", 1);

        call_out("remove_effect", skill/5, me, skill);
	return 1;
}

void remove_effect(object me, int skill)
{
	if ( !me ) return;
        me->add_temp("apply/dodge", -skill);
        me->add_temp("apply/parry", -skill/2);

	me->delete_temp("gm_suxin");

	tell_object(me, HIM "你缓缓吸了一口气，收回玉女素心，一双眸子恢复了平时的光彩。\n" NOR);
}
