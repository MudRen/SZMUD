// Code of ShenZhou
// yinyang.c ������
// code by slow

#include <ansi.h>
#include <armor.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        int damage, jiali, jiajin, ap, dp, pp,dmg,lvl;
        int     value,level;
        string  msg,msg2,str;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�㲻��ս���С�\n");

        if ( objectp(me->query_temp("weapon")) )
                return notify_fail("�㲻�ǿ��֡�\n");

        if( (lvl=(int)me->query_skill("huoyan-dao", 1)) < 120 )
                return notify_fail("��Ļ��浶��Ϊ������\n");

        if ( me->query_skill_mapped("force") != "xiaowuxiang"
        && me->query_skill_mapped("force") != "longxiang-banruo")
                return notify_fail("�������ڹ����ԣ�\n");
              if (me->query("family/family_name") != "ѩɽ��")
          return notify_fail("����ѩɽ�ɵĶ��ž�ѧ��\n");

        if( me->query("neili") <= lvl*2 )
                return notify_fail("�������������\n");

        if( me->query("jingli") <= 150 )
                return notify_fail("��ľ���������\n");


        
        lvl = (int)(lvl / 5);
        me->add("neili", -lvl*2); 
        me->add("jingli", -100);  
        jiali = me->query("jiali");
        jiajin = me->query("jiajin");

        if ( !me->query("xueshan/yinyang") )
        me->set("xueshan/yinyang",1);
        
        value = me->query("xueshan/yinyang");
        level = value / 100 + 1;

        if (level > 9)
        level = 9;
        
       msg = HIY"$N������浶��"HIG+chinese_number(level)+"��������"+HIY",˫���籧Բ�������˳���$n�е��������������ȵ��ھ�\n�Ӳ�ͬ����Ϯ����\n"NOR;
        message_vision(msg, me, target);


        ap = COMBAT_D->skill_power(me,"strike", SKILL_USAGE_ATTACK);
        pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE)/3;
        dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE)/3;

        if (wizardp(me))
                printf("ap = %d , pp = %d , dp = %d .\n",ap*2,pp,dp);   

        ap = (ap+random(ap*2))/2.5;

        if( ap > dp ) {
                damage = 500 + level*(jiali + jiajin/2 + 1000) + lvl * 4;
                dmg = damage;
                damage = (damage + random(damage * 2)) / 2;
                if (damage > dmg )  damage = dmg + random(damage/20);
                
                if (wizardp(me)) printf("damage = %d\n",damage);
                if ((int)damage/target->query("eff_qi")*100>=100) {
                        message_vision(HIR "ֻ��$N��˫�ƽ�ʵ��ӡ��$n���ؿ�,$n������Ѫ�������ѱ�$N��ϡ�\n\n" NOR, me,target);
                        if (target)
                        target->die();
                        return 1;
                }
                
                if ((int)damage/target->query("eff_qi")*100>=50&&(int)damage/target->query("eff_qi")*100<100)
                        message_vision(HIR "$nֱ���Ŀ�һ����Ѫ�Ѵӿ��������\n\n" NOR, me,target);
               
                if ((int)damage/target->query("eff_qi")*100<50)
                        message_vision(HIR "$n�ۼ���������ڹ�������ֱ���������ھ�ӿ���ؿڣ�������Ѫ���ڡ�\n\n" NOR, me,target);
                
                target->receive_damage("qi", damage,  me);
                target->receive_wound("qi", damage/2+random(damage/2), me);
                target->start_busy(1+random(2));   
                
                str = COMBAT_D->status_msg((int)target->query("eff_qi") * 100 /(int)target->query("max_qi"));
                message_vision("($N"+str+")\n", target);
                                                                                     // target busy time > own busy time
                me->start_busy(3+random(2));
                if(jiali > me->query("neili"))
                jiali = me->query("neili");
                if(jiajin > me->query("jingli"))
                jiajin = me->query("jingli")-1;
            
                me->add("neili", -jiali-lvl);                                                               // cost neili 140
                me->add("jingli", -jiajin-lvl/2); 
                
                if (target->query("combat_exp") > me->query("combat_exp") && random(level*level*4) == 0 
       && me->query("xueshan/yinyang") < 900 && lvl*5 >(level*60 + 40)) 
                {
                me->set("xueshan/yinyang",value + 1);  
                tell_object(me,HIC"�㷴��ʹ�������������������������Ŀ��ƣ��ƺ����˸�����˽⡣\n"NOR);
                }
         
        }
        else
        {
                message_vision(HIW "$n������$N��ͼ��������Ц�����ֻ��⡣\n" NOR, me, target);
                me->start_busy(3+random(3));
        
                
        }
      


        return 1;
}
