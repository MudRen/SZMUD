// Code of ShenZhou
//yiyang-zhi.c

inherit SKILL;

string *parry_msg = ({
        "$n��$N�Ĺ���������������ָһ�죬����������š�\n",
});
mapping *action = ({
([      "action" :
"$N�������Ʈ�������ƻ��أ�����ʳָ��ǰңңһ�ӣ�����һ�С�³�����ա�",
        "force" : 250,
        "dodge" : 10,
        "parry" : 20, 
        "lvl"   : 0,
	 "weapon": "����ʳָ",
        "skill_name" : "³������",
        "damage_type" : "����"
]),
([      "action" :
"$Nһʽ��������ɫ����ʩʩȻ��ǰ̤�ϰ벽����һ��������Ĵָ������Ϣ�ص���$n��$l",
        "force" : 280,
        "dodge" : 10,
        "parry" : 30,
        "lvl"   : 15,
	"weapon": "����Ĵָ",
        "skill_name" :  "������ѩ", 
        "damage_type" : "����"
]),
([      "action" :
"$N���΢Ц������ʳָ�������ޡ�����ʳָ������������$n��������һʽ��˫�����١��������",
        "force" : 350,
        "dodge" : 5,
        "parry" : 35,
        "lvl"   : 30,
	"weapon": "����ָ��",
        "skill_name" :  "˫������", 
        "damage_type" : "����"
]),
([      "action" :   
"$N���롱�س嵽$n�ĸ�ǰ����������ָһ��һ���������£������˿�������һʽ����������",
        "force" : 390,
        "dodge" : 25,
        "parry" : 5,
        "lvl"   : 35,
	"weapon": "��������ָ",
        "skill_name" :  "��������",
        "damage_type" : "����"
]),
([      "action" : 
"$N���ζ�Ȼ���ϰ���˫�ּ������£�һʽ�����ս������ѽ�$n��ȫ��ҪѨ����ָ��֮��",
        "force" : 450,
        "dodge" : 30,
        "parry" : 10, 
        "lvl"   : 40,   
	"weapon": "ָ��",
        "skill_name" :  "���ս���",
        "damage_type" : "����"
]),
([      "action" :
"$N��������������ס��������ƾ�ճ�ָ�����ꡱ��һ��ָ���ƿյ���$n����һ�С����ﳯ������",
        "force" : 480,
        "dodge" : 30,
        "parry" : 25,
        "lvl" : 60,
	 "weapon": "ָ��",
        "skill_name" : "���ﳯ��",
        "damage_type" : "����"
]),
([      "action" :
"$Nһʽ���Ǽٷǿա���˫�ֵʹ��������У�СĴָ�����$n������ʱ��ͻ���������������ƿն���",
        "force" : 500,
        "dodge" : 30,
        "parry" : 30,
        "lvl" : 72,
        "weapon": "����ָ��",
	"skill_name" : "�Ǽٷǿ�",
        "damage_type" : "����"
]),
([      "action" :
"$N���²�������վ�ã�����ʳָ�������죬ָ�Ͼ������磬��һʽ��������̩��ң��$n��$l",
        "force" : 530,
        "dodge" : 20,
        "parry" : 35,
        "lvl"   : 90,
	"weapon": "����ָ��",
        "skill_name" : "������̩",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="finger" || 
usage=="parry"; }
int valid_combine(string combo) { return combo=="qingyan-zhang" || 
combo=="jinyu-quan"; }

int valid_learn(object me)
{
	if (me->query("gender") == "Ů��" && me->query_str() < 27)
		return notify_fail("�����������������ޣ��޷���ϰһ��ָ��\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��һ��ָ������֡�\n");
	if ((int)me->query_skill("kurong-changong", 1)<80 
		&& (int)me->query_skill("beiming-shengong", 1)<80)
		return notify_fail("��Ŀ���������򲻹����޷�ѧһ��ָ��\n");
	if ((int)me->query("max_neili") < 500)
		return notify_fail("�������̫�����޷���һ��ָ��\n");
	if ((int)me->query_skill("finger", 1) <80)
		return notify_fail("��Ļ���ָ����򲻹����޷�ѧһ��ָ��\n");
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
        level   = (int) me->query_skill("yiyang-zhi",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"]) return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 60)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 50)
		return notify_fail("�������������һ��ָ��\n");
	me->receive_damage("jingli", 25);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yiyang-zhi/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if (random(me->query_skill("yiyang-zhi", 1)) > 100) {
		victim->apply_condition("yyz_damage", random(me->query_skill("yiyang-zhi", 1)/2)
			+ victim->query_condition("yyz_damage"));
		victim->set_temp("yyzenemy", me->query("id"));
	}
}

mapping *query_skilldbase() {return action;}
