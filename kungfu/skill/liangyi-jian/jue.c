// Code Of ShenZhou
// �ٽ�˫��   (perform jue)
// Ҫ��     �����޼� 300 �������ǽ� 300 ���� (��� Quest)
// ˵����     �ٽ���һ�������ɾ�ѧ��       

#include <ansi.h>
#include <combat.h> 

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
mapping prepare_status; 
string weapon, op_weapon, op_skill, *pname; 
int my_power, op_power, my_li, op_li, my_jing, my_nei, op_jing, op_nei;
if( !target ) target = offensive_target(me); 

if( !target
||      !target->is_character() 
||      !me->is_fighting(target) ) 
        return notify_fail("������������ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 

if( me->query_skill_mapped("force") != "xuantian-wuji" ) 
return notify_fail("����ʹ�ò��������޼����������޷�ʩչ�������\n"); 

if( me->query_skill("force") < 350 )
return notify_fail("��������޼������δ�����޷��˾�ʩչ��������������\n"); 

if( me->query_skill("sword") < 400 ) 
return notify_fail("�����ǽ�����Ϊ���㣬������ʹ�á�������������\n");

if( me->query_skill("qinqi-shuhua",1) < 250 )
return notify_fail("�������黭��Ϊ���㣬������ʹ�á�������������\n");

if( me->query("neili") <= 500 ) 
return notify_fail("�����������ʹ�á�������������\n");  

if( me->query("jingli") <= 500 ) 
return notify_fail("��ľ�������ʹ�á�������������\n"); 


my_jing = me->query("jingli") *7/10; 
my_nei = me->query("neili") *7/10;
  if ( target->query("neili") < me->query("neili")*3/2 ) { 
op_nei = target->query("neili")*8/10;
}
else op_nei = my_nei;

if ( target->query("jingli") < me->query("jingli")*3/2 ) { 
op_jing = target->query("jingli") *8/10; 
}
else op_jing = my_jing;

message_vision(HIY"\n$NͻȻ��ͣ��ս���⣬�ͳ�һ�����٣�����һ�����������\n\n"
               HIG"�����仯�޳�����ͬ�ɾ��е�����������������$N��������ȴ����������������е�$n \n" NOR, me, target);

  my_power = me->query_skill("sword") + me->query_skill("dodge") + me->query_skill("force") + me->query_skill("parry") + me->query("combat_exp") / 900; 
  op_power = target->query_skill(op_skill) + target->query_skill("dodge") + target->query_skill("force") + target->query_skill("parry") + target->query("combat_exp") / 950; 

my_li = me->query("jingli") + me->query("neili"); 
op_li = target->query("jingli") + target->query("neili"); 

  if ( target->query("qi") < me->query("qi")*3/2 ) {
message_vision(RED"$N�������о��ѹ���������һ�������Ľ�������Ӱ��ͬ��������$N���ķ���\n\n" NOR, target);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
target->receive_wound("qi", target->query("max_qi")*7/10, me);
}

else if ( me->query_str() > target->query_str() ) { 
message_vision(RED"$N��ʱ���ѹ�������ȴ���Զ����һ��������һ�������ĲҺ������Ѵ����ķ���\n\n" NOR, target); 
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
target->receive_wound("qi", target->query("max_qi")/3, me); 
}

else if ( target->query("neili") < me->query("neili") ) { 
message_vision(RED"$N���ѹ����������Ѵ���$N���ķ�����$N����һ�������ĲҺ���\n\n" NOR, target); 
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);  
target->receive_wound("qi", target->query("max_qi")/4, me); 
}


else {
message_vision(HIY"$N�Ӿ����л��񣬻��������Ŷ�����������\n" NOR, target);
}

me->add("neili", -1*1000);
me->add("jingli", -700); 
  target->start_busy(3);
  me->start_busy(5);
target->kill_ob(me); 
return 1;
}
