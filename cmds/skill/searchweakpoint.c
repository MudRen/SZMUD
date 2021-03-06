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
		return notify_fail("你正在忙，不能这样做。\n");
	}

	if(!me->is_fighting())
	{
		return notify_fail("你不在战斗中，不能这样做。\n");
	}

	// Target is not in defensive combat mode
	if(objectp(Target) && !Target->query_temp("n_Defensive_Combat_Mode"))
	{
		return notify_fail(Target->query("name")+"不在防守，你不能那样做，请使用特殊攻击。\n");
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
			
			tell_object(me, HIY+"你开始努力的寻找"+Target->query("name")+"招数中的破绽之处。\n"+NOR);

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
			tell_object(me, HIR+"你已经在努力的寻找对手的破绽了。\n"+NOR);
			return 1;
		}
	}

	return notify_fail("指令错误。\n");
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
			tell_object(me, HIY+target->query("name")+"的破绽是在"+target->query_temp("s_DCM_Weak_Point")+"！\n"+NOR);
			me->delete_temp("n_Searching_Weak_Point");
			return;
		}

		// If success rate is < 95%, give a NOT SURE weak point, (50% maybe right weak point)
		if(n_Success_Search == 1 && s_Sure_Or_Not == "Not_Sure")
		{
			if(random(2)>0) // tell right point
			{
				tell_object(me, HIB+target->query("name")+"的破绽很可能是在"+target->query_temp("s_DCM_Weak_Point")+"！\n"+NOR);
				me->delete_temp("n_Searching_Weak_Point");
			}
			else // Tell random point
			{
				tell_object(me, HIB+target->query("name")+"的破绽很可能是在"+s_Body_Positions[random(sizeof(s_Body_Positions))]+"！\n"+NOR);
				me->delete_temp("n_Searching_Weak_Point");
			}
			return;
		}

		// If success rate is < 5%, tell user do not have weak point
		if(n_Success_Search == 0 && s_Sure_Or_Not == "Sure")
		{
			tell_object(me, HIR+target->query("name")+"的招数毫无破绽可寻！\n");
			me->delete_temp("n_Searching_Weak_Point");
			return;
		}

		// If success rate is > 5%, tell a random weak point
		if(n_Success_Search == 0 && s_Sure_Or_Not == "Not_Sure")
		{
			tell_object(me, HIB+target->query("name")+"的破绽可能是在"+s_Body_Positions[random(sizeof(s_Body_Positions))]+"！\n"+NOR);
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
指令格式：searchweakpoint

用以寻找敌人的弱点。寻找的时间和悟性有关。悟性越高，所要的时间
越少。

如果系统出现的是“很可能”的话，大概有百分之五十的机会是找到了
敌人的正确弱点。

如果是“可能”的话，就很有可能是错误的弱点，需要继续寻找。

其他相关命令还有：defense，strike。
TEXT
	);
	return 1;
}