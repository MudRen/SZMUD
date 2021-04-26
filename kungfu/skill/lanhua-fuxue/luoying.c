// Code of ShenZhou
// ��Ӣ���ơ�������Ѩ�ֹ���
// maco 8/25/1999���棬11/13/2000����
// ��Ī�����ָ��Ϊ�ƣ��ƻ�Ϊָ������Ӣ���ơ��롸������Ѩ�֡�����Ϊ�ã�����������ʱ����Ӣ�ͷף�ָ������������ި�������������������ҷ��˶�����

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void remove_effect(object me, object weapon, int speed, int damage);

int perform(object me, object target)
{
	object weapon;
	int speed, damage, hand;

	weapon = me->query_temp("weapon");

	if( !target && me->is_fighting() ) target = offensive_target(me);

	if( !target
	||  !target->is_character()
	||  !me->is_fighting(target) )
		return notify_fail("��Ӣ���ƺ�������Ѩ�ֵĴ��乥��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if( me->query("gender") != "Ů��")
		return notify_fail("�㲻��Ů��������һ�е�������̬�е����롣\n");

	if( objectp(weapon))
		return notify_fail("������ȷ���������\n");

	if( me->query_temp("luoying_lanhua") )
		return notify_fail("���Ѿ�ʹ������Ӣ���ƺ�������Ѩ�ֵĴ��乥����\n");
	
	if( me->query_skill("lanhua-fuxue",1) < 90 )
		return notify_fail("���������Ѩ����Ϊ���㡣\n");

	if( me->query_skill("luoying-shenjian",1) < 90 )
		return notify_fail("�����Ӣ������Ϊ���㡣\n");

	if( me->query_skill("bitao-xuangong", 1) < 100 )
		return notify_fail("��ı���������Ϊ���㣬�޷�ͬʱʩչ��Ӣ���ƺ�������Ѩ�֣�\n");

	if( me->query_skill_mapped("force") != "bitao-xuangong")
		return notify_fail("���������ʹ����������\n");
	if( me->query_skill_mapped("strike") != "luoying-shenjian")
		return notify_fail("����ʩչ���Ʒ�������Ӣ���ƣ��������������Ѩ�ִ��䣿\n");

	if( me->query("max_neili") <= 1000 )
		return notify_fail("���������Ϊ���㣡\n");

	if( me->query("neili") <= 400 )
		return notify_fail("�������������\n");

	if( me->query("jingli") <= 400 )
		return notify_fail("��ľ���������\n");

	damage = (me->query_skill("lanhua-fuxue",1) + me->query_skill("luoying-shenjian",1))/6;
	hand = (me->query_skill("hand",1)+me->query_skill("strike",1) )/6;
	speed = (me->query_skill("hand",1)+me->query_skill("strike",1) )/200;
	me->add("neili", -80);
	me->add("jingli", -80);

	
	//����������
	me->add_temp("apply/speed", speed);
	me->add_temp("apply/attack", damage);
	me->add_temp("apply/damage", damage/2);

	me->set_temp("luoying_lanhua", 1); 	

	message_vision(HIY"\n$NͻȻ���У�ʹ������Ӣ���ơ�������ӰƮ����ķ����棬������һʵ�������һʵ�����������п�����������һ�㣬������̬Ʈ�ݣ������������衣\n"NOR, me,target);

	if(me->is_fighting(target) ){
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	}

	message_vision(HIC"\n����$Nָ��Ϊ�ƣ��ƻ�Ϊָ������Ӣ���ơ��롸������Ѩ�֡�����Ϊ�ã�����������ʱ����Ӣ�ͷף�ָ������������ި�������������������ҷ��˶�����\n"NOR, me,target);

	if(me->is_fighting(target) ){
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	}

	me->set_temp("fuxue", 1); 
	me->start_busy(1);

	call_out("checking", 1, me, weapon,speed,damage);

	return 1;
}

void checking(object me, object weapon,int speed, int damage)
{
	if( !living(me) || me->is_ghost() ){
		remove_effect(me, weapon, speed, damage);
		return ;
	}
	if( !me->is_fighting() ){
		remove_effect(me, weapon, speed, damage);
		message_vision("\n����˫�������ѱϣ�$N����΢�ˣ�ƮȻ���ơ�\n"NOR, me);

		return ;
	}

	else if(me->query_temp("weapon")){
		remove_effect(me, weapon, speed, damage);
		return ;
	}
	else if( me->query_skill_mapped("strike") != "luoying-shenjian"
	 || me->query_skill_mapped("hand") != "lanhua-fuxue"
	 || (me->query_skill_prepared("hand") != "lanhua-fuxue" && me->query_skill_prepared("strike") != "luoying-shenjian") ){
		remove_effect(me, weapon, speed, damage);
		return ;
	}
	else if(  (int)me->query("neili") < 500 ||(int)me->query("jingli") < 500 )
	{
		tell_object(me, "\n�㾪����Ϣ����������ά����˽��ܹ��ƣ����²�ʹ��Ӣ���Ʒ�������������Ѩ��Ӧ�С�\n" NOR);
		remove_effect(me, weapon, speed, damage);
		return ;
	}

		else call_out("checking", 1, me, weapon, speed, damage);
		return;
}

void remove_effect(object me, object weapon, int speed, int damage) 
{
	if (!me) return;
	me->add_temp("apply/speed", -speed);
	me->add_temp("apply/attack", -damage);  
	me->add_temp("apply/damage", -damage/2);
	me->delete_temp("luoying_lanhua");
	me->delete_temp("fuxue");
}
