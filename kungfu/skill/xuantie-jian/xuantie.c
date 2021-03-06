// Code By Scatter
// perform 玄铁
// xuantie.c
// V. 1.2
// update by april 2001.12.22

#include <ansi.h>

inherit F_SSERVER;
inherit F_CLEAN_UP;

void remove_effect(object me, object weapon, int skill);

int perform(object me, object target)
{
	object weapon;
	int skill, skill1;
	int myskill;
	int rigi;
	string msg;

	if( !target ) target = offensive_target(me);
//	if( !target || !target->is_character() || !me->is_fighting(target) )
//		return notify_fail("玄铁只能对战斗中的对手使用。\n");

	if( me->query_temp("gm_xuantie"))
		return notify_fail("你已在使用玄铁中了！\n");

	if( !objectp(weapon = me->query_temp("weapon") ) )
		return notify_fail("你未持武器，不能使用玄铁！\n");

	if( me->query_skill_mapped("force") != "yunu-xinjing" )
		return notify_fail("你所用的并非玉女心经，无法施展玄铁！\n");

	if( me->query_skill("force") < 90 )
		return notify_fail("你的玉女心经火候未到，无法施展玄铁！\n");

	if( me->query_skill("sword") < 135 )
		return notify_fail("你的玉女剑法修为不足，还不会使用玉女素心！\n");

	if( me->query("neili") < 500 )
		return notify_fail("你的内力不够施展玄铁！\n");
        
	if( me->query("jingli") < 300 )
		return notify_fail("你的精力不够施展玄铁！\n");

//	myskill = me->query_skill("xuantie-jian", 1);
//	skill = myskill;
	
//        write("Current Skill Level Is " + myskill+"\n");

	msg = HIW"$N清啸一声，手中的" + weapon->query("name")
		+ "立时感应！\n"
		+ "一阵龙吟过后，剑身越来越黑，也越来越重，宛若传说中的"
		+ " 玄铁重剑 ，破空之声叱叱传来，令人心惊胆颤！\n"NOR;
	message_vision(msg+"\n", me);

	skill = (me->query_skill("sword") + me->query_skill("force")) /3;
	if(skill>600) skill = 600;

	weapon->set_temp("no_get",weapon->query("no_get"));
	weapon->set_temp("no_drop",weapon->query("no_drop"));
	weapon->set_temp("material",weapon->query("material"));
	weapon->set_temp("weight",weapon->weight());

	weapon->set("no_get", "这样东西不能离开那儿。\n");
	weapon->set("no_drop","这样东西不能离开你。\n");

	weapon->set("material","steel");

	myskill = skill/2;
	if( myskill > weapon->query("weapon_prop/damage"))
		me->add_temp("apply/damage",myskill-weapon->query("weapon_prop/damage"));

	myskill = skill * 50;
	if(myskill>25000) myskill = 25000;
	if(myskill<10000) myskill = 10000;
	if(myskill > weapon->weight()) weapon->set_weight(myskill);
 
	me->set_temp("gm_xuantie", 1);
	me->add("neili", -skill);
	me->add("jingli", -skill/2);

//        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, rigi :), 5);
	call_out("remove_effect", skill/10, me, weapon, skill);
	return 1;
}

//*********************************
//Basic Perform Weapon Setting Complete

void remove_effect(object me, object weapon, int skill)
{
	string msga;
	int myskill;

	msga = weapon->query("name")+HIC"渐渐恢复了原样！\n"NOR;
	message_vision(msga+"\n", me);

	weapon->set("no_get",weapon->query_temp("no_get"));
	weapon->set("no_drop",weapon->query_temp("no_drop"));
	weapon->set("material",weapon->query_temp("material"));
	weapon->set_weight(weapon->query_temp("weight"));

	myskill = skill/2;
	if( myskill > weapon->query("weapon_prop/damage"))
		me->add_temp("apply/damage",weapon->query("weapon_prop/damage")-myskill);

	me->delete_temp("gm_xuantie");
}
