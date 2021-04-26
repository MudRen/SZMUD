// Code of ShenZhou
// caoshang-fei.c ���Ϸ� (ΤһЦ's dodge)
// by maco 

#include <combat.h>
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "����$n���ÿ켫����һ�в��˳���û�ܻ��С�$p�ƺ�������ҫ���򣬾���Զ�ߣ�������$N����Ȧ�ӡ�\n",
        "dodge"  : 90,
]),
([      "action" : "$N����������$nȴ��������֮�⣬���Էɲ���������֮�죬ֱ�Ƿ�����˼���ۼ�����׷�ϲ��ϡ�\n",
        "dodge"  : 90,
]),
([      "action" : "$n�������д��ϣ���Ӱһ��һ�������ѱܿ������������������º��С�\n",
        "dodge"  : 90,
]),
([      "action" : "$n����ٿȻ��������������һ�����̣�ת˲������$N���ʮ���ɡ�\n",
        "dodge"  : 90,
]),
([      "action" : "$nб��һ�ã�����һ�������ػ��˿�ȥ����һ�֡����Ϸɡ����Ṧ������죬�����������������Ʈ�У�ʵ������似��\n",
        "dodge"  : 90,
]),
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("caoshang-fei");

	return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
        return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
       return action[random(sizeof(action))]["action"];
}

int practice_skill(object me)
{
        return 0;
}

