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
		return notify_fail("你要攻击敌人的哪个部位？\n");
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
	if(objectp(target) && !target->query_temp("n_Defensive_Combat_Mode"))
	{
		return notify_fail(target->query("name")+"不在防守，你不能那样做，请使用特殊攻击。\n");
	}

	for(i=0; i<sizeof(s_Body_Positions); i++)
	{
		if(arg == s_Body_Positions[i] && objectp(target))
		{
			message_vision(HIC+"$N向$n的"+arg+"展开猛烈的攻击。\n"+NOR, me,target);

			// If hits the right position
			if(arg == target->query_temp("s_DCM_Weak_Point"))
			{
				message_vision(HIC+"$N的"+arg+"受到攻击，登时手忙脚乱。\n"+NOR, target);
				target->start_busy(3);	// Start busy
				target->delete_temp("s_DCM_Weak_Point");	// Delete the weak point
				target->delete_temp("n_Defensive_Combat_Mode");	// Off combat mode
				return 1;
			}

			// If hits the fight position
			if(arg != target->query_temp("s_DCM_Weak_Point"))
			{
				message_vision(HIC+"$N的招数毫无破绽，$n一阵急攻过后，不得不停止攻击。\n"+NOR, target, me);
				me->start_busy(3);	// Start busy
				me->delete_temp("s_DCM_Weak_Point");	// Delete the weak point
				me->delete_temp("n_Defensive_Combat_Mode");	// Off combat mode
				return 1;
			}
		}
	}

	return notify_fail("没有这个部位。\n");
}

int help(object me)
{
	write(@TEXT
指令格式：strike

当敌人进入了防守状态，你可以用strike来突破敌人的防守。可以strike的部位有
：前胸，左胸，右胸，后背，右背，左背，左臂，右臂，头部，脑后，小腹，左小
腹，右小腹，丹田，下阴，左腰，右腰，左腿，右腿。如果突破成功，对方将无法
再进行防守，而且还会忙上一阵。如突破失败，你将不能再进行防守，而且还会忙
上一阵。

其他相关命令还有：defense，searchweakpoint。
TEXT
	);
	return 1;
}
