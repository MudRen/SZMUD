// Code Of ShenZhou
// ������  -  ������Ӱ
// Keny's Skills

#include <ansi.h> 
inherit F_DBASE; 
inherit F_SSERVER; 

int perform(object me, object target) 
{
int dex, skill;

if(!target) target = offensive_target(me); 
if( !target || !target->is_character() || !me->is_fighting(target) ) 
return notify_fail("��������Ӱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 

if( me->query_temp("paiyun/meiying")) 
return notify_fail("�������˹���!\n");   

if( (string)me->query_skill_mapped("dodge") != "paiyun-zhang" )   
return notify_fail("��û�н��������������ϣ��޷�ʹ����������Ӱ����\n");  

if( objectp(me->query_temp("weapon")) ) 
return notify_fail("���ֲ���ʩչ��������Ӱ��\n"); 

if( me->query_skill_prepared("strike") != "paiyun-zhang" ) 
return notify_fail("�������Ĳ��������ƣ�����ʩչ��������Ӱ����\n"); 

if( me->query("neili") <= 400 ) 
return notify_fail("�����������ʹ�á�������Ӱ����\n"); 

if( me->query("jingli") <= 400 ) 
return notify_fail("��ľ�������ʹ�á�������Ӱ����\n");    

if( (int)me->query_skill("paiyun-zhang",1) < 150 )   
return notify_fail("��������ƻ�򲻹����޷�ʹ�á�������Ӱ����\n");   

message_vision(HIB"\n$NͻȻ���Ժ�����һ˿��Ѱ��������"+HIM"��������Ӱ��"+NOR""+HIB"�����޳���Ʈ�첻������\n"NOR, me);   

me->set_temp( "paiyun/meiying", 1 );

dex = me->query_skill( "dodge" ); 
dex = dex / 2; 
me->add("neili",-500); 
me->add("jingli",-500); 
me->add_temp("apply/dodge",dex); 
skill = (me->query_skill("paiyun-zhang",1))/ 2; 
me->start_call_out( (: call_other, __FILE__, "end_perform", me, dex :),skill/8);
return 1; 
}

void end_perform( object me, int dex) 
{
me->add_temp("apply/dodge", -dex); 
me->delete_temp( "paiyun/meiying" ); 
message_vision(HIB"\n$N����ͣ���ǹ���Ӱ�����в����Ͷ������ԭ��\n"NOR, me);
}
