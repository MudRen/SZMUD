// Code of ShenZhou
//feilong.c �������

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	mapping prepare_status;
	string weapon, op_weapon, op_skill, *pname;
	int my_power, op_power, my_li, op_li, my_jing, my_nei, op_jing, op_nei;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( !me->query("huashan/feilong") )
		return notify_fail("����������ǻ�ɽ���ڲ���֮�ܣ��㲢δ��ô��ڣ�\n");

	if( me->query_skill_mapped("force") != "zixia-gong" )
		return notify_fail("�����õĲ�����ϼ�����޷��˾�ʩչ���������\n");

	if( (int)me->query("eff_qi") * 100 / (int)me->query("max_qi") > 16)
		return notify_fail("��������������Ǳ����ľ��У�������������õģ�\n");
		
	if( me->query_skill("force") < 100 )
		return notify_fail("�����ϼ�����δ�����޷��˾�ʩչ���������\n");

	if( me->query_skill("sword") < 150 )
		return notify_fail("�㻪ɽ������Ϊ���㣬������ʹ�����������\n");

	if( me->query("neili") <= 400 )
		return notify_fail("�����������ʹ�����������\n");
	if( me->query("jingli") <= 200 )
		return notify_fail("��ľ�������ʹ�����������\n");

	weapon = me->query_temp("weapon");

	if ( !objectp(op_weapon = target->query_temp("weapon")) ) {
		if ( mapp(prepare_status = target->query_skill_prepare()) ) {
                	pname  = keys(prepare_status);
			op_skill = pname[0];
		}
		else op_skill = "unarmed";
	}
	else {
		op_skill = op_weapon->query("skill_type");
	}

	my_jing = me->query("jingli") * 8 / 10;
	my_nei = me->query("neili") * 8 / 10;

	if ( target->query("neili") < me->query("neili") ) {
		op_nei = target->query("neili")*9/10;
	}
	else op_nei = my_nei;

	if ( target->query("jingli") < me->query("jingli") ) {
		op_jing = target->query("jingli")*9/10;
	}
	else op_jing = my_jing;

	message_vision(HIG "\n$N�������ߣ��׹���磬���ش���ɽ��Ρ�ţ����鴦������޼������Ī�⡣\n"
			   "�赽������$Nһ����ȣ�"+weapon->name()+"���ַɳ�������һ����������$n��\n\n" NOR, me, target);
	tell_object(target, HIR "��ֻ���õ��������Ͷ����ף�ѹ����͸����������\n" NOR);

	my_power = me->query_skill("sword") + me->query_skill("dodge") + me->query_skill("force")
		   + me->query_skill("parry") + me->query("combat_exp") / 1000;

	op_power = target->query_skill(op_skill) + target->query_skill("dodge") + target->query_skill("force")
		   + target->query_skill("parry") + target->query("combat_exp") / 1000;
		
	my_li = me->query("jingli") + me->query("neili");

	op_li = target->query("jingli") + target->query("neili");

	if ( random(my_power) > op_power/2 ) {

	   if ( random(my_li) > random(op_li) ) {
		if ( objectp(op_weapon) ) {
	   		message_vision(HIR "$N���ܲ�����ֻ��ҧ������"+op_weapon->name()+"����ȫ��ǿ�ӹ��ơ�\n" NOR, target);
			message_vision(HIR "Ӳ��֮�£�"+op_weapon->name()+"����Ϊ���أ������費�˷ɽ����ƣ�\n" NOR, target);
			op_weapon->unequip();
			op_weapon->move(environment(me));
			op_weapon->set("name", "�ϵ���" + op_weapon->name());
	  		op_weapon->set("value", 0);
	  		op_weapon->set("weapon_prop", 0);
		}
	   	
		message_vision(HIR "$N���޿ɱܣ�����һ�������ĲҺ���"+weapon->name()+"���������\n" NOR, target);
		weapon->move(target);
		target->receive_wound("qi", target->query("max_qi")*9/10, me);
//		target->die();
	   }
	   else if ( me->query_str() > target->query_str() ) {
		if ( objectp(op_weapon) ) {
			message_vision(HIR "Ӳ��֮�£�"+op_weapon->name()+"����Ϊ���أ���춵����˷ɽ����ƣ�\n" NOR, target);
			message_vision("�ɽ��������裬�������䡣$N�䵲��һ����ȴҲ���������Һģ�ҡҡ��׹��\n", target);
			weapon->move(environment(me));
			op_weapon->unequip();
			op_weapon->move(environment(me));
			op_weapon->set("name", "�ϵ���" + op_weapon->name());
	  		op_weapon->set("value", 0);
	  		op_weapon->set("weapon_prop", 0);
	   	}
		else {
			message_vision(HIR "$N�������㣬��ȴ���в���������һ�������ĲҺ����н����ˣ�\n" NOR, target);
			target->receive_wound("qi", target->query("max_qi")*2/3, me);
		}
	   }
	   else if ( random(2) == 1 && objectp(op_weapon) ) {
		message_vision(HIR "Ӳ��֮�£�$N��"+weapon->name()+"��$n��"+op_weapon->name()+"˫˫���£�\n" NOR, me, target);
		weapon->move(environment(me));
		op_weapon->move(environment(me));
	   }
	   else if ( objectp(op_weapon) ) {
		message_vision(HIR "Ӳ��֮�£�$N��"+weapon->name()+"��$n��"+op_weapon->name()+"˫˫��٣�\n" NOR, me, target);
		op_weapon->unequip();
		op_weapon->move(environment(me));
		op_weapon->set("name", "�ϵ���" + op_weapon->name());
	  	op_weapon->set("value", 0);
	  	op_weapon->set("weapon_prop", 0);
		weapon->unequip();
		weapon->move(environment(me));
		weapon->set("name", "�ϵ���" + weapon->name());
	  	weapon->set("value", 0);
	  	weapon->set("weapon_prop", 0);
	   }
	   else {
		message_vision(HIR "$N�������㣬��ȴ���в���������һ�������ĲҺ����н����ˣ�\n" NOR, target);
		target->receive_wound("qi", target->query("max_qi")/3, me);
	   }

	   target->add("jingli", -op_jing);
	   target->add("neili", -op_nei);
	}
	else {
//		weapon->move(environment(me));	
		message_vision(HIY "$N����������ֻ�ز������ò����׽����бܹ������ŵ�����ֱð��\n" NOR, target);
		message_vision(HIY "һ��δ�У�"+weapon->name()+"ವ�һ���ַɻ�$N���С�\n" NOR, me);
	}

	me->add("neili", -my_nei);
	me->add("jingli", -my_jing);
	target->start_busy(2);
	target->kill_ob(me);
	
	return 1;
}
