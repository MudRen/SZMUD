// defense.c, by FunBoo@sz

#include <ansi.h>
inherit F_CLEAN_UP;

void cost();

// A string array which has body positions strings
#include "/include/s_body_positions.h"

int main(object me, string arg)
{
	if(arg == "off")
	{
		if(!me->query_temp("n_Defensive_Combat_Mode"))
		{
			return notify_fail("你正在进攻状态中。\n");
		}

		me->delete_temp("n_Defensive_Combat_Mode"); // Delete var, means in attack mode
		// Delete a weak point in player
		me->delete_temp("s_DCM_Weak_Point");
		message_vision(HIC+"$N摆出一副进攻的架势。\n"+NOR, me);
		// me->start_busy(1);
		return 1;
	}

	if(me->is_busy())	// If busy
	{
		return notify_fail("你正在忙，不能进入防守状态。\n");
	}

	// If he is doing yun zixia, jingang, taiji, cannot go into defensive mode
	if(me->query_temp("zixia/lvl") || me->query_temp("taiji") || me->query_temp("jingang") || me->query_temp("powerup") || me->query_temp("reverse") || me->query_temp("newhua") || me->query_temp("wuzhuan") || me->query_temp("huaying") || me->query_temp("longxiang") || me->query_temp("linji"))
	{
		return notify_fail("你正在使用某种内功，不能进入防守状态。\n");
	}
	
	if(me->query_temp("n_Defensive_Combat_Mode"))
	{
		return notify_fail("你正在防守状态中。\n");
	}
	
	if(!arg)
	{
		me->set("jiali", 0); // Jiali 0
		me->set("jiajin", 1);	// Jiajin 0
		me->set_temp("n_Defensive_Combat_Mode", 1); // Set var, means in defensive mode
		// Set a weak point in player, if this point got striked, busy and off defensive mode
		me->set_temp("s_DCM_Weak_Point", s_Body_Positions[random(sizeof(s_Body_Positions))]);
		message_vision(HIC+"$N摆出一副全力防守的架势。\n"+NOR, me);
		me->start_busy(3);
		call_out("cost",3);
	}
	
	return 1;
}

void cost()
{
        object obj;
        object me = this_player();
        
        if( !me->query_temp("n_Defensive_Combat_Mode") ) return;

        if(me->query("jingli") < 300)
        {
			message_vision("$N防守了那么久，实在是太累了，只好放弃防守。\n", me);
            me->delete_temp("n_Defensive_Combat_Mode");
			me->delete_temp("s_DCM_Weak_Point");
            return;
        }
        
        me->add("jingli", -me->query("max_jingli")/30);
        call_out("cost",3);
}

int help(object me)
{
	write(@TEXT
指令格式：defense

让你进入防守状态。一旦进入防守状态，你将不能使用任何特殊攻击，不能加力，
不能加精。而敌人却不能向你使用特殊攻击。

指令格式：defense off
让你进入进攻状态。一旦进入进攻状态，你将可以使用特殊攻击，可以加力，可以
加精。而敌人也能向你使用特殊攻击。

如果正在使用某种特殊内功，如：jingang, hua, powerup, reverse, taiji等，将
不能进入防守状态。

其他相关命令还有：strike, searchweakpoint。
TEXT
	);
	return 1;
}
