// Code of ShenZhou
// zhentian ����
// By keny 
// ����ȭ�� 160 ���������޼� 120 ����
// ��ʱ���ӱ�������߹�����

#include <ansi.h>
inherit F_CLEAN_UP;

void remove_effect(object me,int amount);

int perform(object me, object target)
{
int original, skill;

if( objectp(target) && target != me) 
return notify_fail("���������������˵�ս������\n");

if( !me->is_fighting() ) 
return notify_fail("�������ս���в���ʹ������ȭ����\n");

if( me->query_temp("weapon") )
return notify_fail("��ֻ���ڿ���ʱʹ������ȭ����\n");

if( (string)me->query_skill_mapped("force") != "xuantian-wuji" ) 
return notify_fail("�㶼û�����˼ҵ��ķ�����ôʩ�Ծ���ѽ��\n"); 

if( me->query_skill("xuantian-wuji", 1) < 120 )
return notify_fail("��������޼����δ�����޷�ʩչ����ȭ����\n");

if( me->query_skill("zhentian-quan", 1) < 160 )
return notify_fail("�������ȭ���δ�����޷�ʩչ����ȭ����\n");

if( me->query("max_neili") <= 500 )
return notify_fail("���������Ϊ���㣬���������˷����޷�ʩչ����ȭ����\n");

if( (int)me->query("neili") < 500  )
return notify_fail("�������������\n");

if( (int)me->query_temp("quanjing") )
return notify_fail("���Ѿ�����������ȭ����\n");

skill = me->query_skill("zhentian-quan", 1);
original = me->query_str();
me->add("neili", -skill*2);
me->receive_damage("jingli", skill);

message_vision(
HIR "\n $N��������ȭ�������ؾ���˫��ȭ�����ӿ���ڱ��ϣ���ͬ��������֮����ȭ���ϡ�\n" NOR, me);

me->add_temp("apply/strength", original*2);
me->set_temp("quanjing", 1);
me->start_call_out( (: call_other, __FILE__, "remove_effect", me, original :), skill/6);
me->start_busy(1);
return 1;
}

void remove_effect(object me, int amount)
{
me->add_temp("apply/strength", - 2*amount);
me->delete_temp("quanjing");
tell_object(me, YEL"�㻺������һ�����������������ķ��ɣ��ջ�����ȭ����\n"NOR);
}
