//三无三不手
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
                return notify_fail("三无三不手只能对战斗中的对手使用。\n");

        if( me->query_temp("sanwu",1) )
                return notify_fail("你已在使用三无三不手！\n");

        if( me->query_skill_mapped("force") != "yunu-xinjing" )
                return notify_fail("你并非使用玉女心经，无法施展三无三不手！\n");

        if( me->query_skill("yunu-xinjing", 1) < 120 )
                return notify_fail("你的玉女心经火候未到，无法施展三无三不手！\n");


         if( me->query_skill("whip",1) < 120 )
                return notify_fail("你的绝情鞭法修为不足，还不会使用三无三不手！\n");

//        skill =  ( me->query_skill("jueqing-bian")
//                + me->query_skill("force") ) / 5;

        if( me->query("neili") <= 500 )
                return notify_fail("你的内力不够使用三无三不手！\n");
        if( me->query("jingli") <= 500 )
                return notify_fail("你的精力不够使用三无三不手！\n");
        if( me->query("jing") <= 500 )
                return notify_fail("你的精不够使用三无三不手！\n");


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

        msg = HIY"只见$N身影晃动，手中的"+(me->query_temp("weapon"))->query("name")+HIY"舞成光球，刹时间周身白影飘忽不定甚是好看，\n哪知突然指向$n周身大穴一招「无孔不入」，$n身前身后各处穴道都是"+(me->query_temp("weapon"))->query("name")+HIY"的影子。\n" NOR;
        if( rdma > ttarget )
        {
  msg += HIG "$n只感觉身上要穴被制，真气运行不畅，眼看着$N的攻击束手无策，想出手招架，\n但是苦于穴道被制，手臂微微动了一下就再也动不了了！\n\n" NOR;
                hone = 1;
                message_vision(msg+"\n", me, target);
                target->start_busy(2);
        }
        else
        {
                msg += HIR "没想到$n险中求胜，居然侥幸避开了$N的凌厉招式，不免额头上也渗出了冷汗！\n\n" NOR;
                hone = 0;
                message_vision(msg+"\n", me, target);

                me->start_busy(2);
        }




        //Second Hit
        msg = HIY "紧跟着$N又是一招「无所不至」，手中"+(me->query_temp("weapon"))->query("name")+HIY"横扫$n周身诸处偏门穴道，再由不得$n躲闪！\n" NOR;

        if( rdmb > ttarget )
        {
     msg += HIB "$n只感觉身上一阵麻痒，浑身酸痛在也没有力气招架了！\n\n" NOR;
                htwo = 1;
                  message_vision(msg+"\n", me, target);
                  target->start_busy(2);
        }
        else
        {
                msg += HIR "$n眼见要穴道要被制，以头撑地伸指戳向$N膝弯「委中穴」，就在$N回身之际$n也避开了「无所不至」！\n\n" NOR;
                htwo = 0;
                  message_vision(msg+"\n", me, target);
                  me->start_busy(2);
        }


        //Third Hit
        msg = HIY "凭借前两招的威势，$N出手就是一式阴狠毒辣的「无所不为」，连环攻向$n的眼睛，\n咽喉和小腹。到像是无赖打法，让人感觉甚是不光彩！\n" NOR;
        message_vision(msg+"\n", me, target);
        if (rdmc > ttarget )
        {
                msg = HIW "只听得，啪！啪！啪！三声响，$n被$N手中的"+(me->query_temp("weapon"))->query("name")+HIW"分别抽中眼睛，咽喉和小腹，一口鲜血狂喷出来，面如金纸！\n" NOR;
                hthree = 1;
                  message_vision(msg+"\n", me, target);
                  target->start_busy(2);
//                msg = ""
        }
        else
        {
                msg += HIR "$n运起本门身法精华，全力避开。$N脸色戚然，凉气不由的从脊梁骨里钻了出来，脸上汗水也流了下来！\n" NOR;
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
