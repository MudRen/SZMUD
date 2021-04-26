// Code of ShenZhou
// tie-zhang ����
// maco

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : "$N���һ����˫�����縫���һ������$n��ȥ�������������������Ǹ��;���",
        "force" : 180,
        "dodge" : 20,
        "parry" : 10,
        "damage" : 30,
        "damage_type" : "����",
        "lvl" : 0,
]),
([      "action" : "$N�ؿ��Ż��󿪣�˫�۳������⣬��Ȼ��˫�Ʒ�����������������һ�ɺ���������ֱ��$n$l",
        "force" : 240,
        "dodge" : 10,
        "parry" : 10,
        "damage" : 35,
        "damage_type" : "����",
        "lvl" : 10,
]),
([      "action" : "$N������ǰƽ�����Σ�˫�ƺ��ģ��һ�죬��Ȼ��������������һ�ϣ����ݵ�$n��ǰ��˫������$n�ؿ��Ƴ�",
        "force" : 360,
        "dodge" : 20,
        "parry" : 10,
        "damage" : 40,
        "damage_type" : "����",
        "lvl" : 20,
]),
([      "action" : "$N˫�����ģ������죬�������Ǵ̶���ͻȻ�����һ����������$n������������죬$n�Ų�δ�ƣ����������Ѳ������", 
        "force" : 390,
        "dodge" : 30,
        "damage" : 50,
        "parry" : 10,
        "weapon": "�Ʒ�",
        "damage_type" : "����",
        "lvl" : 30,
]),
([      "action" : "$N�˾��ڱۣ�����������Ʒ��ɣ������ĳ������ֳ�ץ��ͬʱϮ�������ɾ�����ɽ��������$nѹ�˹���",
        "force" : 410,
        "parry" : 10,
        "dodge" : 10,
        "damage" : 50,
        "damage_type" : "����",
        "lvl" : 40,
]),
([      "action" : "$N������ƮƮ��$n���ذ���������ʵ�գ������ƣ����Ʋ�����������ǰ��֮����$n��������������Ѹ�� �������֮",
        "force" : 420,
        "dodge" : 10,
        "parry" : 30,
        "damage" : 40,
        "damage_type" : "����",
        "lvl" : 50,
]),
([      "action" : "$N����$n��������һȦ��ٿ��һ��������������ĳ���������Ϊ���͵ġ��������֡�",
        "force" : 450,
        "dodge" : 25,
        "parry" : 20,
        "damage" : 30,
        "damage_type" : "����",
        "lvl" : 60,
]),
([      "action" : "$N����������ͻȻ����΢�࣬ʹ��һ�С�������һ����������������һ�ģ�����˳��б�ɻ���$n$l���Ƶ��Ͷ��ޱ�",
        "force" : 520,
        "dodge" : 10,
        "parry" : 30,
        "damage" : 40,
        "damage_type" : "����",
        "lvl" : 75,
]),
});
int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") )
                return notify_fail("�����Ʊ�����֡�\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷������ƹ���\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level = (int)me->query_skill("tie-zhang", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("����������������ơ�\n");
        me->receive_damage("jingli", 25);
        me->add("neili", -5);
        return 1;
}

string perform_action_file(string action)
{
                return __DIR__"tie-zhang/" + action;
}
