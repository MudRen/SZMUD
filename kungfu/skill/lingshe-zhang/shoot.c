// Code of ShenZhou
// shoot ���䰵��
// maco

#include <ansi.h>

inherit F_SSERVER;
inherit F_DBASE;

void remove_shoot(object);

int perform(object me, object target)
{
	int t = (int)me->query_temp("baituo/shoot");
	string type, limbs, str, dodge_skill, limb, result;
	object weapon;
	int poi_amount, level, exp1, exp2;

	if( environment(me)->query("no_fight"))
		return notify_fail("���ﲻ�ܷ��䰵����\n");

	if( !target && me->is_fighting()) target = offensive_target(me);

	if( !target )
		return notify_fail("��Ҫ��˭���䰵����\n");
		
	if( target == me )
		return notify_fail("���Լ����䰵����\n");

	if( t && (time()-t) < 10 )
                return notify_fail("��ողŷ����˰�������ʱ���ڲ��˹ʼ���ʩ��\n");

	if (!objectp(weapon = me->query_temp("weapon")))
		 return notify_fail("������ֳ��ܷ��䰵�������ȡ�\n");

	type = weapon->query("snake_type");

	if ( !type && weapon->query("id") != "shezhang")
		return notify_fail("���"+weapon->name()+"�ϲ�û�а������ء�\n");

	level = (int)me->query_skill("lingshe-zhang", 1);
	if (level < 40 )
		return notify_fail("��������ȷ�������죬�޷����ݷ��䰵���Ļ��ء�\n");

	if ((int)me->query_skill("poison", 1) < 40 )
		return notify_fail("��Ļ�����������̫ǳ���޷����ݷ��䰵���Ļ��ء�\n");

	if( me->query_skill_mapped("force") != "hamagong")
		return notify_fail("�����õ��ڹ��롸�����ȷ�����·��㣣�\n");

	limbs = target->query("limbs");
	//level = level/2;
	poi_amount = level + me->query_skill("poison", 1);

	if( me->query("neili") < poi_amount )
		return notify_fail("�������������\n");
        if( me->query("jingli") < 50 )
                return notify_fail("��ľ���������\n");

	exp1 = me->query("combat_exp");
	exp2 = target->query("combat_exp");

	if(exp1*3 < exp2 && exp2 > 1000000)
		return notify_fail("����֪"+target->name()+"������֣���ͷ����Ҳ�κ������ã����粻�������ǳ�Ц��\n");

	message_vision(HIB"$N��"+weapon->name()+HIB"�ڵ���һ�٣��ص�һ�����죬��ͷ�зɳ�һ�����ΰ�������ֱ��$n��ȥ��\n"NOR, me, target);

	me->add("neili", -poi_amount/2);
	me->add("jingli", -50);

	if( me->query("neili") > random(target->query("neili")) && exp1 > random(exp2) ) {

		message_vision(HIR"�ǰ���ȥ�úÿ죬����$nһ���Һ�����δ���尵����·���ѱ�����"+limbs[random(sizeof(limbs))]  +"��\n"NOR, me, target);

		if( type == "����" || type == "����" )
			target->apply_condition("bt_poison",
			poi_amount*3 + target->query_condition("bt_poison"));
		else
			target->apply_condition("snake_poison",
			poi_amount*3 + target->query_condition("snake_poison"));
			target->set("poisoner", me);
		
		target->receive_wound("qi", random(level) + level/2 , me);
		target->start_busy(random(2));
		result = COMBAT_D->eff_status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
	        message_vision("( $N"+result+" )\n", target);
	        
	}
	else {
		dodge_skill = target->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		str = SKILL_D(dodge_skill)->query_dodge_msg(limb);
		message_vision(str, me, target);
	}

	target->kill_ob(me);
	me->set_temp("baituo/shoot",time());
	remove_call_out("remove_shoot");
	call_out("remove_shoot", 10,me);
	me->start_busy(random(2));

	return 1;
}

void remove_shoot(object me)
{
	me->delete_temp("baituo/shoot");

        tell_object(me, "���������İ���׼�����ˡ�\n");
}
