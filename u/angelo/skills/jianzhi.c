// Code of ShenZhou
// jianzhi.c ��ָ���乥��
// maco 8/25/1999
// �������(20)�����｣���뵯ָ������Թ���Ѩ��Ϊ������ָ���䣬��΢����

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

void remove_effect(object me, object weapon, int speed, int damage);

int perform(object me, object target)
{
	object weapon;
	int speed, damage, sword,jianyi;

	weapon = me->query_temp("weapon");
	jianyi = me->query("th_jianyi");

	if( !target && me->is_fighting() ) target = offensive_target(me);

	if( !target
	||  !target->is_character()
	||  !me->is_fighting(target) )
		return notify_fail("��ָ���乥��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

 //       if (!me->query("th_jianyi"))
 //	       return notify_fail("��û�������⣬�����｣���İ���������ޣ���Ҳ�޷�ʩչ��ָ����Ĺ��ơ�\n");

	if( !objectp(weapon) || weapon->query("skill_type") != "sword" )
		return notify_fail("�������޽������̸���ϡ���ָ���䡹��\n");

	if( me->query_temp("th_jianmang") )
		return notify_fail("��������ʹ������â���������ٷ����ˣ�\n");

	if( me->query_temp("th_jianzhi") )
		return notify_fail("���������ý�ָ����Ĺ��ƣ�\n");
	
	if( me->query_skill("yuxiao-jian",1) < 100 )
		return notify_fail("������｣����Ϊδ�������ܽ�ָ���乥�У�\n");

	if( me->query_skill("tanzhi-shentong",1) < 100 )
		return notify_fail("��ĵ�ָ��ͨ��Ϊδ�������ܽ�ָ���乥�У�\n");

	if( me->query_skill("bitao-xuangong", 1) < 100 )
		return notify_fail("��ı���������Ϊ���㣬ǿʹ��ָ���䣬ͽȻ��ɢ������\n");

	if( me->query_skill_mapped("force") != "bitao-xuangong")
		return notify_fail("������ʹ���ڹ��޷��뽣ָ����֮�ķ�Э����\n");
	if( me->query_skill_mapped("finger") != "tanzhi-shentong")
		return notify_fail("����ʩչ��ָ�����ǵ�ָ��ͨ��\n");

	if( me->query_skill_prepared("finger") != "tanzhi-shentong")
		return notify_fail("�㻹û��׼����ʩչ��ָ��ͨ��\n");

	if( me->query("max_neili") <= 1200 )
		return notify_fail("���������Ϊ���㣬����ʩչ��ָ���䣬���������������������գ�\n");

	if( me->query("neili") <= 400 )
		return notify_fail("����������㣬������ʩչ��ָ���䣡\n");

	if( me->query("jingli") <= 400 )
		return notify_fail("��ľ������㣬������ʩչ��ָ���䣡\n");

	damage = me->query_skill("yuxiao-jian") + me->query_skill("tanzhi-shentong",1);
	damage = damage/4;
	sword = (me->query_skill("sword")*jianyi + me->query_skill("finger") )/6;
	speed = (me->query_skill("sword")+me->query_skill("finger") )/200;
	me->add("neili", -250);
	me->add("jingli", -100);

	//����������
	me->add_temp("apply/speed", speed);
	me->add_temp("apply/attack", damage);
	me->add_temp("apply/damage", damage/2);

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	if(me->query_temp("apply/damage") <= 0) me->set_temp("apply/damage", 0);

	message_vision(HIG"$N����"+weapon->name()+HIG"һ�ڣ�������ȥ���������磬�������ǹ��ƣ�һ�в���$n���⿪ȥ���ڶ��е����������������\n"NOR, me,target);

	//�ڶ����Կ�
	me->add_temp("apply/attack", damage/3);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->add_temp("apply/attack", -damage/3);

	if(me->is_fighting(target) ){
	message_vision(HIG"$N����δֹ������ָ�����̾�����������$n��·Ѩ����"+HIW"�����｣����"NOR+HIG"��"+HIW"����ָ��ͨ��"NOR+HIG"����Ϊ�ã�Խ����΢����仯���\n"NOR, me,target);

	weapon->unequip();
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	weapon->wield();
	}
	me->set_temp("th_jianzhi", sword); 

	if(me->query_temp("th_jianzhi") > 70)
	me->set_temp("th_jianzhi", 70); 

	call_out("checking", 1, me, weapon,speed,damage);

	return 1;
}

void checking(object me, object weapon,int speed, int damage)
{
	if( !living(me) || me->is_ghost() )
	{
		remove_effect(me, weapon, speed, damage);
		return ;
	}
	if( !me->is_fighting() )
	{
		message_vision("\n$N��ս���ѱϣ��㼴�����˽�ָ����Ĺ�����\n", me);
		remove_effect(me, weapon, speed, damage);
		return ;
	}

	else if( environment(weapon) != me || weapon != me->query_temp("weapon") )
	{
		message_vision("\n$N���б�����ʧ�������ջ��˽�ָ����Ĺ��ơ�\n"NOR, me);
		remove_effect(me, weapon, speed, damage);
		return ;
	}
	else if( me->query_skill_mapped("sword") != "yuxiao-jian"
	 || me->query_skill_mapped("finger") != "tanzhi-shentong"
	 || me->query_skill_prepared("finger") != "tanzhi-shentong" )
	{
		remove_effect(me, weapon, speed, damage);
		message_vision(HIG"\n$Nһ��"+weapon->name()+HIG"����Ȼ�任���������������｣���뵯ָ��ͨ�Ĵ��������\n"NOR, me);
		return ;
	}
	else if(  (int)me->query("neili") < 500 ||(int)me->query("jingli") < 500 )
	{
		tell_object(me, HIR "\n�㾪����Ϣ����������˿칥������̷��������²�����ɫ�������������֡���ָ��ͨ�����ơ�\n" NOR);
		remove_effect(me, weapon, speed, damage);
		return ;
	}
	else if( me->query_temp("th_jianzhi") <= 20 )
	{
		remove_effect(me, weapon, speed, damage);
		message_vision(HIG"\n$Nһ��"+weapon->name()+HIG"������ʳ�ж�ָ���𽣾������������ʹ�������｣������\n"NOR, me);
		return; 
	}

		else call_out("checking", 1, me, weapon,speed,damage);
		return;
}

void remove_effect(object me, object weapon, int speed, int damage) 
{
	if (!me) return;
	me->add_temp("apply/speed", -speed);
	me->add_temp("apply/attack", -damage);  
	me->add_temp("apply/damage", -damage/2);

	if(me->query_temp("apply/damage") <= 0) me->set_temp("apply/damage", 0);

	me->delete_temp("th_jianzhi");
}
