// Code of ShenZhou
// pudu-zhang.c �ն��ȷ�

inherit SKILL;

mapping *action = ({
([	"action":"$Nʹһ�С���ţת�ǡ�������$w���¶��ϣ������ޱȵ���$n��С����ȥ��",
	"force" : 180,
        "dodge" : -10,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "��ţת��",
	"damage_type":"����"
]),
([	"action":"$N�첽�����һ�С�Ұ��׷�硹������ƽ��$w�����������ȶˣ�����$n���ؿڡ�",
	"force" : 200,
        "dodge" : -10,
	"damage": 20,
	"lvl" : 9,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "Ұ��׷��",
	"damage_type":"����"
]),
([	"action":"$N�߾�$w��һ�С��ͻ���������ȫ��Ծ������$w§ͷ�Ƕ�����$n��ȥ��",
	"force" : 230,
        "dodge" : -5,
	"damage": 30,
	"lvl" : 18,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "�ͻ�����",
	"damage_type":"����"
]),
([	"action":"$Nһ�С�ʨ��ҡͷ����˫�ֳ������֣���׼$n�͵�һ������ͬƽ�ع���һ�����硣",
	"force" : 270,
        "dodge" : -10,
	"damage": 35,
	"lvl" : 27,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "ʨ��ҡͷ",
	"damage_type":"����"
]),
([	"action":"$N���$w��һ�С�������β�����ȶ˻���������ԲȦ�����ͳ��أ���$n�������С�",
	"force" : 320,
        "dodge" : -15,
	"damage": 40,
	"lvl" : 36,
	"skill_name" : "������β",
	"damage_type":"����"
]),
([	"action":"$Nȫ�������$w�̵غ�ɣ�ͻ��һ�С�������������Ӱ��$n��������",
	"force" : 380,
        "dodge" : 5,
	"damage": 55,
	"lvl" : 45,
	"skill_name" : "��������",
	"damage_type":"����"
]),
([	"action":"$N˫�ֺ�ʮ������һ�С���ɮ�в�����$w������ɳ���������$nײȥ��",
	"force" : 450,
        "dodge" : -5,
	"damage": 55,
	"lvl" : 53,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "��ɮ�в�",
	"damage_type":"����"
]),
([	"action":"$Nһ�С��Ⱥ��նɡ���$w�������������Ծ����ֱ��$n���ؿڴ��롣",
	"force" : 530,
        "dodge" : -5,
	"damage": 60,
	"lvl" : 60,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "�Ⱥ��ն�",
	"damage_type":"����"
]),
});

int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("hunyuan-yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ�������̫ǳ��\n");
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
	level   = (int) me->query_skill("pudu-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if (me->query_str() < 20)
                return notify_fail("��ı����������ն��ȷ���\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ����������ն��ȷ���\n");

        if( (int)me->query_skill("luohan-quan", 1) < 30 )
                return notify_fail("����޺�ȭ��Ϊ��������\n");

	me->receive_damage("jingli", 20);
        if(me->query_skill("pudu-zhang", 1) > 100)
        me->receive_damage("jingli", 5);
        if(me->query_skill("pudu-zhang", 1) > 150)
        me->receive_damage("jingli", 5);
	return 1;
}
