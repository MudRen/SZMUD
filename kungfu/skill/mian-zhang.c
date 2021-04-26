 // Code of ShenZhou
// mian-zhang.c ����
// xQin 12/98
// xQin 11/00

#include <combat.h>
inherit SKILL;


nomask int parry_available() { return 1; }

string *parry_msg = ({
        "$p����չ�����ƣ���Ԫ��һ��ȫ��Ҫ���صú���©����\n",
        "$p�������ã���$w���������磬ͻȻ���У�����ֱ��$P�������š�\n",
        "$p˫��һ������Ż���������ȥ$P�����ƽ������Ȳ����ˡ�\n",
        "$p������죬���ȡ����ƶϷ塹���ӵ�ɨȥ��\n",
        "$pһ�����˿�һ�������ơ����Ƽ��ա��������ӳ���\n",
        "$p���̡��̹���񡹣�˫�������÷�����$P���š�\n",
        "$p����ԧ���ȡ���$P��в��ʹ$N���ò��������С�\n",
        "$p�ˡ��ϡ�λ���������������㡰��Ȫ����\n",
        "$p�ˡ����ڡ����Է����ֻ�����\n",
        "$p�ˡ���λ�����ˡ�����λ�����ˡ�δ�á���\n",
        "$p��������һ����ʹ���С���ת���ɡ���ת�˸�Ȧ�ӣ���ʱ��$P$w˦�䡣\n",
        "$p�����������������˹�������$P$w����������������ƣ���ʦ���Ĵ��ġ����ơ�������\n",
        "$p�����������һ�С���ܽ�������ס��\n",
});

string query_parry_msg(object weapon, object victim) 
{ 
        if( victim->query_temp("weapon") || victim->query_skill("mian-zhang", 1) < 100
                || victim->query_skill_prepared("strike") != "mian-zhang" )
                return SKILL_D("parry")->query_parry_msg(weapon);
        else
                return parry_msg[random(sizeof(parry_msg))];
}

mapping *action = ({
([      "action": "����$N����һ�䣬˫�Ʒ��裬��������Ʈѩ��������಻������",
        "force" : 160,
        "dodge" : 10,
        "damage": 5,
        "lvl" : 0,
        "skill_name" : "��Ʈѩ��",
        "damage_type": "����"
]),
([      "action": "$N���������ұۣ�ʹһ�С����ڷɻ���������������$n$l��ȥ",
        "force" : 200,
        "dodge" : 15,
        "damage": 10,
        "lvl" : 13,
        "skill_name" : "���ڷɻ�",
        "damage_type": "����"
]),
([      "action": "$Nһ�С��ɺ����᡹��ٿ��б���������������ƣ���$n$l��",
        "force" : 260,
        "dodge" : 20,
        "damage": 15,
        "lvl" : 26,
        "skill_name" : "�ɺ�����",
        "damage_type": "����"
]),
([      "action": "$N���ַ���һ�С��ɽ�ն������$n�����ֱ����䣬�����ͻ�$p$l",
        "force" : 320,
        "dodge" : 0,
        "damage": 25,
        "lvl" : 39,
        "skill_name" : "�ɽ�ն��",
        "damage_type": "����"
]),
([      "action": "$N�������ƣ�һ�С��������¡������󷭹�������ת�˸�СȦ����$n$l��ȥ",
        "force" : 245,
        "dodge" : 5,
        "damage": 35,
        "lvl" : 52,
        "skill_name" : "��������",
        "damage_type": "����"
]),
([      "action": "$NͻȻ�ؿ�һ����˫�ۻػ���һ�С����Ƴ�ᶡ�������ʳָ������ʳָͬʱ����$n$l",
        "force" : 400,
        "dodge" : 25,
        "damage": 30,
        "lvl" : 65,
        "skill_name" : "���Ƴ��",
        "damage_type": "����",
]),
([      "action": "$N����¶�Ὥ�������ĳ������ƶ��������������������б�����ִӺ�����������",
        "force" : 450,
        "dodge" : 30,
        "damage": 40,
        "lvl" : 78,
        "skill_name" : "��¶�Ὥ",
        "damage_type": "����"
]),
([      "action": "$N�������䣬˫����ƮƮ�أ��������޵��Ļ�������ʹ�С����׷���������������������ٿ������$n$l����",
        "force" : 370,
        "dodge" : 35,
        "damage": 20,
        "lvl" : 91,
        "skill_name" : "���׷���",
        "damage_type": "����"
])
});

int valid_enable(string usage)
{
        return usage=="strike" ||  usage=="parry";
}

int valid_combine(string combo)
{
        if (this_player()->query_skill("taiji-shengong", 1) > 99)
        return combo=="taiji-quan";
        
}

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("��ϰ���Ʊ�����֡�\n");

        if( (int)me->query_skill("force", 1) < 19)
                return notify_fail("����ڹ���Ϊ��ǳ������ѧϰ���ơ�\n");

        if( (int)me->query("max_neili") < 100 )
                return notify_fail("�������̫�����޷���ϰ���ơ�\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for( i = sizeof(action)-1; i >= 0; i-- )
                if( level >= action[i]["lvl"] )
                        return action[i]["skill_name"];
}



int practice_skill(object me)
{

        if ((int)me->query_skill("taiji-shengong", 1) < 19)
                return notify_fail("���̫���񹦻�򲻹����޷�ѧ���ơ�\n");

        if( (int)me->query("jingli") < 30 )
                return notify_fail("����������������ơ�\n");

        if( (int)me->query("neili") < 20 )
                return notify_fail("����������������ơ�\n");

        me->receive_damage("jingli", 25, "����͸֧��������");
        me->add("neili", -10);
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;

        if( me->query_temp("double_huakai") )
                return ([
                        "action": "$N˫�ֵ���֮�󣬸������ƻ�$p��գ�����ʳָ��$p�Ҽ��ȱ��Ѩ��",
                        "force" : 500,
                        "dodge" : 15,
                        "damage": 45,
                        "damage_type" : random(2)?"����":"����"
                        ]);

        level = (int)me->query_skill("mian-zhang", 1);
        for( i = sizeof(action); i > 0; i-- )
                if( level > action[i-1]["lvl"] )
                        return action[NewRandom(i, 20, level/5)];
        me->delete_temp("double_huakai");
}
        
string perform_action_file(string action)
{
        return __DIR__"mian-zhang/" + action;
}

