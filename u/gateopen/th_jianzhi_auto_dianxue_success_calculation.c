// header file, look at perform_success_calculation.c file
#include "/kungfu/skill/perform_success_calculation.h"

// Use to determind auto dianxue success or not, if no xiao, no auto dianxue
// s_Attack_Type mean it is a finger attack or sword attack, since return message is not the same
void Auto_Dianxue_Success_Or_Not(object me, string s_Attack_Type)
{
	int n_Success_Rate;
	float f_My_Yxj_Level, f_My_Tzst_Level, f_Target_Dodge_Level;
	object victim;
	object o_Weapon = me->query_temp("weapon");
	string s_Xue;

	s_Xue = xuedao[random(sizeof(xuedao))];

	// Get victim object
	if(!victim && objectp(me) && me->is_fighting())
	{
		victim = offensive_target(me);
	}

	// If user with xiao & victim is not busy, can do auto dianxue
	if(objectp(me) && me->query_temp("n_th_Jianzhi_Auto_Dian_Xue") && !victim->is_busy())
	{
		f_My_Yxj_Level = me->query_skill("yuxiao-jian");
		f_My_Tzst_Level = me->query_skill("tanzhi-shentong");
		f_Target_Dodge_Level = victim->query_skill("dodge");

		// Get auto dianxue success rate:
		n_Success_Rate = Get_Success_Rate(f_My_Yxj_Level, f_Target_Dodge_Level, 0.75, 0.1, 0.1);
		
		// His perform successed
		if(random(100) < n_Success_Rate)
		{
			// If performer's use sword to attack
			if(s_Attack_Type=="sword")
			{
				me->add("neili", -20);
				message_vision("“嗒”地一声，$N的"+s_Xue+"已被$n手中的"+o_Weapon->name()+"点中。\n", victim, me);
				victim->start_busy(1);
			}

			// If performer's use finger to attack
			if(s_Attack_Type=="finger")
			{
				me->add("neili", -20);
				message_vision("$N的"+s_Xue+"被这一下指劲弹中，霎时酸麻不已。\n", victim);
				victim->start_busy(1);
			}
			return;
		}
		// If fail, nothing happen, return;
		return;
	}
	return;
}

#include "/kungfu/skill/perform_success_calculation.c"