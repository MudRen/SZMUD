/* 
[396] re snowyu                                ���(lnere)(Fri Jan 25)
----------------------------------------------------------------------
�����Ƶ�pfm.��Ҳ����һЩ����,����û���ҵ��ܺõ�����.������˵һ���ҵ��뷨��
��ҹ�ͬ���޸����ɡ�
���⹥�������ύ��(jiaoji)
������$N���Ե�������,�������ơ�(���Լ��ɼ�)
ֻ��$Nһ����Х��˫�Ʒ��裬����������Ȼ�ǲ�Ҫ���Ĵ򷨡�$N��ʱ���Ʒ�ʱ������΢�����Ʈ������,ʱ���ش�������͸ǧ����$n���һ����
��������������ֻ������ת�أ���ͼ�Ա���
$N��$n��æ����֮�ʣ�����Ծ��$n��ǰ�����������,����ͬʱ����$n��С����
$n�Ѿ����޿��ˣ�ֻ��˫�����𽻴���ʹ��ȫ������$N��˫��,��ͼ�����������Լ����վ��а��ѳ������ⲻ֪$N������֮��ȴ�ֳ���һ��һ�ᡣ$nֻ�����Լ������Լ�С����һ����ƮƮ����������
$n���롰��⡱��
$n��������볷�����ƣ���Ϊʱ�����͵���һ�ɾ���ײ���ѱ�$N���������صĻ�������,$n������������ߵķ�����ˤ�˳�ȥ��
���⹥����ʴѩ�ڱ�(qinxue)
������$N��$n΢΢һЦ,˵������$nС���ˡ�����$nһ㶡�ֻ��$N˫����ɫ�����ɺ�ת�࣬����ת��,ɷ��Ѫɫ���������Ʒ�Ҳ���ڳ����˸е�Խ��Խ���䡣
$N˫��Խ��Խ�죬�������Ʒ������ؼ�����ѩ�籩�������������絶�����ʹ��$n�ѱ����ε��Ʒ綳�û�����������ֻ���˹�������,�ֿ����Ѿ�����֮�����Ʒ硣
$n������΢΢�������˹������ֿ����䡣(pfm����ʱ���ڶԷ��ķ�Ӧ)
$n�����彥��ů������������Ҳ���Ƹղ��ǰ㽩Ӳ��(pfm����ʱ�ĶԷ�������,��ʾ�Է�pfm������)
*/
// ���ύ�� By snowyu 2002/2 thank lnere 

#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
     string msg;
	int damage;
	object weapon,ob;
	int skill, jiali, my_rate, your_rate;

	skill = me->query_skill("kunlun-zhang",1);
	jiali=(int)me->query("jiali");
	weapon = me->query_temp("weapon");

	if(me->is_busy())
		return notify_fail("����æ���أ�\n");

        if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("�����ύ�á�ֻ����ս����ʹ�á�\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����ύ�á�ֻ�ܿ���ʹ�á�\n");

	if( (int)me->query_skill("xuantian-wuji", 1) < 120 )
		return notify_fail("��������޼���Ϊ����������ʹ�á����ύ�á���\n");

	if( me->query_skill_mapped("force") != "xuantian-wuji" )
		return notify_fail("�����õĲ��������޼���ʹ���������ύ�á���\n");

	if( (int)me->query("neili") < 1000 )
                return notify_fail("�������������\n");

    if( (int)me->query_skill("kunlun-zhang",1) < 120 )
                return notify_fail("��������ƻ�򲻹����޷�ʹ�á����ύ�á���\n");

    msg = WHT "\n$N���Ե���������������,ֻ��$Nһ����Х��˫�Ʒ��裬����������Ȼ�ǲ�Ҫ���Ĵ򷨡�\n" NOR;
    msg += HIY "\n$N��ʱ���Ʒ�ʱ������΢�����Ʈ������,ʱ���ش�������͸ǧ����$n���һ����\n"NOR;

    if( random( me->query("combat_exp") ) > random( target->query("combat_exp")*2 ) || !living(target) )
  {
			damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
			if(damage > 4000) damage = 4000;
			if(damage < 1000) damage = 1000;
			if(wizardp(me))
            printf("damage=====%d", damage);
			me->add("neili", -damage/2 );
			me->add("jingli", -me->query("jiajin")/2);

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage), me);
			target->start_busy(1+random(3));

		msg += HIC"\n$N��$n��æ����֮�ʣ�����Ծ��$n��ǰ�����������,����ͬʱ����$n��С����\n"NOR;

		msg += NOR;
		me->start_busy(2+random(2));
  }
  else if( random( me->query("combat_exp")*2 ) > random( target->query("combat_exp") )
				&&  random(target->query_skill("dodge")) < random( me->query_skill("strike") )  )
  {
			damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
			damage = damage / 2;
			if(damage > 2000) damage = 2000;
			if(damage < 500) damage = 500;
			if(wizardp(me))
            printf("damage=====%d", damage);

			me->add("neili", -damage/2 );
			me->add("jingli", -me->query("jiajin")/2);

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage), me);
			target->start_busy(1+random(3));

		msg += HIC"\n$n��������볷�����ƣ���Ϊʱ�����͵���һ�ɾ���ײ���ѱ�$N���������صĻ������š�\n"NOR;
        msg += RED"\n$n������������ߵķ������ˤ�˳�ȥ��\n"NOR;
		msg += NOR;
		target->add( "neili", -damage/4 );
		me->start_busy(2+random(2));
  }
  else if( random( me->query("combat_exp")*2 ) > random( target->query("combat_exp") ) &&
	  random( target->query_skill("dodge")*2 ) > random( me->query_skill("strike") ) )
  {
			damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")/5) ) ;
			damage = damage / 3;
			if(damage > 1000) damage = 1000;
			if(damage < 250) damage = 250;
			if(wizardp(me))
            printf("damage=====%d", damage);

			me->add("neili", -damage/2 );
			me->add("jingli", -me->query("jiajin")/2);

			target->receive_damage("qi", damage,  me);
			target->receive_wound("qi", random(damage), me);
			target->start_busy(1+random(3));

			msg += HIR"\n$n�Ѿ����޿��ˣ�ֻ��˫�����𽻴���ʹ��ȫ������$N��˫��,��ͼ�����������Լ����վ��а��ѳ�����\n"NOR;
            msg += RED"\n�ⲻ֪$N������֮��ȴ�ֳ���һ��һ�ᡣ$nֻ�����Լ�С�������صĴ���һ�ƣ�\n"NOR;
		msg += NOR;
		target->add( "neili", -damage/4 );
		me->start_busy(2+random(2));
  }
  else {
	 msg += HIC"\n$n֪�����Ʋ����мܣ�����һת���ӳ���$N�Ĺ�����Χ��\n\n"NOR;
	 me->add("neili", -jiali*2 );
	 me->add("jingli", -me->query("jiajin") );
	 me->start_busy(2 + random(2));
	 message_vision(msg+"\n", me, target);
	 return 1;
  }

  message_vision(msg+"\n", me, target);
  COMBAT_D->report_status(target);
  return 1;
}

