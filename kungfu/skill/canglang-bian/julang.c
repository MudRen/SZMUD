// Code Of ShenZhou 
// by keny 5/18/2002 
// perform julang ���������죩 
// ������$1��Ȼ��$NƵƵ˦����$N������ž����֮�������ŵ�$2�ķ����ҡ� 
//  $1��������ǧ������ͷȴ����ָ��$2������ҪѨ��������������������޾�����$2ֻ���м�֮��ȴ�޻���֮����; 
// ���� by lnere 
      
#include <ansi.h>  
inherit F_DBASE;  
inherit F_SSERVER;  

int perform(object me, object target) 
{ 
object weapon; 
int skill; 
return notify_fail("���������졹��δ������ɡ�\n");
if( !target ) target = offensive_target(me); 

if( !target 
||      !target->is_character() 
||      !me->is_fighting(target) ) 
return notify_fail("���������졹ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 

if (!objectp(weapon = me->query_temp("weapon"))  
|| (string)weapon->query("skill_type") != "whip")  
return notify_fail("��û�б����֣�ʩ�������������졹��\n");  

if( (int)me->query("neili") < 200 )  
return notify_fail("�������������\n");  

if( me->query_skill("canglang-bian", 1) < 200 )  
return notify_fail("��ġ����˱޷� ��δ�����磬�޷�ʩ�����������졹��\n");  

if( me->query_skill("bitao-xuangong", 1) < 200 )  
return notify_fail("��ı���������Ϊ�������޷�ʩ�������˱޷�����\n");  

if( me->query_temp("wuzhuan"))  
return notify_fail("����������������δɢ������ͬʱ��������ʩչ���������졹��\n");  

if( me->query_skill_mapped("whip") != "canglang-bian" )  
return notify_fail("�����õĲ��ǡ����˱޷� ����ʩչ�������������졹��\n");  

message_vision(HIR"$N��Ȼ��"+(me->query_temp("weapon"))->query("name")+HIR"ƵƵ˦����"+(me->query_temp("weapon"))->query("name")+HIR"������ž����֮�������ŵ�$n�ķ����ҡ�\n" NOR, me, target);   
message_vision(HIB"$N��������ǧ������ͷȴ����ָ��$n������ҪѨ��������������������޾�����$nֻ���м�֮��ȴ�޻���֮����\n" NOR, me, target); 

me->set_temp("julang", 1); 

skill =  ( me->query_skill("canglang-bian") + me->query_skill("dodge") ) / 2; 

me->add_temp("apply/attack", skill/2); 
me->add_temp("apply/dodge",  skill/2); 
me->add_temp("apply/speed", 100);

COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

me->add("neili", -200); 
me->start_busy(random(2)); 

me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/2 :), skill/15); 

return 1; 
} 
      
private int remove_effect(object me, int amount) 
{ 
me->add_temp("apply/attack", -amount); 
me->add_temp("apply/dodge", -amount); 
me->add_temp("apply/speed", -100); 
me->delete_temp("julang"); 
message_vision(YEL"\n$N���������ڹ���������ѹ�£�\n\n" NOR, me);

return 0; 
} 
