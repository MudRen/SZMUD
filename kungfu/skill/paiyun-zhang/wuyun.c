// Code Of ShenZhou
// ������ - ���Ʊ���
// Keny's Skills

#include <ansi.h>  
inherit F_DBASE; 
inherit F_SSERVER;  

int perform(object me, object target)  
{ 
object weapon; 
int ap,dp, amount,damage,dam;   
string str; 
if( !target ) target = offensive_target(me); 
if( !target   
||      !target->is_character()   
||      !me->is_fighting(target) )  
return notify_fail("�����Ʊ��ա�ֻ�ܶ�ս���еĶ���ʹ�á�\n");  

if (me->query_temp("weapon") || me->query_temp("secondary_weapon")) 
return notify_fail("�����Ʊ��ա�ֻ�ܿ���ʹ�á�\n");  

if( me->query_skill_mapped("strike") != "paiyun-zhang" )  
return notify_fail("�����õĲ��������ƣ�ʹ���������Ʊ��ա���\n"); 

if( (int)me->query_skill("paiyun-zhang",1) < 300 )  
return notify_fail("��������ƻ�򲻹����޷�ʹ�á������ɾ�����\n");

if( me->query("neili") <= 1200 )
return notify_fail("�����������ʹ�á����Ʊ��ա���\n");  

if( me->query("jingli") <= 800 )  
return notify_fail("��ľ�������ʹ�á����Ʊ��ա���\n");

message_vision(YEL"$N��ʹһ��"+WHT"�����Ʊ��ա�"+NOR""+YEL"����ʽ�ճ�����������������������һƬ���ƣ�$N�Ծ����ٵ�����$n��ǰ�����صĻ��������ƣ�ʹ$n���һ����\n"NOR,me,target);             

amount = (int)me->query_skill("strike")/4;  
if ( amount < 60 ) amount = 60; 
if ( amount > 100 ) amount = 100; 
me->add_temp("apply/damage",amount*3);     
me->add_temp("apply/attack",amount*4);    
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);   
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);    
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);   
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1); 
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1); 
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1); 

if (living(target) && !target->is_ghost() && target->query("eff_qi")>=0 && target->query("qi")>=0)      
{    
ap=me->query_skill("strike",1)+me->query_skill("paiyun-zhang")/4; 
dp=target->query_skill("parry",1); 
if ((random(ap)>dp/2)) {   
message_vision(HIW"$P��ǰ���������һ��"+RED"�����ƾ���"+NOR"��ǰ��ȥ����һ�ƺñ�ǧǧ����Ŀ���һӿ���ϣ���$n��ȥ��\n" NOR, me, target);       
dam=me->query_skill("paiyun-zhang",1)*(random(3)+2); 
target->receive_wound("qi", dam/2);    
target->receive_damage("qi",dam);  
me->add("neili", -1200); 
me->add("jingli", -500);      
COMBAT_D->report_status(target);   
}   

else       
{    
me->add("neili", 100);  
me->add("jingli", 100);   
target->start_busy(2);   
message_vision(HIY"$pͻȻ����һ˿�����⣬�����һԽ��������վȦ�⡣\n" NOR,me,target);       
}   
}   
target->start_busy(random(4)+1);   
me->add("neili", -1000);    
me->add("jingli", -400);  
me->add_temp("apply/damage",-amount*3);        
me->add_temp("apply/attack",-amount*4);    
return 1;  
} 
