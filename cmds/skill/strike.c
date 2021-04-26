// strike.c, by FunBoo@sz

#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_DBASE; 
inherit F_SSERVER;

// A string array which has body positions strings
#include "/include/s_body_positions.h"

int main(object me, string arg)
{
	object target;
	int i;

	if(me->is_fighting())
	{
		target = offensive_target(me);
	}

	if(!arg)
	{
		return notify_fail("��Ҫ�������˵��ĸ���λ��\n");
	}

	if(me->is_busy())
	{
		return notify_fail("������æ��������������\n");
	}

	if(!me->is_fighting())
	{
		return notify_fail("�㲻��ս���У�������������\n");
	}

	// Target is not in defensive combat mode
	if(objectp(target) && !target->query_temp("n_Defensive_Combat_Mode"))
	{
		return notify_fail(target->query("name")+"���ڷ��أ��㲻������������ʹ�����⹥����\n");
	}

	for(i=0; i<sizeof(s_Body_Positions); i++)
	{
		if(arg == s_Body_Positions[i] && objectp(target))
		{
			message_vision(HIC+"$N��$n��"+arg+"չ�����ҵĹ�����\n"+NOR, me,target);

			// If hits the right position
			if(arg == target->query_temp("s_DCM_Weak_Point"))
			{
				message_vision(HIC+"$N��"+arg+"�ܵ���������ʱ��æ���ҡ�\n"+NOR, target);
				target->start_busy(3);	// Start busy
				target->delete_temp("s_DCM_Weak_Point");	// Delete the weak point
				target->delete_temp("n_Defensive_Combat_Mode");	// Off combat mode
				return 1;
			}

			// If hits the fight position
			if(arg != target->query_temp("s_DCM_Weak_Point"))
			{
				message_vision(HIC+"$N����������������$nһ�󼱹����󣬲��ò�ֹͣ������\n"+NOR, target, me);
				me->start_busy(3);	// Start busy
				me->delete_temp("s_DCM_Weak_Point");	// Delete the weak point
				me->delete_temp("n_Defensive_Combat_Mode");	// Off combat mode
				return 1;
			}
		}
	}

	return notify_fail("û�������λ��\n");
}

int help(object me)
{
	write(@TEXT
ָ���ʽ��strike

�����˽����˷���״̬���������strike��ͻ�Ƶ��˵ķ��ء�����strike�Ĳ�λ��
��ǰ�أ����أ����أ��󱳣��ұ����󱳣���ۣ��ұۣ�ͷ�����Ժ�С������С
������С����������������������������ȣ����ȡ����ͻ�Ƴɹ����Է����޷�
�ٽ��з��أ����һ���æ��һ����ͻ��ʧ�ܣ��㽫�����ٽ��з��أ����һ���æ
��һ��

�����������У�defense��searchweakpoint��
TEXT
	);
	return 1;
}
