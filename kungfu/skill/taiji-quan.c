// Code of ShenZhou
// taiji-quan.c ̫��ȭ
// fang 6/26/96
// Ryu 12/12/97
// by aln 4/98
// xQin 6/2000

inherit SKILL;

nomask int parry_available() { return 1; }

string *parry_msg = ({
	"$p�ۼ�$P$w����������ʹ��һ�С���ȸβ�����ҽ�ʵ������飬���𡰼����־���ճ��ճ�棬�����Ѵ�ס$P���󣬺ᾢ������$N����������ǰһ�壬�����������ʼվ����\n",
	"����$p˫��һȦ���籧̫����һ���ۻ��ޱȵ����������һ�����У�ֻ����$P��ԭ�ؼ�ת�߰��¡�\n",
	"$p��˫����������������˫�ֳ�Բ�λ������漴��Ȧ��Ȧ��һ��ԲȦ����һ��ԲȦ����Ȧ��СȦ��ƽȦ����Ȧ����Ȧ��бȦ��һ����̫��ԲȦ��������ʱ���׵�$P����ײײ�������������㲻�ȡ�\n",
	"$pʹ��һ�С����֡������ָߣ����ֵͣ�һ��ԲȦ�ѽ�$P$w��ס��\n",
	"$p����Ϣ΢�ϣ�����һ�С�б���ơ�����$P$w��ƫ��\n",
	"$p��һ����������������ת�����ƻӳ���һ��һӭ����$P�������������˻�ȥ��\n",
	"$p˫��һ����ʹ��һ�С����֡���˫���ᵽ�˼������������飬��$P$w�ļ���������ȥ��\n",
	"$p����˫��һ�ӭ��$w��ȥ������������$P$w����δ��֮�ʣ�ʩ������ȸβʽ������$w����£ס�����¡��𼦶���ʽ��������صأ��������գ�ȫ��ת������һö���ݡ�\n",
	"��������ʯ���һ˲֮�䣬$p����һ�������ǡ��׺����᡹��ǰ���У�$P�ľ�����ʱ��ա�\n",
});

string query_parry_msg(object weapon, object victim) 
{
	if ( victim->query_temp("weapon") || victim->query_skill("taiji-quan", 1) < 100
	|| victim->query_skill_prepared("cuff") != "taiji-quan" )
		return SKILL_D("parry")->query_parry_msg(weapon);
	else
		return parry_msg[random(sizeof(parry_msg))];
}

mapping *action = ({
([	"action" : "$Nʹһ�С���ȸβ����˫�ֻ��˸���Ȧ������$n��$l",
	"force" : 120,
	"dodge" : 30,
	"lvl" : 0,
	"skill_name" : "��ȸβ",
	"damage_type" : "����"
]),
([	"action" : "$N��������������һ�С����ޡ�����$n��ͷ��",
	"force" : 140,
	"dodge" : 25,
	"lvl" : 5,
	"skill_name" : "����",
	"damage_type" : "����"
]),
([	"action" : "$N˫�ֺ���ץס$n���ֱۣ�ʹһ�С�������ʽ���������׳�",
	"force" : 160,
	"dodge" : 20,
	"lvl" : 10,
	"skill_name" : "������ʽ",
	"damage_type" : "����"
]),
([	"action" : "$N�������ݵ�ʹһ�С��׺����᡹�������°�������������$n��$l��ȥ",
	"force" : 220,
	"dodge" : 15,
	"lvl" : 15,
	"skill_name" : "�׺�����",
	"damage_type" : "����"
]),
([	"action" : "$Nһ��������ǰ��ʹһ�С�§ϥ�ֲ���������§ס$n�����ֻ���$n��$l",
	"force" : 270,
	"dodge" : 10,
	"lvl" : 20,
	"skill_name" : "§ϥ�ֲ�",
	"damage_type" : "����"
]),
([	"action" : "$N˫�����»Ӷ���һ�С��ֻ����á����ͻ�$n��$l",
	"force" : 280,
	"dodge" : 30,
	"lvl" : 25,
	"skill_name" : "�ֻ�����",
	"damage_type" : "����"
]),
([	"action" : "$N���ֻ���������ͻȻ�������»�����һ�ǡ���׿������ͻ�$n��$l",
	"force" : 300,
	"dodge" : 25,
	"lvl" : 30,
	"skill_name" : "��׿���",
	"damage_type" : "����"
]),
([	"action" : "$N����ץס$n������һ�С������롹�������ʹ�$n���ɲ�",
	"force" : 320,
	"dodge" : 20,
	"lvl" : 35,
	"skill_name" : "������",
	"damage_type" : "ץ��"
]),
([	"action" : "$Nһ������ͨ������һ�������������$n���ز�",
	"force" : 330,
	"dodge" : 15,
	"lvl" : 40,
	"skill_name" : "��ͨ��",
	"damage_type" : "����"
]),
([	"action" : "$Nһ����ʹһ�С�б��ʽ�������Ҽ翿��$n���ز�",
	"force" : 330,
	"dodge" : 15,
	"lvl" : 45,
	"skill_name" : "б��ʽ",
	"damage_type" : "����"
]),
([	"action" : "$N�����鰴������ʹһ�С��������š�����$n��$l��ȥ",
	"force" : 330,
	"dodge" : 30,
	"lvl" : 50,
	"skill_name" : "��������",
	"damage_type" : "ץ��"
]),
([	"action" : "$N˫����ȭ����ǰ��󻮻���һ�С�˫����������$n��$l",
	"force" : 340,
	"dodge" : 25,
	"lvl" : 55,
	"skill_name" : "˫����",
	"damage_type" : "����"
]),
([	"action" : "$N�����黮������һ�ǡ�ָ�ɴ�������$n���ɲ�",
	"force" : 340,
	"dodge" : 20,
	"lvl" : 60,
	"skill_name" : "ָ�ɴ�",
	"damage_type" : "����"
]),
([	"action" : "$Nʹ��������ʽ�������ֻ���$n��$l�����ֹ���$n���ɲ�",
	"force" : 350,
	"dodge" : 15,
	"lvl" : 65,
	"skill_name" : "����ʽ",
	"damage_type" : "����"
]),
([	"action" : "$N˫�ֲ�ͣ�ػ�Ȧ��һ�С����֡�����ס��$n��ȫ��",
	"force" : 350,
	"dodge" : 10,
	"lvl" : 70,
	"skill_name" : "����",
	"damage_type" : "����"
]),
([	"action" : "$N�ҽš��𼦶���������ϥ����$n���ɲ������ֲ���$n���ʺ�",
	"force" : 380,
	"dodge" : 10,
	"lvl" : 75,
	"skill_name" : "�𼦶���",
	"damage_type" : "ץ��"
]),
([	"action" : "$N��ǰ΢һ����һ�С���̽������������һ���������͵ز���$n���ʺ�",
	"force" : 390,
	"dodge" : 15,
	"lvl" : 80,
	"skill_name" : "��̽��",
	"damage_type" : "ץ��"
]),
([	"action" : "$N˫�����ط�ת��һ�С���Ů���󡹣���$n���ز��͸���ͬʱ��ȥ",
	"force" : 400,
	"dodge" : 25,
	"lvl" : 85,
	"skill_name" : "��Ů����",
	"damage_type" : "����"
]),
([	"action" : "$Nһ��������Ʋ��������ȭ����Ȧ����$n���沿",
	"force" : 400,
	"dodge" : 20,
	"lvl" : 90,
	"skill_name" : "����Ʋ��",
	"damage_type" : "����"
]),
([	"action" : "$Nһ����ת����ȡ��������$n��������ȥ",
	"force" : 400,
	"dodge" : 30,
	"lvl" : 95,
	"skill_name" : "ת�����",
	"damage_type" : "����"
]),
([	"action" : "$Nʹһ�С���������������һ��һ��������һȭ����$n��$l",
	"force" : 400,
	"dodge" : 30,
	"lvl" : 100,
	"skill_name" : "������",
	"damage_type" : "����"
]),
([	"action" : "$N��ǰ�����󹭲�������һ�ǡ��Դ�����һȭ����$n��ͷ��",
	"force" : 400,
	"dodge" : 25,
	"lvl" : 105,
	"skill_name" : "�Դ�",
	"damage_type" : "����"
]),
([	"action" : "$Nʹһ�С�Ұ����ס���˫����ס$n���ֱۣ��粿�͵���$n��в�¿�ȥ",
	"force" : 400,
	"dodge" : 20,
	"lvl" : 110,
	"skill_name" : "Ұ�����",
	"damage_type" : "����"
]),
([	"action" : "$Nʹһ�С�������ɽ�������ֱ�ס$n��������������$n������",
	"force" : 420,
	"dodge" : 15,
	"lvl" : 115,
	"skill_name" : "������ɽ",
	"damage_type" : "����"
]),
([	"action" : "$Nһ����ʮ���֡������ִ���������$n����в��ȥ",
	"force" : 420,
	"dodge" : 10,
	"lvl" : 120,
	"skill_name" : "ʮ����",
	"damage_type" : "����"
]),
([	"action" : "$N��һ�����鲽��˫����ȭ���棬һ�����������ǡ���ͬʱ����$n�ĺ���",
	"force" : 430,
	"dodge" : 15,
	"lvl" : 125,
	"skill_name" : "��������",
	"damage_type" : "ץ��"
]),
([	"action" : "$Nʹһ�С�����������$n�����ˤȥ",
	"force" : 440,
	"dodge" : 30,
	"lvl" : 130,
	"skill_name" : "�����",
	"damage_type" : "����"
]),
([	"action" : "ֻ����ž����һ����$Nʹһ�С�ת����������ҽ�����$n�ı���������ͬʱ����$n���ظ�",
	"force" : 450,
	"dodge" : 20,
	"lvl" : 135,
	"skill_name" : "ת�����",
	"damage_type" : random(2)?"����":"����"
]),
([	"action" : "$N���ҿ�����һ�С��乭�仢��������קס$n���ֱۣ�����һȭ����$n��Ҹ��",
	"force" : 460,
	"dodge" : 25,
	"lvl" : 140,
	"skill_name" : "�乭�仢",
	"damage_type" : "����"
]),
([	"action" : "$N˫�ֻ���һ����Ȧ��һ����Ȧ��һȦȦ��$n���Ű�Χס���·������������ƣ�һ������$n��ȫ������Ҫ������һ�С�����Ʊա���ʮ�����У������ޱ�",
	"force" : 500,
	"dodge" : 40,
	"lvl" : 145,
	"skill_name" : "����Ʊ�",
	"damage_type" : "����"
])
});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("��̫��ȭ������֡�\n");
	if ((int)me->query_skill("taiji-shengong", 1) < 20)
		return notify_fail("���̫���񹦻�򲻹����޷�ѧ̫��ȭ��\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷���̫��ȭ��\n");
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
	object ob, victim;

	level = (int)me->query_skill("taiji-quan", 1);

	ob = me->select_opponent();

	if( me->query_temp("taiji") )
		me->add_temp("taiji_fight", 1);

	if( me->query_temp("double_attack") == 1 )
	{
		return ([
		"action": "$N���ֽ��ڿ��л��ɴ�Ȧ�����ֽ�������������Ҳ��������΢��",
		"force" : 380+random(120),
		"dodge" : 20,
		"parry" : 10,
		"damage": 120+random(80),
		"weapon": "���ֽ���",
		"damage_type" : "����" ]);
	}

	if( objectp(victim = me->query_temp("nian")) ) 
	{
		if( ob == victim && !me->query("jiali") && me->query("jiajin") < 2 )
		{
			ob->receive_damage("jing", level/3, "����͸֧��������");
			ob->receive_damage("jingli", level/3, "����͸֧��������");
		} 
		else if( !me->query_temp("taiji") &&
		(me->query("jiali") > 0 || me->query("jiajin") > 1) )
		{
			tell_object(me, "\n��������󷢾�ȭ���ͻ���˫��Բת��ʱ�жϡ�\n");
			me->delete_temp("nian");
		}
	}

	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("�������������̫��ȭ��\n");
	me->receive_damage("jingli", 15);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"taiji-quan/" + action;
}

int valid_combine(string combo)
{
	if (this_player()->query_skill("taiji-shengong", 1) > 99)
	return combo=="mian-zhang";
}
mapping *query_skilldbase() {return action;}