// revive.c
// by Xuanyuan   7/2001
/*��������������ƣ�����ϱ��������Ǻ����̹�����������֮�����������ս�ǰ
��������ָ�������ѷ������Ů�Ӷϱ۴���Ѩ����Ѫ����ֹ�������ε�ָʱ��ʹ����
ͯ�����̵�һ�С�������������һ�ɵı�ڤ�����������ı۸����и�Ѩ���С���Ů��
��������һ����У�����ת����
*/

#include <ansi.h>

int exert(object me, object target)
{	
	if( !target )		
		return notify_fail("���Լ������ѵ���\n");	

	if( me->is_fighting() || target->is_fighting())		
		return notify_fail("ս�����޷��˹���\n");	

	if(target == me)		
		return notify_fail("�㲻�ܶ��Լ��˹���\n");	

	if( (int)me->query("max_neili") < 1000 )		
		return notify_fail("���������Ϊ������\n");	

	if( (int)me->query("neili") < 350 )		
		return notify_fail("�������������\n");        

	if( living(target) )		
		return notify_fail( target->name() +"�Ѿ������ѵģ�\n");	

	message_vision(HIY "$N������ָ������һ�С�������������һ����������$n�ı۸����и�Ѩ���С�\n\n" NOR,me, target );	

	target->revive(); 
    	
	me->add("neili", -250);	
	me->set("jiali", 0);                
	me->start_busy(2);                
	target->start_busy(2);	

	return 1;
}