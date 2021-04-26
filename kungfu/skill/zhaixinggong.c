// Code of ShenZhou
// zhaixinggong.c based on xiaoyaoyou.c
// by yucao
// modified by wsky.

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$nһ��������ժ�ǡ���Ծ�����ߣ������$N��һ�С�\n",
        "dodge"  : 20,
]),
([      "action" : "$n�������һ�ݣ�ʹ��һ�С�ƮȻ���������ܹ���$N�Ĺ�����\n",
        "dodge"  : 40,
]),
([      "action" : "$nʹ����������ˮ����ǡ�ö����$N�Ĺ��ơ�\n",
        "dodge"  : 60,
]),
([      "action" : "$nһ�С�֯Ů���󡹣���̬����ض��˿�ȥ��\n",
        "dodge"  : 80,
]),
([      "action" : "$n����һ�Σ�һ�С�ѩƮ��ɽ�����������µض㿪��$N�Ĺ�����\n",
        "dodge"  : 90,
]),
([      "action" : "$n����ƮƮ������������ʹ��һ�С���԰������"+NOR"���ɵĶ㿪$N�Ĺ��ơ�\n",
        "dodge"  : 100,
])
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level = (int)me->query_skill("tiyunzong");

        if (level < 60 )
                zhaoshu--;

        if (level < 50 )
                zhaoshu--;

        if (level < 40 )
                zhaoshu--;

        return action[random(zhaoshu)];
}

int valid_enable(string usage) 
{ 
        return (usage == "dodge") || (usage == "move"); 
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return action[random(sizeof(action))]["action"];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 40 )
                return notify_fail("��ľ���̫���ˣ�������ժ�ǹ���\n");
        if (me->query_skill("zhaixinggong", 1) < 30)
                me->receive_damage("jingli", 10);
        else    me->receive_damage("jingli", 20);
        return 1;
}
string perform_action_file(string action)
{    
	return __DIR__"zhaixinggong/" + action;
}
