// Code of ShenZhou
///kungfu/skill/riyue-lun/riyue.c 
// ����ͬ��
// snowbird Jan 2000

#include <ansi.h>
#include <combat.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        int skill, add, add2, damage, ap, pp, dp, busy_time;
        string *limbs, limb, str, weapon, *pfm_msg, msg, dodge_skill;
   object obj;

   obj = me->query_temp("weapon");
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�㲻��ս���С�\n");

   if (!(obj) || (obj->query("name")!="����" && obj->query("name")!="����"))
      return notify_fail("���������֣����ʩչ����ͬ�ԣ�\n");

        if( me->query_skill_mapped("hammer") != "riyue-lun" )
                return notify_fail("�����õķ������ַ�������ʩչ����ͬ�ԣ�\n");

   if( me->query_skill_mapped("force") != "longxiang-banruo" )
                return notify_fail("�����õĲ��������������ʩչ��������ͬ�ԣ�\n");

        if( me->query_skill("force") < 250 )
                return notify_fail("����ڹ���Ϊ�������ʹ�ò�������ͬ�ԣ�\n");

        if( me->query_skill("hammer") < 300 )
                return notify_fail("��������ַ�������\n");

        if( me->query("neili") <= 800 )
                return notify_fail("�������������\n");

        if( me->query("jingli") <= 600 )
                return notify_fail("��ľ���������\n");

   busy_time = 0;

   weapon = obj->name();

   pfm_msg = ({ 
   "$N̤��һ����"+weapon+"�������֣���$n���˹�ȥ������"+weapon+"��ת����$n�ҵ���",
   "$N�����ۣ���������Եһ������"+weapon+"�������һ�㣬�ڿ��к���ת������$n׷����ȥ��",
   "$N����ȥͻ����ȭ������һ�����ֱ�һ����"+weapon+
   "���Ʋ���ʮ��Ѹ�٣�������δ����������Ȼ�������Ƶ��Ͷ�֮����",
   "$Nʢŭ֮�£������Ƴ�"+weapon+"������ת�����ֽ����ӷɳ�����ʱ�����Ӽ������Ӿ�Ȼ��Ȼ������",
   "$N��������֮��ͬʱ˫��������������ϣ���"+weapon+
   "���Ƴ����۾�һ�㣬�ڿ������˰��Ȧ�ӣ���$n���ἱ׷��",
   "$N����Ծ�𣬽����е�"+weapon+"�ջء�"
   });

        me->set_temp("xueshan/riyue",1);

        skill = me->query_skill("hammer") + me->query_skill("force");
        if(skill>1200) skill=1200;
        add = skill / 4;
   if(add > 200) add = 200;
        add2 = add / 4;

        /* add power */
        me->add_temp("apply/attack",add);
        me->add_temp("apply/damage",add2);

/* This the first hit */
        msg = HIY"\n"+ pfm_msg[0] +"\n" NOR;
        message_vision(msg, me, target);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

/* This the second hit */

        me->add_temp("xueshan/riyue",1);

        me->add_temp("apply/attack",50);
        me->add_temp("apply/damage",10);

        msg = HIY"\n"+ pfm_msg[1] +"\n" NOR;
        message_vision(msg, me, target);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        /* Remove power */
        me->add_temp("apply/attack",-(add+50));
        me->add_temp("apply/damage",-(add2+10));

        busy_time = 2;
        if (skill > 700)
        {
                        /* This the third hit */
                        me->add_temp("xueshan/riyue",1);

                        msg = HIY"\n"+ pfm_msg[2] +"\n" NOR;
                        message_vision(msg, me, target);
         msg = HIW"\n$N���кȵ�����"+chinese_number(me->query_temp("xueshan/riyue"))+"�����ˣ�\n"NOR;
                        message_vision(msg, me);

        ap = COMBAT_D->skill_power(me,"hammer", SKILL_USAGE_ATTACK)*3;
        pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE);
        dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE);
                  ap = (ap+random(ap*2));

        if (ap > (pp+dp))
        {
                          damage = skill*1.5 + random(me->query("jiali") + me->query("jiajin"));
           if (damage > 1500) damage = 1500;

                                target->receive_damage("qi", damage,  me);
                                target->receive_wound("qi", (int)me->query_skill("hammer"), me);

                                me->add("neili", -(50 + me->query("jiali")/2));
                                me->add("jingli", -me->query("jiajin")/3);
           
           str = "$N������������"+weapon+"���صĻ����ؿڣ��۵����һ����Ѫ��\n";
                          message_vision(str,target);

                          str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
                          message_vision("($N"+str+")\n", target);
        }
                  else 
                  {
            limbs = target->query("limbs");
            dodge_skill = target->query_skill_mapped("dodge");
            if( !dodge_skill ) dodge_skill = "dodge";
            limb = limbs[random(sizeof(limbs))];
            str = SKILL_D(dodge_skill)->query_dodge_msg(limb);
            message_vision(str, me, target);
            busy_time = busy_time + 1;
                  }
        }

/* add power for my next 2 hits */
        me->add_temp("apply/attack", (add+50));
        me->add_temp("apply/damage", (add2+10));

   if (skill > 900)
   {
                /* This the forth hit */
                me->add_temp("xueshan/riyue",1);
                msg = HIY"\n"+ pfm_msg[3] +"\n" NOR;
                message_vision(msg, me, target);

                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
      busy_time = busy_time + 1;
        }

        me->add_temp("apply/attack", 50);
        me->add_temp("apply/damage", 10);

   if (skill > 1100)
   {
                /* This the fifth hit */
                me->add_temp("xueshan/riyue",1);
                msg = HIY"\n"+ pfm_msg[4] +"\n" NOR;
                message_vision(msg, me, target);

                COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
      busy_time = busy_time + 1;
        }

/* back to normal*/
        me->add_temp("apply/attack", -(add+100));
        me->add_temp("apply/damage", -(add2+20));

        msg = HIY"\n"+ pfm_msg[5] +"\n" NOR;
        message_vision(msg, me);

        if ( me->query("neili") > 250 )
                me->add("neili", -200);
        else me->add("neili", -(me->query("neili") - 10));
  
        if ( me->query("jingli") > 150 )
                me->add("jingli", -100);
        else me->add("jingli", -(me->query("jingli") - 10));

        me->delete_temp("xueshan/riyue");
        me->start_busy( busy_time+random(2) );

        return 1;
}
