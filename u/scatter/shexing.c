// shexing.c ����
// CODE BY SCATTER

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
      int lvl, player, opp, diff;
          string strMsg;

      lvl = ((int)me->query_skill("xiaoyaoyou", 1)+(int)me->query_skill("shexing-diaoshou", 1))/2;
          
          if( !target ) target = offensive_target(me);
          if( !target || !target->is_character() || !me->is_fighting(target) )
                  return notify_fail("����Ӱ���С�֮��ֻ����ս���жԵ���ʹ�á�\n");
          if( me->is_busy() )
                  return notify_fail("�㻹��æѽ��\n");
      if( (int)me->query_skill("xiaoyaoyou",1) < 150 )
                  return notify_fail("�����ң�β�����죬����ʹ����Ӱ���У�\n");
      if( (int)me->query_skill("shexing-diaoshou",1) < 150 )
                  return notify_fail("�����ң�β�����죬����ʹ����Ӱ���У�\n");
      if( (int)me->query_skill("huntian-qigong", 1) < 150 )
                  return notify_fail("��Ļ��������ȼ�����������ʹ����Ӱ���У�\n");
      if( (int)me->query("max_neili") < 1000 )
                  return notify_fail("�������̫��������ʹ����Ӱ���У�\n");
      if( (int)me->query("neili") < 200 )
                  return notify_fail("�������̫���ˣ�����ʹ����Ӱ���У�\n");   
          if( (int)me->query("neili") < 300 )
                  return notify_fail("��ľ���̫���ˣ�����ʹ����Ӱ���У�\n");   
          if(!me->query_temp("gb_huixuan"))
                  return notify_fail("��û��ʹ����ң���������޷�ʹ����Ӱ���У�\n");   

          strMsg = MAG+"$N˫�ֵĹ�������ͻȻ�ı䣬��ʱ������ʱ�죬��ʱƫ����ʱ׼��$n�е�����Ӧ����\n\n"+NOR;

          player = lvl * 4 / 3;
          opp = ((int)target->query_skill("force", 1)+(int)me->query_skill("dodge", 1))/2;
          diff = player - opp;

          if(diff < 1)
          {
                  strMsg = strMsg + HIR + "��ʱ$Nʹ��ȫ������ʱ�䷢������¶����ֻ��$n�����ɵ�����$N�Ĺ�����\n"+NOR;
                  me->start_busy(2 + random(2));
          }

          else if(diff < 50)
          {
                  strMsg = strMsg + HIC + "��ʱ$Nץ��$n�书��Ҫ����ʹ��ʮ�ɹ����ڶ�ʱ����ֻ�����ء�\n"+NOR;
                  me->add_temp("apply/damage", diff);
                  me->add_temp("apply/dodge", diff);
                  me->add_temp("apply/parry", diff);
                  me->add_temp("apply/speed", diff);
                  me->add_temp("apply/attack", diff);
                  me->add_temp("apply/armor", diff);

                  COMBAT_D->do_attack(me, target);
                  COMBAT_D->do_attack(me, target);
                  COMBAT_D->do_attack(me, target);

                  me->add_temp("apply/damage", -diff);
                  me->add_temp("apply/dodge", -diff);
                  me->add_temp("apply/parry", -diff);
                  me->add_temp("apply/speed", -diff);
                  me->add_temp("apply/attack", -diff);
                  me->add_temp("apply/armor", -diff);

                  strMsg = strMsg + HIR + "$nʹ�������Ṧ��������ӭ�н�$Nʹ��ʮ�ɹ���˲����Ϊ���ɡ�\n"+NOR;
                  me->start_busy(1 + random(3));
          }

          else if(diff < 100)
          {
                  strMsg = strMsg + HIW + "��ʱ$N�͹�$n�ϣ��У���������$n��ʱ�е��޷�����ֻ��ǿ���мܡ�\n"+NOR;

                  me->add_temp("apply/damage", diff);
                  me->add_temp("apply/dodge", diff);
                  me->add_temp("apply/parry", diff);
                  me->add_temp("apply/speed", diff);
                  me->add_temp("apply/attack", diff);
                  me->add_temp("apply/armor", diff);

                  COMBAT_D->do_attack(me, target);
                  COMBAT_D->do_attack(me, target);
                  COMBAT_D->do_attack(me, target);

                  me->add_temp("apply/damage", -diff);
                  me->add_temp("apply/dodge", -diff);
                  me->add_temp("apply/parry", -diff);
                  me->add_temp("apply/speed", -diff);
                  me->add_temp("apply/attack", -diff);
                  me->add_temp("apply/armor", -diff);

                  strMsg = strMsg + HIR + "$n�ڳ��мܵ����ƿ�׼��$N�Ĺ���Ŀ�꣬$nʹ��ȫ���м��˼��·����Լ��񵾲�һ���ķ��˳�ȥ��\n"+NOR;
                  me->start_busy(2 + random(3));
          }

          else
          {
                  strMsg = strMsg + HIW + "$N������˵��ʼ�ȷ����ˣ�$N˫�����Ϲ���ͻȻת��Ϊ���м乥����$N��˲��Ļ����Ϲ�����\n"+NOR;

                  me->add_temp("apply/damage", diff);
                  me->add_temp("apply/dodge", diff);
                  me->add_temp("apply/parry", diff);
                  me->add_temp("apply/speed", diff);
                  me->add_temp("apply/attack", diff);
                  me->add_temp("apply/armor", diff);

                  COMBAT_D->do_attack(me, target);
                  COMBAT_D->do_attack(me, target);
                  COMBAT_D->do_attack(me, target);
                  COMBAT_D->do_attack(me, target);

                  me->add_temp("apply/damage", -diff);
                  me->add_temp("apply/dodge", -diff);
                  me->add_temp("apply/parry", -diff);
                  me->add_temp("apply/speed", -diff);
                  me->add_temp("apply/attack", -diff);
                  me->add_temp("apply/armor", -diff);

                  strMsg = strMsg + HIR + "$n����$N����������ȫ�޷�Ԥ��Ŀ�꣬$n��$N����" + HIC + "��" + HIW + "��" + HIR + "��" + HIW + "��" + HIG + "��" + HIW + "�������Ĺ���˿��û�з���������\n"+NOR;
                  me->start_busy(1 + random(4));

          }
          
          COMBAT_D->report_status(target);

      return 1;
}

