// Code Of ShenZhou 
// by keny 
// perform tianjing ��ʯ���쾪�� 
//  ����������ȭ��200���������޼�200���� 
// ������$1˫��Բ��ŭ��һ��������ƽ�ر��װ�������ĵ����ѡ� 
// $1Я����֮����������ȭӰ������ѩ����ʯ���쾪֮����������������$2��ľ�˰㶨�ڵ�������֪����мܡ� 
// ���� by lnere 
 
#include <ansi.h>  
#include <combat.h>  
inherit F_SSERVER;  

int perform(object me, object target)  
{  
int skill;
string msg;

if( !target ) target = offensive_target(me);  
if( !target || !target->is_character() || !me->is_fighting(target) )  
return notify_fail("��ʯ���쾪��ֻ�ܶ�ս���еĶ���ʹ�á�\n");  

if( objectp(me->query_temp("weapon")) )  
return notify_fail("�������ֲ���ʹ�á�ʯ���쾪����\n");                 

if( me->query_temp("quanjing")) 
return notify_fail("����������������δɢ������ͬʱ��������ʩչ��ʯ���쾪����\n"); 

if( me->query_temp("liushui")) 
return notify_fail("����������������δɢ������ͬʱ��������ʩչ��ʯ���쾪����\n"); 

if( me->query_temp("tianjing")) 
return notify_fail("������ʩչ��ʯ���쾪����\n");


if( (int)me->query_skill("zhentian-quan", 1) < 200 )  
return notify_fail("��ġ�����ȭ������!\n");  

if( (int)me->query_skill("xuantian-wuji", 1) < 200 )  
return notify_fail("��ġ������޼�������!\n");

if( (int)me->query("neili", 1) < 1000 )  
return notify_fail("����������̫��������ʹ�á�ʯ���쾪��!\n");  

if( (int)me->query("jingli", 1) < 500 )  
return notify_fail("�����ھ���̫��������ʹ�á�ʯ���쾪��!\n"); 

message_vision(RED"\n$N˫��Բ��ŭ��һ��������ƽ�ر��װ�������ĵ����ѡ�\n" NOR, me);  
message_vision(HIR"\n$NЯ����֮����������ȭӰ������ѩ����ʯ���쾪֮����������������$n��ľ�˰㶨�ڵ�������֪����мܡ�\n" NOR, me); 

me->set_temp("tianjing", 1); 

skill =  ( me->query_skill("zhentian-quan") 
+ me->query_skill("cuff") ) / 2; 

me->add_temp("apply/attack", skill/3); 
me->add_temp("apply/damage",  skill/6); 
me->add_temp("apply/dodge",  skill/2);
me->add_temp("apply/speed", 100); 

COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

me->add("neili", -1000); 
me->add("jingli", -500);  
me->start_busy(random(2)); 

me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/2 :), skill/5); 
return 1; 
} 

private int remove_effect(object me, int amount) 
{ 
me->add_temp("apply/attack", -amount); 
me->add_temp("apply/damage", -amount/3); 
me->add_temp("apply/dodge", -amount); 
me->add_temp("apply/speed", -100);

me->delete_temp("tianjing"); 
message_vision( HIY "\n$N����һ�������������ջص��\n\n" NOR, me); 

return 0; 
} 
