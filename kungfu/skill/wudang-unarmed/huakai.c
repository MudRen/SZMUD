// Code of ShenZhou
// huakai.c ����֮���������١�
// xQin 11/00

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	object ob;
	string msg;
	int skill;
	
	if( !target ) target = offensive_target(me);
	if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��������ֻ�ܴ���ս���еĶ��֡�\n");
                
        if( me->query_temp("yield") )
                return notify_fail("�㲻���ƣ���ô�ܳ����������١���\n");
        
   /*     if( objectp(ob = me->query_temp("huakai")) )
	{
                if( ob->is_fighting(me) )
                	return notify_fail("���Ѿ��ڳ����������١��ˡ�\n");
        }
     */   
        if( (int)me->query_skill("mian-zhang", 1) < 99)
        	return notify_fail("������Ʋ������죬��δ�ܳ��˾��С�\n");
        
        if( (int)me->query_skill("taiji-shengong", 1) < 79)
        	return notify_fail("���̫������Ϊ���������ܳ����������١���\n");
        	
        if( (int)me->query("jiali") > 2 || (int)me->query("jiajin") > 2)
        	return notify_fail("�㷢�ּ������޷����������������ޣ�����������Ҫ�����ӳ�����\n");
                
        msg = WHT "\n$N��������һ������һ�С��������١����ֻ����ͻ�$n���Ҽգ����ֳ�ָ����$n�ġ�ȱ��Ѩ����\n";
        
        me->add("neili", -30 +random(-20));
        me->add("jingli", -15 +random(-15));
        
	
        if( random(me->query("combat_exp") * me->query_skill("force") /100+ random(10) ) >
        (int)target->query("combat_exp") * target->query_skill("force") /200 ) {
        
		me->start_busy(2);
		call_out("huakai", 1, me, target);
	}
	else
	{
		msg += YEL"����$p�ѿ��ƴ��У����Ų�æ�ıܿ��ˡ�\n"NOR;
		me->start_busy(1+random(3));
		}
	
		message_vision(msg, me, target);
	
	return 1;
	

}	
int huakai(object me, object target)
{
	int damage, tjsg, mz, nl;
	
	if( !me->is_fighting(target) || !living(target) ) return 0;
	tjsg = (int)me->query_skill("taiji-shengong");
	mz = (int)me->query_skill("strike");
	nl = (int)me->query("neili");
	
	if( random(me->query_skill("taiji-shengong") * me->query("neili")/100 > 
	(int)target->query_skill("force") * (int)target->query("neili") /200 ) 
	|| (int)me->query_skill("mian-zhang", 1) > 119 )
	{
		me->set_temp("double_huakai");
		damage = mz + tjsg/random(2);
		target->receive_damage("qi", damage, me);
		target->receive_wound("qi", damage/3, me);
		target->add("neili", -(damage/4));

		me->add("neili", -damage/10);
		message_vision(WHT"$P˫�ֵ���֮�󣬸������ƻ�$p��գ�����ʳָ��$p�Ҽ��ȱ��Ѩ����\n"
		               "�����С��������١�����һ�У�������ʽ�����籩�������ʹ�����Ƶ�֮�ͣ��ַ�֮�죬�����ͬС�ɣ�\n"NOR, me, target);
		return 1;               
	}
	else
	{

		damage = mz + tjsg/random(3);
		target->receive_damage("qi", damage, me);
		
		target->receive_wound("qi", damage/4, me);
		target->add("neili", -(damage/5));
		
		me->add("neili", -damage/9);
		message_vision(RED"���ֻ��$p���һ���������������³���һ����Ѫ��\n"NOR, me, target);
		return 1;
	}
	
	
}
