// Code Of ShenZhou
// ���ǽ� ������ɫ(Perform wushengse)
// by keny, earl

#include <ansi.h>
inherit F_SSERVER;

void remove_temp(object me)
{
if (me->query_temp("pfm_wushengse"))
me->delete_temp("pfm_wushengse");
}

int perform(object me, object target)
{
object weapon; 
int amount,damage; 

if (me->query_temp("pfm_wushengse"))
{
return notify_fail("��ĵ��������˵����д�׾�ˣ����������˲ų����ɣ� \n");
}

if ( !target ) target = offensive_target(me);

if( !target || !target->is_character()) 
return notify_fail("�����˭��ʩ���˼���\n");

if( environment(target)->query("no_fight")) 
return notify_fail("С�Ĵ��ƶ����ˡ�\n"); 

if(target->query_temp("surrender/ownder")!=0) 
return notify_fail("�����ڲ�����������ʩ���˼�!"); 

if( me->query_skill("sword") < 150 )
return notify_fail("������ǽ����������޷�����˼����衣\n"); 

if( me->query_skill("force") < 200 ) 
return notify_fail("�ڹ����⹦��Ҫ��Ҫ�ɣ��ҿ��㻹�����ڹ��ϻ���ʱ��ɡ�\n"); 

if (me->query("neili") < 600) 
return notify_fail("��������������޷�ʩ����\n"); 

amount = (int)me->query_skill("sword")/4;
if ( amount < 60 ) amount = 60; 
if ( amount > 100 ) amount = 100;
me->add_temp("apply/damage",amount*2);
me->add_temp("apply/attack",amount*3); 

if(target->query("combat_exp") < me->query("combat_exp")) 
{
message_vision(HIG"\n$N������"+(me->query_temp("weapon"))->query("name")+HIG"��ͻȻʹ�������ɽ�ѧ�еľ���"+HIC"��������ɫ����"+HIG"ͬʱ����$n�����ȥ��\n" NOR, me, target); 
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
}

else {
message_vision(HIY"\n$n���������ͣ��߸߷����˵�һ���⣬����˴˼���\n"NOR,me,target);
}

me->set_temp("pfm_wushengse", 1); 
call_out("remove_temp", 5, me); 
target->kill_ob(me); 
me->add("neili", -400); 
me->add("jingli", -400); 
me->add_temp("apply/damage",-amount*2); 
me->add_temp("apply/attack",-amount*3);
return 1;
}
