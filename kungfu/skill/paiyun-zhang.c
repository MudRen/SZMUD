// Code Of ShenZhou
// Yo
// ������ Paiyun-zhang
// Keny's Skills

#include <ansi.h>
#include <combat.h>
inherit SKILL;

string *dodge_msg = ({
"$n����Ť����������Ӱ����������$N����һ����\n",
"$n�ֱۻ�ת��ʩ��һʽ��������Ӱ����˳������һ�ԡ�\n",
"$n����Ť����һ�С�������Ӱ����������$N�Ĺ���Ҳ�ܹ��ˣ�����һ�Ӱ�Ӷ㴩��$N����һ����\n",
"$n����Ӱһ�㣬��Ť��������һʽ��������Ӱ�����ܹ���$N������������ \n",
"$n����Ʈ����������Ӱһʽ��������Ӱ����ת�˼�ת�������$N��һ�С�\n",
"$n���ƣ�����Ӱ�㣬ʩ����������Ӱ�������$N�Ĺ�����\n",
});

string *parry_msg = ({
        "$p����Ť����һ��"+HIC"��������Ӱ��"+NOR"��������$n�Ĺ���Ҳ�ܹ��ˣ�����һ�Ӱ�Ӷ㴩��$N����һ����\n",
        "$p�����Ӱ����Ť��������һʽ"+HIC"��������Ӱ��"+NOR"���ܹ���$N������������ \n",
"$p��ǰ���������һ��"+RED"�����ƾ���"+NOR"��ǰ��ȥ����һ�ƺñ�ǧǧ����Ŀ���һӿ���ϣ���$n��ȥ�����ú�$N�Ĺ���˫����ƽ�� \n",
});

string  *msg = ({
"$N�����ƾ�����ƥ���޵С���ֹ���������ƣ����ƻ���$n��Ҫ����",
"$N����һ�䣬����Ӱ��ת��$n��ǰ����಻��һ�ߣ�˫���Ѿ���$n��$l",
"������Ӱ������$N˫�ƻ���$n��$l�������������ܲ��ɱ�",
"$N��Ծ��գ�ӳ�����£��Ƽ������ھ����صĻ���$n��$n�����˴��Ʊؿ��к�",
});

mapping *action = ({
([      "action": "$Nʹ������ˮ���ơ���������ˮ��һ����һ���ǳɣ�ÿһ��Ҳ���ӵ������޷�ı���$n��$nҲ�����м�",
        "dodge": 20,
        "parry": 50,
        "force": 480,
        "damage": 100,
        "lvl": 0,
        "skill_name": "��ˮ����",
        "damage_type": "����",
]),
([      "action": "$N��Ծ��գ�ӳ�����£���ؼ�һʽ�����ƴ��¡����Ƽ������ھ����صĻ���$n��$n�����˴��Ʊؿ��к�",
        "dodge": 15,
        "parry": 25,
        "force": 400,
        "damage": 130,
        "lvl": 10,
        "skill_name": "���ƴ���",
        "damage_type": "����"
]),
([      "action": "$N�����˹���˫�ƺ��ѣ���ʹ�����Ƹ��꡹��˫��ͻȻ�û������ƻ���$n���ñ�������ϸ��$nѶ�����Ե���",
        "dodge": 20,
        "parry": 20,
        "force": 330,
        "damage": 135,
        "lvl": 15,
        "skill_name": "���Ƹ���",
        "damage_type": "����"		
]),
([      "action": "$N��Ծ�ڿա����������������������еġ���ɽ���������Ʒ���緭���ƣ��������ߴ���$n��$n�������˸���",
        "dodge": 15,
        "parry": 25,
        "force": 600,
        "damage": 110,
        "lvl": 20,
        "skill_name": "��ɽ����",
        "damage_type": "����"
]),
([      "action": "$N��ʹһ�С����Ʊ��ա�.��ʽ�ճ�,����������������������һƬ���ƣ�$N�Ծ����ٶ�����$n��ǰ�����صĻ��������ƣ�ʹ$n���һ��",
        "dodge": 15,
        "parry": 25,
        "force": 450,
        "damage": 160,
        "lvl": 25,
        "skill_name": "���Ʊ���",
        "damage_type": random(2)?"����":"����"
]),
([      "action": "$Nһʽ����������������������˫�ƣ����������ѽ�$n�Ĺ�����Ϊ�㣬Ѷ�����������ġ����ƻ���$n$l",
        "dodge": 20,
        "parry": 20,
        "force": 380,
        "damage": 145,
        "lvl": 30,
        "skill_name": "��������",
        "damage_type": "����",
]),
([      "action": "$Nפ����������Ŵ�ǰ��˫�������ǰ��һʽ��˺�����ơ���������˫���йɶ���װ������$N�������ĺ��˫��������֮������$n",
        "dodge": 15,
        "parry": 25,
        "force": 400,
        "damage": 150,
        "lvl": 35,
        "skill_name": "˺������",
        "damage_type": "����"
]),
([      "action": "$Nһ�С��ƺ����Ρ������ƺ��纣���޳���һʱ�ߣ�һʱ�ף�һ����һ���Ҳ��ϵĻ���$n$l��$n���Էֱ�����мܺ�",
        "dodge": 25,
        "parry": 15,
        "force": 420,
        "damage": 155,
        "lvl": 40,
        "skill_name": "�ƺ�����",
        "damage_type": "����"
]),
([      "action": "$N���������������������𣬻𵽺�ʱ����һʽ�������޶�����$N��ǧ�������صĻ���$n$l����������ͻᱻ����",
        "dodge": 30,
        "parry": 10,
        "force": 450,
        "damage": 160,
        "lvl": 45,
        "skill_name": "�����޶�",
        "damage_type": "����"
]),
([      "action": "$Nգһ���۾Ͳ������ˣ�$nͻȻ�䷢��$N��ͷ�����֣�����һʽ�������콵��������ѹ�£���ʱ�޷����",
        "dodge": 20,
        "parry": 20,
        "force": 470,
        "damage": 160,
        "lvl": 50,
        "skill_name": "�����콵",
        "damage_type": "����"
]),
([ "action":"$N�˹��ɶ����������һ����ϼ���ԴԵİ�Χ��$n��$nͻ��е�ȫ��Ӳ�ƻ��У�ԭ��$N��ʹ�����������е����С������ɾ���",
        "dodge": 30,
        "parry": 10,
        "force": 500,
        "damage": 170,
        "lvl": 55,
        "skill_name": "�����ɾ�",
        "damage_type": "����"
]),
([      "action": "$N��һ�С����Ʋҵ�������˫�Ʋ��ϻ������γ���һ���޴���������$n���������ñ�һ��������$n��",
        "dodge": 15,
        "parry": 25,
        "force": 520,
        "damage": 175,
        "lvl": 60,
        "skill_name": "���Ʋҵ�",
        "damage_type": "����",
])
});

int valid_enable(string usage) 
{ 
    return usage == "strike" || usage == "dodge" || usage == "parry"; 
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
        int i, level, neili, force,damage;


        level   = (int) me->query_skill("paiyun-zhang",1);
        force = me->query_skill("force");
                damage= (random(force)+force)/2;
                if(damage>300) damage=300;

        neili = me->query("neili");
        if (level > 120 && force > 180 && neili > 500 
            && me->query("max_neili") > 1200
            && (random(me->query_int()) > 25
                        || random(me->query_dex()) > 27)){
            return([      
                   "action": msg[random(sizeof(msg))],                   
                   "force" : 150+random(neili/100),
                   "dodge" : 40+random(neili/100),
                   "damage": damage,
                   "damage_type" : "����",
                   ]);
            }
           for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string query_parry_msg(object weapon, object victim) 
{ 
        if ( victim->query_temp("weapon") || victim->query_skill("paiyun-zhang", 1) < 100
        || victim->query_skill_prepared("strike") != "paiyun-zhang" )
                return SKILL_D("parry")->query_parry_msg(weapon);
        else
                return parry_msg[random(sizeof(parry_msg))];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}


int practice_skill(object me)
{
        if ((int)me->query("jingli") < 50)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 10)
                return notify_fail("������������������ơ�\n");
        me->receive_damage("jingli", 60);
        me->add("neili", -40);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"paiyun-zhang/" + action;
}
