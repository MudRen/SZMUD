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
			return notify_fail("�����ڽ���״̬�С�\n");
		}

		me->delete_temp("n_Defensive_Combat_Mode"); // Delete var, means in attack mode
		// Delete a weak point in player
		me->delete_temp("s_DCM_Weak_Point");
		message_vision(HIC+"$N�ڳ�һ�������ļ��ơ�\n"+NOR, me);
		// me->start_busy(1);
		return 1;
	}

	if(me->is_busy())	// If busy
	{
		return notify_fail("������æ�����ܽ������״̬��\n");
	}

	// If he is doing yun zixia, jingang, taiji, cannot go into defensive mode
	if(me->query_temp("zixia/lvl") || me->query_temp("taiji") || me->query_temp("jingang") || me->query_temp("powerup") || me->query_temp("reverse") || me->query_temp("newhua") || me->query_temp("wuzhuan") || me->query_temp("huaying") || me->query_temp("longxiang") || me->query_temp("linji"))
	{
		return notify_fail("������ʹ��ĳ���ڹ������ܽ������״̬��\n");
	}
	
	if(me->query_temp("n_Defensive_Combat_Mode"))
	{
		return notify_fail("�����ڷ���״̬�С�\n");
	}
	
	if(!arg)
	{
		me->set("jiali", 0); // Jiali 0
		me->set("jiajin", 1);	// Jiajin 0
		me->set_temp("n_Defensive_Combat_Mode", 1); // Set var, means in defensive mode
		// Set a weak point in player, if this point got striked, busy and off defensive mode
		me->set_temp("s_DCM_Weak_Point", s_Body_Positions[random(sizeof(s_Body_Positions))]);
		message_vision(HIC+"$N�ڳ�һ��ȫ�����صļ��ơ�\n"+NOR, me);
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
			message_vision("$N��������ô�ã�ʵ����̫���ˣ�ֻ�÷������ء�\n", me);
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
ָ���ʽ��defense

����������״̬��һ���������״̬���㽫����ʹ���κ����⹥�������ܼ�����
���ܼӾ���������ȴ��������ʹ�����⹥����

ָ���ʽ��defense off
����������״̬��һ���������״̬���㽫����ʹ�����⹥�������Լ���������
�Ӿ���������Ҳ������ʹ�����⹥����

�������ʹ��ĳ�������ڹ����磺jingang, hua, powerup, reverse, taiji�ȣ���
���ܽ������״̬��

�����������У�strike, searchweakpoint��
TEXT
	);
	return 1;
}
