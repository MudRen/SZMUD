// Code of ShenZhou
//lianhuan.c  ��ħ�ȷ�֮��ħ����

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void check_fight(object me, object target, object weapon);
private int remove_attack(object me, object weapon);

int perform(object me, object target)
{
	object weapon;
	int skill;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��ħ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( me->query_temp("fengmo") )
                return notify_fail("������ʹ�÷�ħ�����ˣ�\n");

	weapon = me->query_temp("weapon");
        if( !objectp(weapon) || weapon->query("skill_type") != "staff" )
                return notify_fail("���������ȣ�����ܹ�ʩչ��ħ���ȣ�\n");

	if( me->query_skill_mapped("force") != "huntian-qigong" )
                return notify_fail("�����õĲ��ǻ����������޷�����ȷ�ʩչ��ħ���ȣ�\n");

        if( me->query_skill("force") < 100 )
                return notify_fail("��Ļ����������δ�����޷�����ȷ�ʩչ��ħ���ȣ�\n");

	if( me->query_skill("staff") < 100 )
		return notify_fail("���ħ�ȷ���Ϊ���㣬������ʹ�÷�ħ���ȣ�\n");

	if( me->query("neili") <= 300 )
		return notify_fail("�����������ʩչ��ħ���ȣ�\n");
	if( me->query("jingli") <= 200 )
		return notify_fail("��ľ�������ʩչ��ħ���ȣ�\n");

 	skill = me->query_skill("staff");
	
	message_vision(HIR "\n$N���һ�������м�ת�ŵ�"+weapon->name()+"�����������ڿ��иߵ����һ�����\n\n" NOR, me, target);

	me->set_temp("fengmo", 1);
	me->set_temp("location", file_name(environment(me)));
//	me->set_temp("my_weapon", base_name(weapon));
//	me->set_temp("weapon_name", weapon->name());
	me->add("neili", -200);
	me->add("jingli", -100);
	weapon->unequip();
//	destruct(weapon);
//        weapon->move("/u/ryu/workroom")
	weapon->set("no_clean_up", 1);
	me->reset_action();
//	me->start_call_out( (: call_other, __FILE__, "check_fight", me, target, weapon :), 1);
	call_out("check_fight", 1, me, target, weapon);

	return 1;
}

void check_fight(object me, object target, object weapon)
{
	string *limbs, limb, result, str, type;
	int damage;

	me->reset_action();

	if ( me->query_temp("fengmo") >= (int)me->query_skill("fengmo-zhang", 1)/5 ) {
	   call_out("remove_attack", 1, me, weapon);
	}
	else if ( me->is_fighting() && me->query_temp("fengmo") ) {
	limbs = target->query("limbs");
	limb = limbs[random(sizeof(limbs))];
	type = "����";

	   message_vision(HIR "\nͻȻ��$n������$N��"+limb+"��Ȼ��ײ��ȥ��\n" NOR, target, weapon);

	   if ( random(me->query("combat_exp")) > target->query("combat_exp") ) {

//RYU: the following code is to make it look nice.
	   damage = 5+random(me->query_skill("fengmo-zhang", 1));
	   target->receive_damage("qi", damage, me);

           result = COMBAT_D->damage_msg(damage, type);
	   result = replace_string( result, "$l", limb);
	   str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));

	   message_vision(result, me, target);
	   message_vision("($N"+str+")\n", target);

	   }
	   else {
		message_vision(YEL "$N���÷���������һ�ã��ܹ���$n��\n" NOR, target, weapon);
	   }
	
	   message_vision(HIR "\n$N����һ������Ʈ�����$n��������βһ�ƣ����������ڰ�շ�����\n\n" NOR, me, weapon);

	   me->add_temp("fengmo", 1);
	   call_out("check_fight", 1, me, target, weapon);
	}
	else {
	   call_out("remove_attack", 1, me, weapon);
	  
	}
}		

int remove_attack(object me, object weapon)
{
	remove_call_out("check_fight");
	me->delete_temp("fengmo");
	
	if ( file_name(environment(me)) == me->query_temp("location") && living(me) ) {
		weapon->move(me);
		weapon->set("no_clean_up", 0);
		weapon->wield();
		message_vision(YEL "\n$N������ǰ����������$n�ջء�\n\n" NOR, me, weapon);
	}
	else {
		weapon->move(me->query_temp("location"));
		message("vision", "ֻ�����ϵ�һ����"+weapon->name()+"�����ɰ�յ��䡣\n", environment(weapon), ({weapon}) );
	}

//	me->delete_temp("my_weapon");
//	me->delete_temp("weapon_name");
	me->delete_temp("location");

	return 1;
}
