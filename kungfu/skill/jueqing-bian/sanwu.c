//����������
//Code by Scatter
//V. 1.2
//+(me->query_temp("weapon"))->query("name")+HIY
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
int remove_effect(object me);

int perform(object me, object target)
{
        string msg;
        int tme;
        int ttarget;
        int rdma;
        int rdmb;
        int rdmc;
        int total;
        int hone;
        int htwo;
        int hthree;
        int ttar;
        int sdamage;
        int tdamage;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_temp("sanwu",1) )
                return notify_fail("������ʹ�����������֣�\n");

        if( me->query_skill_mapped("force") != "yunu-xinjing" )
                return notify_fail("�㲢��ʹ����Ů�ľ����޷�ʩչ���������֣�\n");

        if( me->query_skill("yunu-xinjing", 1) < 120 )
                return notify_fail("�����Ů�ľ����δ�����޷�ʩչ���������֣�\n");


         if( me->query_skill("whip",1) < 120 )
                return notify_fail("��ľ���޷���Ϊ���㣬������ʹ�����������֣�\n");

//        skill =  ( me->query_skill("jueqing-bian")
//                + me->query_skill("force") ) / 5;

        if( me->query("neili") <= 500 )
                return notify_fail("�����������ʹ�����������֣�\n");
        if( me->query("jingli") <= 500 )
                return notify_fail("��ľ�������ʹ�����������֣�\n");
        if( me->query("jing") <= 500 )
                return notify_fail("��ľ�����ʹ�����������֣�\n");


        tme = me->query_skill("jueqing-bian", 1) + me->query_skill("feiyan-gong", 1) + me->query_skill("yunu-xinjing", 1);
        ttar = target->query_skill("dodge") + target->query_skill("force");


        ttarget = random(ttar);
        rdma = random(tme);
        rdmb = random(tme);
        rdmc = random(tme);
        tdamage = tme / 3;

//        write("-------------------------\n");
//        write("Currect Target Ramdom Number is "+ ttarget+".\n");



//        write("Currect Me Ramdom A Number is "+ rdma+".\n");
//        write("Currect Me Ramdom B Number is "+ rdmb+".\n");
//        write("Currect Me Ramdom C Number is "+ rdmc+".\n");
//        write("-------------------------\n");

        //FIRST HIT

        me->add("neili", -400+random(100));

        msg = HIY"ֻ��$N��Ӱ�ζ������е�"+(me->query_temp("weapon"))->query("name")+HIY"��ɹ���ɲʱ�������ӰƮ���������Ǻÿ���\n��֪ͻȻָ��$n�����Ѩһ�С��޿ײ��롹��$n��ǰ������Ѩ������"+(me->query_temp("weapon"))->query("name")+HIY"��Ӱ�ӡ�\n" NOR;
        if( rdma > ttarget )
        {
  msg += HIG "$nֻ�о�����ҪѨ���ƣ��������в������ۿ���$N�Ĺ��������޲ߣ�������мܣ�\n���ǿ���Ѩ�����ƣ��ֱ�΢΢����һ�¾���Ҳ�������ˣ�\n\n" NOR;
                hone = 1;
                message_vision(msg+"\n", me, target);
                target->start_busy(2);
        }
        else
        {
                msg += HIR "û�뵽$n������ʤ����Ȼ���ұܿ���$N��������ʽ�������ͷ��Ҳ�������亹��\n\n" NOR;
                hone = 0;
                message_vision(msg+"\n", me, target);

                me->start_busy(2);
        }




        //Second Hit
        msg = HIY "������$N����һ�С�����������������"+(me->query_temp("weapon"))->query("name")+HIY"��ɨ$n�����ƫ��Ѩ�������ɲ���$n������\n" NOR;

        if( rdmb > ttarget )
        {
     msg += HIB "$nֻ�о�����һ��������������ʹ��Ҳû�������м��ˣ�\n\n" NOR;
                htwo = 1;
                  message_vision(msg+"\n", me, target);
                  target->start_busy(2);
        }
        else
        {
                msg += HIR "$n�ۼ�ҪѨ��Ҫ���ƣ���ͷ�ŵ���ָ����$Nϥ�䡸ί��Ѩ��������$N����֮��$nҲ�ܿ��ˡ�������������\n\n" NOR;
                htwo = 0;
                  message_vision(msg+"\n", me, target);
                  me->start_busy(2);
        }


        //Third Hit
        msg = HIY "ƾ��ǰ���е����ƣ�$N���־���һʽ���ݶ����ġ�������Ϊ������������$n���۾���\n�ʺ��С���������������򷨣����˸о����ǲ���ʣ�\n" NOR;
        message_vision(msg+"\n", me, target);
        if (rdmc > ttarget )
        {
                msg = HIW "ֻ���ã�ž��ž��ž�������죬$n��$N���е�"+(me->query_temp("weapon"))->query("name")+HIW"�ֱ�����۾����ʺ��С����һ����Ѫ��������������ֽ��\n" NOR;
                hthree = 1;
                  message_vision(msg+"\n", me, target);
                  target->start_busy(2);
//                msg = ""
        }
        else
        {
                msg += HIR "$n��������������ȫ���ܿ���$N��ɫ��Ȼ���������ɵĴӼ����������˳��������Ϻ�ˮҲ����������\n" NOR;
                hthree = 0;
                message_vision(msg+"\n", me, target);
                me->start_busy(2);
//                msg = ""
        }


// First Hit Damage Calculation
        if (hone = 1)
        {
                sdamage = tdamage;
                target->receive_damage("qi", sdamage,  me);
        }


// Second Hit Damage Calculation
        if (htwo = 1)
        {
                 sdamage = tdamage * 2;
                 target->receive_damage("qi", sdamage, me);
        }


// Third Hit Damage Calculation
         if (hthree = 1)
         {
                 sdamage = tdamage * 3;
                 target->receive_damage("qi", sdamage, me);
         }



// Combo  Hit Rate  1 2 3 All Hit

          if (hone = 1 && htwo = 1 && hthree = 1)
            {
                if(me->query("combat_exp")>target->query("combat_exp"))
                   sdamage = tdamage * 10;
                    target->start_busy(random(4));
                       target->receive_wound("qi",tdamage);
          }
          else if (hone = 1 && htwo = 1)
          {
                if(me->query("combat_exp")>=target->query("combat_exp"))
                    sdamage = tdamage * 6;
                  target->start_busy(random(3));
                       target->receive_wound("qi",tdamage);
          }
          else if (htwo = 1 && hthree = 1)
          {
                    sdamage = tdamage * 3;
                  target->start_busy(1);
                       target->receive_wound("qi",tdamage);
          }
          else if (hone = 1 && hthree = 1)
          {
                  if(!random(5))
                sdamage = tdamage * 4;
                  target->start_busy(1);
                       target->receive_wound("qi",tdamage);
          }


//  message_vision(msg+"\n", me, target);
  COMBAT_D->report_status(target);
  return 1;
}
