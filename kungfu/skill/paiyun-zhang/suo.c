// Code Of ShenZhou
// ������ - ��������
// Keny's Skills

#include <ansi.h> 
inherit F_SSERVER;

int perform(object me, object target) 
{        
int mywx; 
string msg; 
object weapon; 
if( !target ) target = offensive_target(me); 
if( !target 
||      !target->is_character() 
||      !me->is_fighting(target) ) 
return notify_fail("������������ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 

if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))  
return notify_fail("������������ֻ�ܿ���ʹ�á�\n"); 

if( me->query_skill_mapped("strike") != "paiyun-zhang" )  
return notify_fail("�����õĲ��������ƣ�ʹ������������������\n");  

if( me->query("neili") <= 200 )  
return notify_fail("�����������ʹ�á�������������\n");  

if( me->query("jingli") <= 100 )  
return notify_fail("��ľ�������ʹ�á�������������\n");     

if( (int)me->query_skill("paiyun-zhang",1) < 70 )  
return notify_fail("��������ƻ�򲻹����޷�ʹ�á�������������\n");  

if( target->is_busy() ) { 
me->add("neili", 10); 
me->add("jingli", 5); 
return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n"); 
} 

msg = HIC"$Nһʽ"+NOR""+CYN"������������"+NOR"��"+HIC"��������˫�ƣ����������ѽ�$n�Ĺ�����Ϊ�㣬Ѷ�����������ġ����ƻ���$n��\n"; 
me->add("neili", -50); 
me->add("jingli", -20); 
mywx = me->query_int(); 
if( random( me->query("combat_exp") ) > random( target->query("combat_exp") ) || !living(target) ) 
{
msg += HIY"���$p��$P���˸���æ���ң�һʱ�޷����н�����\n" NOR; 
target->start_busy(12); 
} else { 
msg += HIY"$p˫��һ�ƣ�����ıܹ���$P�Ľ�����\n" NOR; 
me->start_busy(1+random(3)); 
} 
message_vision(msg, me, target); 
return 1; 
} 
