// jue.c 「绝剑」
// by snowyu update 2002/4

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int i, level, attack, damage;

	weapon = me->query_temp("weapon");
	if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
		weapon = me->query_temp("secondary_weapon");

	if( !target && me->is_fighting() ) target = offensive_target(me);

	if( me->query_skill("emei-jian", 1) < 200 )
		return notify_fail("你的峨嵋剑法修为还不够，还未领悟「绝剑」！\n");

	if( me->query_skill("linji-zhuang", 1) < 200 )
		return notify_fail("你的内功修为火候未到，施展「绝剑」只会伤及自身！\n");

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("「绝剑」只能对战斗中的对手使用。\n");

	if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
		return notify_fail("你手中无剑，怎能运用「绝剑」？！\n");

	if( me->query_skill_mapped("force") != "linji-zhuang" )
		return notify_fail("你所用的内功与「绝剑」心法相悖！\n");

	level = me->query_skill("sword") / 75;
	if( me->query("max_neili") <= level*500 )
		return notify_fail("你的内力修为不足，劲力不足以施展「绝剑」！\n");

        if( me->query("neili") <= level*80 )
                return notify_fail("你的内力不够，劲力不足以施展「绝剑」！\n");

        if( me->query("jingli") <= level*60 )
                return notify_fail("你的精力有限，不足以施展「绝剑」！\n");

	if( me->query_temp("perform/miejian") )
		return notify_fail("你正在运用「灭剑」心法！\n");

	damage = ( me->query_skill("force") + me->query("neili")/20 + me->query("max_neili")/5 )/20;
	attack = ( me->query_skill("dodge") + me->query("jingli")/20 + me->query("max_jingli")/5 )/20
		 + me->query_dex()/5 + weapon->query("apply/damage")/2;

           if (damage > 200) damage=200;
           if (attack > 200) attack=200;
        me->add_temp("apply/damage", damage);
        me->add_temp("apply/attack", attack/2+random(80));
	me->add_temp("apply/speed", level*5);

	if( wizardp(me) ) tell_object( me,
		sprintf("damage: %d, attack: %d, speed: %d, neili cost: %d, jingli cost: %d",
		me->query_temp("apply/damage"), me->query_temp("apply/attack"),
		me->query_temp("apply/speed"), level*70, level*50) );

	for( i=0; i < level; i++ )
	{
		me->add_temp("perform/juejian", 1);
		COMBAT_D->do_attack(me, target, weapon);
	}
	message_vision(HIY"\n这几下交手，当真是兔起鹬落，迅捷无伦，一刹那间$N连攻了"+
		chinese_number(level) +"下快招，招招是致命的凌厉毒著！！\n"NOR, me);

        me->add_temp("apply/damage", -damage);
        me->set_temp("apply/attack", 0);
	me->add_temp("apply/speed", -level*5);

	me->add("neili", -level*70);
	me->add("jingli", -level*50);

	me->delete_temp("perform/juejian");
	me->start_busy(2+random(2));
	return 1;
}
