       // Code by Slow
     
#include <ansi.h>
      inherit F_DBASE; 
      inherit F_SSERVER; 
       
      int perform(object me, object target) 
      { 
              object weapon; 
              int myexp, targexp, damage, skill, merand, targrand, targneili,time,i; 
              string str,*limb,type; 
              mapping myfam; 
              int tmp_jiali,dmg;
         int num;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ŭ�����Ρ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ( (!( myfam= me->query("family")) || myfam["family_name"] != "��Ĺ��") )
                  return notify_fail("ֻ�й�Ĺ���Ӳ����á�ŭ�����Ρ���\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("���ֲ���ʩչ��ŭ�����Ρ���\n");

        if( me->query_skill_mapped("force") != "yunu-xinjing" )
                return notify_fail("�����õĲ�����Ů�ľ���ʹ������ŭ�����Ρ���\n");

        if( (int)me->query_skill("yunu-xinjing",1) < 120 )
                return notify_fail("���ڹ���Ϊ̫��������á�ŭ�����Ρ���\n");

        if( me->query_skill("xiaohun-zhang",1) < 120 )
                return notify_fail("����Ȼ��������Ϊ̫��������á�ŭ�����Ρ���\n");
         if ( !living(target))    
              return notify_fail("���ڲ�û��Ҫ�á�ŭ�����Ρ��ѣ�\n");  
          if (me->query_temp("jingtao_time"))
                return notify_fail("��ŭ�����Ρ����������޴󣬲���Ƶ��ʹ�ã�\n");
/*
         if (!me->query("canjingtao"))
           return notify_fail("�����ڻ�ûѧ�ᣡ\n");
*/

        if( me->query("neili") <= 1000 )
                return notify_fail("�����������ʹ�á�ŭ�����Ρ���\n");
        if( me->query("jingli") <= 500 )
                return notify_fail("��ľ�������ʹ�á�ŭ�����Ρ���\n");     
      if( me->query("jing") <= 200 )
               return notify_fail("��ľ�����ʹ�á�ŭ�����Ρ���\n");
          if( me->query_skill_prepared("cuff") == "meinu-quan" ) {
          me->set_temp("restore", 1);
          me->prepare_skill("cuff");
          }
message_vision(HIR"\n$N���Ʒ��������ų�ӿ֮�����Ʒ�ĵ��������п�ӿ���������������������ڴ��������ľ����� \n"NOR,me,target);
message_vision(HIG"\n$N��$n�������ϣ������˲��ܿ������š��겻���ᡱ����������ʩ������������ʧ�����������С�\n"NOR,me,target);
message_vision(HIG"������һ�С���ʬ���⡱���߳�һ�š�\n"NOR,me,target);
        skill=me->query_skill("xiaohun-zhang",1);
         num=(int)(skill/5);
             tmp_jiali=me->query("jiali");
        me->set("jiali",0);
        me->add_temp("apply/strength",num);
        me->add_temp("apply/damage",(num*3+40));
        me->add_temp("apply/attack",num);
        me->set_temp("perform/jingtao",1);
        me->set_temp("jingtao_time",1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           me->add_temp("perform/jingtao",1);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
           me->add_temp("perform/jingtao",1);
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->add_temp("perform/jingtao",1);
        me->add_temp("apply/strength",-num);
        me->add_temp("apply/attack",-num);
        me->add_temp("apply/damage",-(3*num+40));
          me->delete_temp("perform/jingtao");
        if (random(me->query("combat_exp")*2)>target->query("combat_exp"))
//        && skill>200 && random(2)=0)
          {
            message_vision(HIB"$N��һ�ŷ���ʱ�л��㱣�����ԼԼ���������ޣ�$n����ܵù��ˣ����һ�죬�����ؿڡ�\n"NOR,me,target);
            message_vision(HIB"$n���һ����һ����Ѫ���!\n"NOR,me,target);
              dmg = me->query_skill("force")+me->query_skill("strike")+me->query("jiajin");
              dmg = dmg + random(dmg*2);   
              target->receive_damage("qi", dmg,  me);
              target->receive_wound("qi", random(dmg), me);
          COMBAT_D->report_status(target); 
          }
          else {
            message_vision(HIB"$n������Ʈ������������:�������������������ɱܿ���\n"NOR,me,target);
           me->start_busy(1+random(2));
            }
        me->add("neili", -350);
        me->add("jingli", -150);
         me->set("jiali",tmp_jiali);
        

        if( me->query_temp("restore") ) me->prepare_skill("cuff", "meinu-quan");
                        
           call_out("remove_effect",5,me);

        return 1;
}        
void  remove_effect(object me)
{
       me->delete_temp("jingtao_time");
}
