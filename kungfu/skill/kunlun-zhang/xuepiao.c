// kunlun ��ɽѩƮ

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        int lvl,damage;
        string msg;
            lvl=(int)me->query_skill("kunlun-zhang", 1)+(int)me->query_skill("mantian-huayu", 1)+ (int)me->query_skill("taxue-wuhen", 1);
       damage = (int)me->query_skill("kunlun-zhang", 1)+(int)me->query_skill("mantian-huayu", 1);
           damage = damage*5;
           damage = 1000 + damage/2+random(damage/2);
        if( !target ) target = offensive_target(me);
        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("����ɽѩƮ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�á���ɽѩƮ����\n");               
        if( (int)me->query_skill("kunlun-zhang", 1) < 200 )
                return notify_fail("��ġ������ơ�����!\n");
//                 if( (int)me->query_skill("mantian-huayu", 1) < 200 )
//                 return notify_fail("��ġ����컨�꡹����!\n");
                  if( (int)me->query_skill("xuantian-wuji", 1) < 200 )
                  return notify_fail("��ġ������޼�������!\n");
              if( (int)me->query_skill("taxue-wuhen", 1) < 200 )
                return notify_fail("���̤ѩ�޺ۻ���!\n");
        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("����������̫��������ʹ�á���ɽѩƮ��!\n");
  message_vision(
  WHT "\n$N���һ��[��ɽѩƮ]��ͻȻ�������ת��һ�С���ɽѩƮ������Ӱ���裬��ʱ֮������˷�����$N����Ӱ,���ű�һ�п��һ��.\n" NOR, me);
           if (random(me->query_skill("kunlun-zhang"))+lvl*7/10 > target->query_skill("force")/2 +target->query_skill("dodge")/2 )
        {
me->add_temp("apply/attack", lvl/10);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
me->add_temp("apply/attack", -lvl/10);
                me->start_busy(random(2)+2);
                target->start_busy(random(3));
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                 me->add("neili", -damage/8);

                if( damage < 40 )
         msg = MAG  "\n���$n��$N���˸����ֲ������ؿ�����һ��,�ƺ�һ��.\n"NOR;
          else if( damage < 80 )

     msg = HIR "$n��$N���мӿ�һ����ң���$N��˫�ƴ����ؿ�,�����ܵ�һ���ش�����������������\n"NOR;

        else if( damage < 160 )

        msg = RED "\n$nֻ�������ܶ���$N����Ӱ�۾�һ��,�����$N��˫�ƻ����ؿڣ���ǰһ�ڣ���һ������һ�����˳�ȥ��\n"NOR;
                else
        msg = RED "\n$nֻ�������ܶ���$N����Ӱ�۾�һ��,�����$N��˫�ƻ����ؿڣ���ǰһ�ڣ���һ������һ�����˳�ȥ��\n"NOR;
}
        else 
        {
                   me->start_busy(random(3));
                me->add("qi", -(damage/2));
                me->add("eff_qi", -(damage/5));
    msg = HIY"\n$n������$N����ͼ������һת����æ���⴮������,����һ��������\n"NOR;
        }
       message_vision(msg, me, target);
        return 1;
}

