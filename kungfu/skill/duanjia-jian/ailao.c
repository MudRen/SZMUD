/*
ailao.c ����ɽ����
[1] dali fix report                          ���(lnere)(Mon May 20)
----------------------------------------------------------------------
�޸Ĺ��ܣ�perform ailao������jifa dodge��jifa parry��10%��
                  ������ͬԭ�й��ܡ�
                  ���ƣ�ʹ�ù���busy 3-4 tick��
***********************************************************************
snowyu ע:
pfm ailao �����combo ˲�����apply parry ��dodge �ǲ�����ʲôЧ����
˲��combo ����attack damage speed ��Ȼailao �Ѿ��̶���������ģʽ
�ҽ�lnere ��ע���� dodge parry ��Ϊ damage ��attack  ����߹�����
���������ͽ�����������һ����������
dodge ��parry ���벻��û��̫�������
***********************************************************************
snowyu update 2002/5
*/
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int i, lvl, lvl1 ,lvl2, a, ap, dp, power;

	if (!target) target=offensive_target(me);

	if (!target || !target->is_character() || !me->is_fighting(target))
		return notify_fail("�㲻��ս���У�\n");

	weapon=me->query_temp("weapon");

	if (!objectp(weapon) || weapon->query("skill_type") != "sword")
		return notify_fail("�������޽������ʹ�ó�����ɽ���⣿\n");

	if ( me->query_skill("kurong-changong", 1)<70)
		return notify_fail("����ڹ����δ�����޷���������ɽ���⣡\n");
	
	if ( me->query_skill("sword", 1) < 100)
		return notify_fail("�㽣����Ϊ�������޷�ʩչ����ɽ���⣡\n");
	
	if ( me->query_skill("duanjia-jian", 1)<60)
		return notify_fail("��μҽ���Ϊ�������޷�ʩչ����ɽ���⣡\n");
	
	if( me->query_skill_mapped("force") != "kurong-changong")
		return notify_fail("�����õ��ڹ��밧��ɽ������·��㣣�\n");

	if ( me->query("neili") <= 500)
		return notify_fail("�����������ʹ�ð���ɽ���⣡\n");
	
	
	message_vision(HIR "\nͻȻ��$N����ͻ�䣬�����ݺᣬ����������������ǰ��������������\n\n"NOR, me, target);
	message_vision(HIR "\n����������������ʩչ����ɽ�����$n����ʵʵ��������ʮ������\n\n" NOR, me, target);
	
	lvl1 = (int)me->query_skill("duanjia-jian", 1);
	lvl2 = (int)me->query_skill("kurong-changong", 1); 
	lvl  = (lvl1+lvl2)/4;
	if ( lvl < 50 ) lvl = 50;
    if ( lvl > 200 ) lvl = 200;

	if(wizardp(me))
                       
        printf("lvl=====%d", lvl);
	me->add_temp("apply/attack", lvl);
    me->add_temp("apply/damage", lvl);
//  me->add_temp("apply/dodge",  lvl);
//	me->add_temp("apply/parry",  lvl);
        
	
	if (me->query("combat_exp")*100/target->query("combat_exp")<120)
		a=3;
	else
	{
		if (me->query("combat_exp")*100/target->query("combat_exp")<150)
			a=4;
		else
		{
			if (me->query("combat_exp")*100/target->query("combat_exp")<180)
				a=5;
			else a=6;
		}
	}

	for (i=1; i<=a; i++)
		COMBAT_D->do_attack(me, target, weapon);
	me->add_temp("apply/attack", - lvl);
    me->add_temp("apply/damage", - lvl);
//  me->add_temp("apply/dodge",  - lvl);
//	me->add_temp("apply/parry",  - lvl);
    me->add("neili", -150);
	me->start_busy(random(4));
     


	ap = me->query_skill("force")+me->query_skill("sword")/3;
	dp = target->query_skill("force")+target->query_skill("dodge")/3;
	power =  me->query_skill("yiyang-zhi",1) + me->query_skill("duanjia-jian",1);

// ���ӹ����� ���ļ���֮����
	if(random(2) == 1
		&& random(ap+dp)*100 > dp*50
		&& (int)me->query_skill("yiyang-zhi", 1) > 200 
		&& me->query("neili") >= 2000 
		&& me->query("family/family_name")=="����μ�")
	{
		message_vision(HIY "\nֻ��$N�������֣����ּ����ڹ���һ��ָ����ע��"NOR+weapon->query("name")+NOR HIY"������$n����һ����\n" NOR, me, target);
		me->add_temp("apply/speed", power/3);
		me->add_temp("apply/damage", power/2);
		me->add_temp("apply/attack", power/2);
		target->add_temp("apply/defense", -power/5);
		target->add_temp("apply/dodge", -power/5);
		target->add_temp("apply/parry", -power/5);
		COMBAT_D->do_attack(me, target, weapon);
		target->add_temp("apply/defense", power/5);
		target->add_temp("apply/dodge", power/5);
		target->add_temp("apply/parry", power/5);
		me->add_temp("apply/speed", -power/3);
		me->add_temp("apply/damage", -power/2);
		me->add_temp("apply/attack", -power/2);
		me->add("neili", -500);
	}
	me->start_busy(a-random(4));
	me->add("neili", -200);
	me->add("jingli", -50);
	return 1;
}