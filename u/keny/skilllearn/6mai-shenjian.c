// Code of ShenZhou
// liumai-shenjian.c ������  changed by macmac

inherit SKILL;
mapping *action = ({
([      "action" : "$N����Сָ�����ʹһ�С����󽣡������ν���������ȥ���仯��΢�������������ҵ���$nб��",
        "force" : 300,
        "dodge" : 15,
        "damage": 350,
        "lvl" : 22,
        "skill_name" : "����",
	"weapon": "���ν���",
        "damage_type" : "����"
]),
([      "action" : "$N����Сָһ�㣬���ǡ��ٳ彣����һ���������ٳ�Ѩ�м����������׾�ݻ�����������ʵ��׽��",
        "force" : 330,
        "dodge" : 20,
        "damage": 400,
        "lvl" : 36,
        "skill_name" : "�ٳ彣",
	"weapon": "���ν���",
        "damage_type" : "����"
]),
([      "action" :"$N�������������س彣��ʹ��������׾�͹��ӣ�����ָ�㴦���������죬������ӿ����",
        "force" : 360,
        "dodge" : 25,
        "damage": 450,
        "lvl" : 52,
        "skill_name" : "�س彣",
	"weapon": "���ν���",
        "damage_type" : "����"
]),
([      "action" : "$N��ָ�ᵯ��ʹ���ˡ��г彣�����󿪴��أ�����������һ·����ʹ���ṹ�Ͻ���ȫ������",
        "force" : 400,
        "dodge" : 30,
        "damage": 500,
        "lvl" : 70,
        "skill_name" : "�г彣",
	"weapon": "���ν���",
        "damage_type" : "����"
]),
([      "action" : "$Nʳָ���������ˡ���������������Ѹ�٣�ʳָ������һ����һ���Ĵ̳���������ã�����׽��",
        "force" : 450,
        "dodge" : 35,
        "damage": 550,
        "lvl" : 90,
        "skill_name" : "������",
	"weapon": "���ν���",
        "damage_type" : "����"
]),
([      "action" : "$N��Ĵָ������ʹ�������̽����������󿪴��أ����ɺ�ΰ��������һ����īɽˮ���ƣ��ݺ���б���������ʣ�ȴ�ǽ�·�۾���ÿһ���̳�������ʯ���쾪���������֮��",
        "force" : 600,
        "dodge" : 50,
        "damage": 600,
        "lvl" : 130,
        "skill_name" : "���̽�",
	"weapon": "���ν���",
        "damage_type" : "����"
])
});
 int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�������񽣱�����֡�\n");
        if ((int)me->query_skill("force", 1) < 180)
                return notify_fail("���������Ϊ���������\n");
        if ((int)me->query("max_neili") < 2000)
                return notify_fail("����δ�޾۵����ǿ������������\n");
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
        level   = (int) me->query_skill("6mai-shenjian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}


int practice_skill(object me)
{
        if ((int)me->query("qi") < 30)
                return notify_fail("�������̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("������������������񽣡�\n");
        me->receive_damage("qi", 30);
        me->add("neili", -10);
        return 1;
} 
string perform_action_file(string action)
{
        return __DIR__"liumai-shenjian/" + action;
}

