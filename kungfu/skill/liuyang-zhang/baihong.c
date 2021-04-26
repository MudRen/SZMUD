// baihong.c ���׺�������
// Modified by xuanyuan 8/2001

/*
����ˮ������Ԯ�֣��ܹ���ͯ�ѵļ�������Ϣ��Ȼ���ȣ�˵���������ɣ���
�Ѳ����£����ÿ��ɡ��������ĳ�������һ��������֮���ƹ��������ϣ���
ͯ�ѹ�ȥ��ͯ�����°�����������˾�Ȼ�����ˡ��׺�����������ֱ���⣬
�����˵á�������������ӭ��
*/

#include <ansi.h>
void remove_effect(object me,int strike);

int perform(object me)
{
	int force, strike;

	if( !me->is_fighting() )
		return notify_fail("���׺�������ֻ����ս����ʹ�á�\n");

//	if( !me->query("lingjiu/baihong") )
//		return notify_fail("��δ�ø���ָ�㣬��֪�����ʩչ���׺���������\n");

	if( me->query_temp("yield") )
		return notify_fail("�㲻���У����ʹ�����׺���������\n");

	if( me->query_temp("lingjiu/baihong") )
		return notify_fail("���Ѿ���ʹ�á��׺��������ˣ�\n");

	if ( me->query_skill_mapped("force") != "xiaowu-xiang"
		&& me->query_skill_mapped("force") != "bahuang-gong"
		&& me->query_skill_mapped("force") != "beiming-shengong")
		return notify_fail("�����õ��ڹ��롸�׺��������ķ���㣣�\n");

	if( (int)me->query_skill("strike", 1) < 120 )
		return notify_fail("����Ʒ���Ϊ������������ʩչ���׺���������\n");

	if( (int)me->query_skill("force", 1) < 120 )
		return notify_fail("����ڹ���Ϊ���δ�㣬�޷��԰������������磡\n");

	if( me->query("max_neili") <= 1500 )
		return notify_fail("�������������������޷��������磡\n");

	if( me->query("neili") <= 500 )
		return notify_fail("������������������޷��������磡\n");

	if( me->query("jingli") <= 200 )
		return notify_fail("����������ޣ�����ʩչ���׺���������\n");

	me->add("neili", -100);
	me->add("jingli", -150);

	force = me->query_skill("force")/2;
	strike = me->query_skill("strike")/2;

	me->add_temp("apply/attack", strike);
	me->set_temp("lingjiu/baihong", strike);

	message_vision(WHT "\n$N�����ĳ�������һ��������֮�����²�����
���Ź���������ң���ϳ��Ʒ��е�"+ HIW +"���׺�������"+ NOR + WHT +"���˿�$N������ֱ���⣬�����˵ã�\n"NOR, me);

	call_out("checking", 1, me, strike);
	return 1;
}

void checking(object me, int strike)
{
	if( !me ) return;

	if( !living(me) || me->is_ghost() )
	{
		remove_effect(me, strike);
		return;
	}
	else if( !me->is_fighting() && !me->is_busy() )
	{
		remove_effect(me, strike);
		message_vision(WHT "\n$N����һ�ӣ�������ǰ�ػ��˸��������������²�����������\n"NOR, me);
		me->start_busy(1);
		return;
	}
	else if( (int)me->query("neili") < (int)me->query("max_neili") / 5 ||
		(int)me->query("jingli") < (int)me->query("max_jingli") / 4 )
	{
	        remove_effect(me, strike);
        	tell_object(me, HIR "\n��΢����Ϣ���������ò��������ջأ�\n" NOR);
		message("vision", CYN+"\n"+ me->name() +CYN"˫��һ�ͣ������Ѳ���֮ǰ�����޳�����ò�����\n"NOR, environment(me), me);
		me->start_busy(2);
		return;
	}
	else if( me->query_skill_mapped("strike") != "liuyang-zhang" && !me->is_busy() )
	{
		remove_effect(me, strike);
		message_vision(CYN "\n$NȦת���ƣ�ͻȻ���У������Ѳ���֮ǰ�����޳�����ò�����\n"NOR, me);
		return; 
	}
	else if( me->query_temp("lingjiu/baihong") <= 50 )
	{
		remove_effect(me, strike);
		message_vision(HIC "\n$N����Ȧת���ѿ�����һ·"+ HIW +"���׺�������"+ HIC +"����ʹ����\n"NOR, me);
		return; 
	}

	call_out("checking", 1, me, strike);
} 

void remove_effect(object me, int strike)
{
	me->delete_temp("lingjiu/baihong");
	me->add_temp("apply/attack", -strike);
}
