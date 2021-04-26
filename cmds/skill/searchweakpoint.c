// strike.c, by FunBoo@sz

#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_DBASE; 
inherit F_SSERVER;

// Calculate whether search should success or not
#include "/kungfu/skill/perform_success_calculation.h"

void func_Let_Me_Know(object me, object target, int n_Success_Search, string s_Sure_Or_Not);

// A string array which has body positions strings
#include "/include/s_body_positions.h"

int main(object me, string arg)
{
	object Target;
	float f_My_Exp, f_Target_Exp;
	int n_Success_Rate, n_My_Int, n_Search_Time, n_Debug_Number;
	string s_Target_Weak_Point;

	if(me->is_fighting())
	{
		Target = offensive_target(me);
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
	if(objectp(Target) && !Target->query_temp("n_Defensive_Combat_Mode"))
	{
		return notify_fail(Target->query("name")+"���ڷ��أ��㲻������������ʹ�����⹥����\n");
	}

	// Search the weak point
	if(objectp(Target) && Target->query_temp("s_DCM_Weak_Point"))
	{
		if(!me->query_temp("n_Searching_Weak_Point")) // If not start searching
		{
			me->set_temp("n_Searching_Weak_Point", 1);
			f_My_Exp = me->query("combat_exp");
			f_Target_Exp = Target->query("combat_exp");
			n_My_Int = me->query("int");
			n_Search_Time = 33 - n_My_Int;	// Calculate how much time is needed for search

			if(n_Search_Time < 3)
			{
				n_Search_Time = 3;
			}

			// Get the target weak point
			s_Target_Weak_Point = Target->query_temp("s_DCM_Weak_Point");

			// Get auto dianxue success rate: 
			n_Success_Rate = Get_Success_Rate(f_My_Exp, f_Target_Exp, 0.5, 0.1, 0.1);
			
			tell_object(me, HIY+"�㿪ʼŬ����Ѱ��"+Target->query("name")+"�����е�����֮����\n"+NOR);

			// If successed
			if(random(100) < n_Success_Rate)
			{
				if(objectp(me) && objectp(Target))
				{
					if(n_Success_Rate > 95) // If success rate is > 95%, give a SURE weak point
					{
						// Call out function, time depense on Int, 1 is scuess search, 0 is failed search
						call_out("func_Let_Me_Know", n_Search_Time, me, Target, 1, "Sure");
					}
					else // If success rate is < 95%, give a NOT SURE weak point, (50% maybe right weak point)
					{
						call_out("func_Let_Me_Know", n_Search_Time, me, Target, 1, "Not_Sure");
					}
				}
			}
			// If fail
			else
			{
				if(objectp(me) && objectp(Target))
				{
					if(n_Success_Rate < 5) // If success rate is < 5%, tell user do not have weak point
					{
						call_out("func_Let_Me_Know", n_Search_Time, me, Target, 0, "Sure");
					}
					else	// If success rate is > 5%, tell a random weak point
					{
						call_out("func_Let_Me_Know", n_Search_Time, me, Target, 0, "Not_Sure");
					}
				}
			}
			return 1;
		}
		else	// Already in searching
		{
			tell_object(me, HIR+"���Ѿ���Ŭ����Ѱ�Ҷ��ֵ������ˡ�\n"+NOR);
			return 1;
		}
	}

	return notify_fail("ָ�����\n");
}

// Calculate whether search should success or not
#include "/kungfu/skill/perform_success_calculation.c"

void func_Let_Me_Know(object me, object target, int n_Success_Search, string s_Sure_Or_Not)
{
	if(objectp(me) && objectp(target) && me->is_fighting())
	{
		// If success rate is > 95%, give a SURE weak point
		if(n_Success_Search == 1 && s_Sure_Or_Not == "Sure")
		{
			tell_object(me, HIY+target->query("name")+"����������"+target->query_temp("s_DCM_Weak_Point")+"��\n"+NOR);
			me->delete_temp("n_Searching_Weak_Point");
			return;
		}

		// If success rate is < 95%, give a NOT SURE weak point, (50% maybe right weak point)
		if(n_Success_Search == 1 && s_Sure_Or_Not == "Not_Sure")
		{
			if(random(2)>0) // tell right point
			{
				tell_object(me, HIB+target->query("name")+"�������ܿ�������"+target->query_temp("s_DCM_Weak_Point")+"��\n"+NOR);
				me->delete_temp("n_Searching_Weak_Point");
			}
			else // Tell random point
			{
				tell_object(me, HIB+target->query("name")+"�������ܿ�������"+s_Body_Positions[random(sizeof(s_Body_Positions))]+"��\n"+NOR);
				me->delete_temp("n_Searching_Weak_Point");
			}
			return;
		}

		// If success rate is < 5%, tell user do not have weak point
		if(n_Success_Search == 0 && s_Sure_Or_Not == "Sure")
		{
			tell_object(me, HIR+target->query("name")+"����������������Ѱ��\n");
			me->delete_temp("n_Searching_Weak_Point");
			return;
		}

		// If success rate is > 5%, tell a random weak point
		if(n_Success_Search == 0 && s_Sure_Or_Not == "Not_Sure")
		{
			tell_object(me, HIB+target->query("name")+"��������������"+s_Body_Positions[random(sizeof(s_Body_Positions))]+"��\n"+NOR);
			me->delete_temp("n_Searching_Weak_Point");
			return;
		}
	}

	if(objectp(me))
	{
		me->delete_temp("n_Searching_Weak_Point");
	}
	return;
}

int help(object me)
{
	write(@TEXT
ָ���ʽ��searchweakpoint

����Ѱ�ҵ��˵����㡣Ѱ�ҵ�ʱ��������йء�����Խ�ߣ���Ҫ��ʱ��
Խ�١�

���ϵͳ���ֵ��ǡ��ܿ��ܡ��Ļ�������аٷ�֮��ʮ�Ļ������ҵ���
���˵���ȷ���㡣

����ǡ����ܡ��Ļ����ͺ��п����Ǵ�������㣬��Ҫ����Ѱ�ҡ�

�����������У�defense��strike��
TEXT
	);
	return 1;
}