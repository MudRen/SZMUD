// /u/final/kungfu/skill/sanyin-zhua/wanghun.c
// final

/*  ####################################################################################
    Ϊ��ά�����ɵ�ƽ�⣬�Ҳ����xingxiu��ú�����������Ϊ����player�е����棬���������pfm
    ���pfm ���Ǻ�����  ����ҪҪ���ر�࣬������������xingxiu���а�����ɵ���ʵ��
    �������Ҫxingxiu���� ����Ҫ�ܶ�-shen ������Ҫɱ�ܶ��� �����������ٴ�.....��
<<----------------------------------------------------------------------------------->>
                ���pfmֻ���ο�
                ƥ��Ķ���  Ҳ����һ���Ϊ����˼�ɣ�
                :P
<<----------------------------------------------------------------------------------->>
    
*/



#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int myexp, targexp, damage, merand, targrand, targneili, time, i, whatt, skill, dodge, fk, fl, aaa;
        string str,*limb,type;
        string msg;
        mapping myfam;
        msg="";

        if( !target ) target = offensive_target(me);    if( !objectp(target) || target == me || target->query("id") == "mu ren"      || target->query("id") == "shangshan"      || target->query("id") == "mengzhu"     || target->query("id") == "fae" 
        || target->query("id") == "final" )             return notify_fail("��Ҫ��˭ʹ�����ꣿ\n");
        

     /*   if( !target
       ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

*/
//              if (!wizardp(me))
  //      return notify_fail("�⹦��Ŀǰ��������ҿ��š�\n");
        if ( (!( myfam= me->query("family")) || myfam["family_name"] != "������") && me->query("id")!="kies")
                  return notify_fail("�㲻�����޵���,��ôʹ����˺ݶ����书��\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("����������\n");

        if( me->query_skill_mapped("claw") != "sanyin-zhua" )
                return notify_fail("�����õĲ����������צ������ʩչ���꣡\n");

        if( me->query_skill_prepared("claw") != "sanyin-zhua" )
                return notify_fail("�������Ĳ����������צ������ʩչ���꣡\n");
        
        if( me->query_skill("qianzhu-wandu" ,1) < 100 )
                return notify_fail("��о�ƾ�����ڵ��ö����ɻ������ó����꣡\n");

        if( me->query_skill_mapped("force") != "huagong-dafa" )
                return notify_fail("����ڹ��޷����������ںϣ�\n");

        if( (int)me->query_skill("huagong-dafa",1) < 120 )
                return notify_fail("�㱾���ڹ��������������꣡\n");

        if( me->query_skill("sanyin-zhua",1) < 120 )
                return notify_fail("����书��ʽ�������ң�\n");
        
        if( me->query("shen") >= -10000 )
                return notify_fail("�������������𣿣�\n");
        if( me->query("PKS") <= 15 )
                                return notify_fail("�㻹û��ɱ�˲���Ѫ�ĳ̶Ȳ���ʹ�������!\n");
                if( me->query("MKS") <= 1000 )
                                return notify_fail("�㻹û��ɱ�˲���Ѫ�ĳ̶Ȳ���ʹ�������!\n");
                if( me->query("death_count") <= 20 )
                                return notify_fail("�����Ĵ���̫���ˣ�������Ҫ����Թ��ķ�ŭ!\n");
        if( me->query("neili") <= 500 )
                return notify_fail("�������������������ʹ�����꣡\n");
        if( me->query("jingli") <= 300 )
                return notify_fail("���������������ʹ�����꣡\n");     
        if( me->query("jing") <= 300 )
                return notify_fail("���������������ʹ�����꣡\n");

        message_vision(HIB"\n$NͻȻ������,������������������ԩ���ʱð������!��\n"NOR,me);
        message_vision(HIM"\n$Nͷ���ƺ�����һЩԹ��,���ƺ�����ɵ��!��\n"NOR,me);        
                
        me->start_busy(2);
        fk = ( me->query_skill("poison",1) + me->query_skill("sanyin-zhua",1) + me->query_skill("qianzhu-wandu",1))/3;
        whatt = ( me->query("PKS") + me->query_skill("poison")/10 + me->query_skill("qianzhu-wandu",1) / 10 ) / 3; 
        fl = target->query_skill("dodge", 1);
        message_vision(HIW"\n$NͻȻһ������,צ��$nץȥ!��\n"NOR,me,target);
        skill=random(whatt+random(50));
        
        if (skill>150) skill=200;
        if (skill<150) skill=100;
        aaa = skill*fk/10;
        dodge = target->query_skill("dodge", 1);
        if (fk<fl) {
                msg += HIG"$p�Ṧ�˵ã�˵ʱ�٣���ʱ��,�Ѿ����˹�ȥ��\n" NOR;            me->start_busy(3 + random(1));
}
        else {        msg += HIR "$n������,�Ѿ���$N��צץ�����ѡ�\n"NOR;                                         target->add("eff_qi",-aaa);                                     target->add("qi",-aaa);                                 target->add("jingli",-aaa/2);  }message_vision(msg, me, target);  return 1;}

