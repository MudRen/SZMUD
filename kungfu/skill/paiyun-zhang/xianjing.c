// Code Of ShenZhou
// ������ - �������ɾ���
// Keny's Skills

#include <ansi.h> 
inherit F_SSERVER; 

int perform(object me, object target) 
{ 
string msg; 
int damage; 
object weapon,ob; 
int skill, jiali, my_rate, your_rate; 

jiali=(int)me->query("jiali"); 
weapon = me->query_temp("weapon"); 

if(me->is_busy()) 
return notify_fail("����æ���أ�\n"); 

if( !target ) target = offensive_target(me); 
if( !target 
||      !target->is_character() 
||      !me->is_fighting(target) ) 
return notify_fail("�������ɾ���ֻ����ս����ʹ�á�\n"); 

if (me->query_temp("weapon") || me->query_temp("secondary_weapon")) 
return notify_fail("�������ɾ���ֻ�ܿ���ʹ�á�\n"); 

if( me->query_skill_mapped("strike") != "paiyun-zhang" ) 
return notify_fail("�����õĲ��������ƣ�ʹ�����������ɾ�����\n"); 

if( (int)me->query_skill("paiyun-zhang",1) < 200 ) 
return notify_fail("��������ƻ�򲻹����޷�ʹ�á������ɾ�����\n"); 

msg = HIG "\$N�˹��ɶ����������һ����ϼ���ԴԵİ�Χ��$n��$nͻ��е�ȫ��Ӳ�ƻ��У�ԭ��$N��ʹ�����������е�����"+MAG"�������ɾ���"+NOR"\n" NOR; 
msg += RED "$NͻȻ������$n����ǰ�����Ե���������������,ֻ��$Nһ����Х��˫�Ʒ��裬���Ʒƶ���˼��\n"NOR;  

if( random( me->query("combat_exp") ) > random( target->query("combat_exp") ) || !living(target) ) 
{ 
damage = random(  me->query_skill("force") + me->query_skill("strike") + me->query("jiali") )*( 1 + random(me->query("jiajin")*10) ) ; 
if(damage > 4000) damage = 5000; 
if(damage < 1000) damage = 2000; 
me->add("neili", -1000 ); 
me->add("jingli", -500); 

target->receive_damage("qi", damage,  me); 
target->receive_wound("qi", random(damage), me); 
target->start_busy(1+random(3)); 

msg += HIR"\n$N��$n��æ����֮�ʣ�����Ծ��$n��ǰ�����������,����ͬʱ����$n��С����\n"NOR; 

msg += NOR; 
me->start_busy(2+random(2)); 
} 

else { 
msg += HIY"\n$nͻȻ����һ˿�����⣬�����һԽ��������վȦ�⡣\n\n"NOR; 
me->add("neili", -jiali*2 ); 
me->add("jingli", -me->query("jiajin") ); 
me->start_busy(2 + random(2)); 
message_vision(msg+"\n", me, target); 
return 1; 
} 

message_vision(msg+"\n", me, target); 
COMBAT_D->report_status(target); 
return 1; 
} 
