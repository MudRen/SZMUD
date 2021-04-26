// Code of ShenZhou
//zhemei-shou.c ��ɽ��÷��
//Xuanyuan

inherit SKILL;

mapping *action = ({
([      "action" : 
"$N���һ����ʹ��һ·Ѹ�͵��Ʒ���˫�����·��ɡ��󿪴��أ���������$n",
        "force" : 320,
        "parry" : 30,
        "dodge" : 30,
        "lvl"   : 10,
        "damage_type" : "����"
]),
([      "action" :
"$N����أ�������ߣ�����Ʈ�����������²�����ͻȻ�����$n��$l����һ·����������Ʒ�",
        "force" : 260,
		"parry" : 30,
		"dodge" : 50,
        "lvl"   : 0,
        "damage_type" : "����"
]),
([      "action" :
"$N��Ȼ��Ϊһ·�����Ʒ���˫��̤ʵ�����������������������ᣬ���Ტ�ã��߶�ǿ�������ͻ�$n��$l",
        "force" : 530,
        "parry" : 30,
		"dodge" : 5,
        "lvl"   : 80,
        "damage_type" : "����"
]),
([      "action" :
"$N˫�ֺ���ץ��������������ȭ�������ƣ������任����С�����ַ�����$n��$lץȥ",
        "force" : 350,
        "dodge" : 45,
        "parry" : 5,
        "lvl"   : 30,
        "damage_type" : "ץ��"
]),
([      "action" :   
"$Nʹ��һ·���������ַ���˫��ʱ����צ��ʱ����צ������������$n��$l��ȥ",
        "force" : 380,
        "dodge" : 5,
        "parry" : 35,
        "lvl"   : 35,
        "damage_type" : "ץ��"
]),
([      "action" : 
"$N˫��ʹӥצ�֣����˵��ݣ��ϴ���������$n�����󡢽��󡢲��ӣ�������צ����",
        "force" : 400,
        "dodge" : 30,
        "parry" : 10,
        "lvl"   : 40,
        "damage_type" : "ץ��"
]),
([      "action" :
"$Nȭ��һ�䣬˫�۾���û�˹�ͷһ���������ۣ�ʹ��һ·�޷���$n�������ҳ��",
        "force" : 450,
        "dodge" : 30,
        "parry" : 25,
        "lvl"   : 50,
        "damage_type" : "����"
]),
([      "action" :
"$N��ָ��£������Ϊ����ǿ������������Ե��һ��ֱ��$n��$l����õ�����Ҫ",
        "force" : 500,
        "dodge" : 30,
        "parry" : 30,
        "lvl"   : 72,
        "damage_type" : "����"
]),
([      "action" :
"$N����Գ�ۣ�˫ָ��£���������֮ң��������$n����ֱ�̣�ʹ�ľ�Ȼ�ǳ�ǹǹ��",
        "force" : 480,
        "dodge" : 40,
        "parry" : 10,
        "lvl"   : 90,
        "damage_type" : "����"
]),
([      "action" :
"$N�������������൤����Ƹ߾٣���ָ�ؿۣ�����һ���󸫣���$n��ͷ����",
        "force" : 550,
        "dodge" : 0,
        "parry" : 10,
        "lvl"   : 90,
        "damage_type" : "����"
]),
([      "action" :
"$N����һ����Ц��˫�۱�����������ָ��ʹ��һ·�����е�ץ������$n������ץ��������",
        "force" : 520,
        "dodge" : 30,
        "parry" : 50,
        "lvl"   : 100,
        "damage_type" : "ץ��"
]),
([      "action" :
"$Nһ����Х����ָΪ����ʹ��һ�־���Ľ������У���$n�����������̴���",
        "force" : 580,
        "dodge" : 30,
        "parry" : 30,
        "lvl"   : 100,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_combine(string combo) { return combo=="liuyang-zhang"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("xiaowu-xiang", 1)<50
		&& (int)me->query_skill("bahuang-gong", 1)<50
		&& (int)me->query_skill("beiming-shengong", 1)<50)
		return notify_fail("�����ң���ڹ���򲻹����޷�ѧϰ��ɽ��÷�֡�\n");
	if ((int)me->query("max_neili") < 500)
		return notify_fail("�������̫�����޷�ѧϰ��ɽ��÷�֡�\n");
	if ((int)me->query_skill("hand", 1) <80)
		return notify_fail("��Ļ����ַ���򲻹����޷�ѧϰ��ɽ��÷�֡�\n");
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
        level   = (int) me->query_skill("zhemei-shou",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]) return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if (me->query_temp("weapon"))
		return notify_fail("����ɽ��÷�ֱ�����֡�\n");
	if ((int)me->query("jingli") < 50)
                return notify_fail("��ľ�����������ɽ��÷�֡�\n");
        me->receive_damage("jingli", 30, "����͸֧�������ˡ�");
	return 1;
}

string perform_action_file(string action)
{
       return __DIR__"zhemei-shou/" + action;
}
