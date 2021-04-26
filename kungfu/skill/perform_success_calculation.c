// Function usage:
// 1 arg: the skill level/exp of the performer you want to compare
// 2 arg: the skill level/exp of the target you want to compare
// 3 arg: basic success rate if arg1 == arg2, 50%, put 0.5, 75%, put 0.75
// 4 arg: arg1 >= arg2 or arg1 < arg2, + or - how many percent on success rate, if you want 10%, put 0.1, 20% put 0.2 and so on
// 5 arg: in how many % different in skills level/exp, success rate start to take effect
// if you want 10%, put 0.1, if you want 20%, put 0.2 and so on
// Example:
// Get_Success_Rate(100, 100, 0.75, 0.1, 0.1);
// example above is my skill is 100, target skill is 100, and my perform have 75% to success when we have equal skill level
// if I have 10% skill level higher than target, i get 10% more on perform success rate
// if I have 10% skill level less than target, i get 10% less on perform sucess rate
int Get_Success_Rate(float f_My_Level, float f_Target_Level, float f_Basic_Success_Rate, float f_Add_Success_Rate, float f_Skill_Level_Diff)
{
	float f_Success_Rate, f_Power_Number, f_Jian_Number, f_First_Chu_Number;
	int n_Success_Rate, n_Power_Number;

	// If performer's skill/exp is higher than target
	if(f_My_Level >= f_Target_Level)
	{
		// ����(coolzh)�ش��㣺0.75*(1+0.1*(y-x)/x)
		// ����(coolzh)�ش��㣺and 0.75*(1-0.1*(y-x)/x)

		// 0.75*(1+0.1)^((x-y)/x/0.1)
		// This one is correct: 0.75*(1-0.1)^((y-x)/x) and 0.75*(1+0.1)^((x-y)/y)
		// 0.75(75%) is the basic success rate, 1+0.1(10%) is the add success rate if performer's skill level is high than target
		// If you want 20% success rate added on skill level difference, change to 1+0.2(20%) for example
		// the last magical number 0.1(10%) is referring to the skill different rate, if you want to set
		// 20% skill difference, change this number
		// x = performer's skill level, y = target skill level
		// Note: if target's skill level is higher, change to another formula
		// the follow is use to calculate the auto dianxue success rate:
		// As above, this happen to when performer's skill is higher, so if
		// performer have 1% higher, will give performer around 1% more to success his perform
		// Basic perform success rate is 75% (0.75), this is apply when they have equal skill level
		f_Jian_Number = f_My_Level - f_Target_Level;
		
		f_First_Chu_Number = (to_float(f_Jian_Number)/to_float(f_My_Level));
		
		f_Power_Number = f_First_Chu_Number/f_Skill_Level_Diff;
		n_Power_Number = to_int(f_Power_Number);
		
		f_Success_Rate = f_Basic_Success_Rate * pow((1 + f_Add_Success_Rate), f_Power_Number);
	}

	// If performer's skill/exp is less than target
	if(f_My_Level < f_Target_Level)
	{
		f_Jian_Number = f_Target_Level- f_My_Level;

		f_First_Chu_Number = (to_float(f_Jian_Number)/to_float(f_Target_Level));

		f_Power_Number = f_First_Chu_Number/f_Skill_Level_Diff;
		n_Power_Number = to_int(f_Power_Number);

		f_Success_Rate = f_Basic_Success_Rate * pow((1 - f_Add_Success_Rate), f_Power_Number);
	}

	// * 100 here is because need to compare with 100 (100% success)
	n_Success_Rate = to_int(f_Success_Rate*100);
	
	return n_Success_Rate;
}