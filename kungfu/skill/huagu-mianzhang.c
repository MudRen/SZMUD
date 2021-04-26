// Code of ShenZhou
// huagu-mianzhang.c
// modified by aln 4 / 98

#include <ansi.h>

inherit SKILL;

// void create() { seteuid(getuid()); }

mapping *action = ({
([      "action": "$Nʹһ�С����߰�β����ȫ����Ȼһ������$nˤ���ڵ�",
	"dodge": -30,
	"parry": 10,
	"force": 20,
	"skill_name" : "���߰�β",
	"damage_type": "����"
]),
([      "action": "$N����������һ�С���������մ��$n������ͬʱչ��ҡ�򣬺��$n��ǰ��",
	"dodge": -15,
	"parry": -20,
	"force": 30,
	"skill_name" : "��������",
	"damage_type": "����"
]),
([      "action": "$N�����ⷭ���������ϣ������ڷ����ķ����ϣ�һ�С�˫����β����\n"
		  "ץס$n���ֱۣ��������",
	"dodge": -10,
	"parry": -10,
	"force": 30,
	"skill_name" : "˫����β",
	"damage_type": "����"
]),
([      "action": "$N˫�ƽ��棬ʹһ�С�˫�����项������$n���ֱۣ��ҽ�ǰ��$n����С��",
	"dodge": -5,
	"parry": 0,
	"force": 60,
	"skill_name" : "˫������",
	"damage_type": "����"
]),
([      "action": "$N���������ڹ����������$n���ֱۣ�������ȭ����ֱ��$n���沿��"
		   "һ�С��������̡�",
	"dodge": 0,
	"parry": 10,
	"force": 50,
	"skill_name" : "��������",
	"damage_type": "����"
]),
([      "action": "$N�ҽ���㣬��������$n�����棬ͬʱ�ҽŷ���$n��������������ߡ�",
	"dodge": 10,
	"parry": 20,
	"force": 60,
	"skill_name" : "�������",
	"damage_type": "����"
]),
([      "action": "$N�����鰴$n������ͻȻ�����ڲ���š�����ձ�����һ�ǡ�������ġ�\n"
		  "�ͻ�$n��$l",
	"dodge": 20,
	"parry": 20,
	"force": 80,
	"skill_name" : "�������",
	"damage_type": "����"
]),
([      "action": "$N���߿粽��һ�С����Ը�ɽ��������$n���ɲ�",
	"dodge": 25,
	"parry": 10,
	"force": 20,
	"skill_name" : "���Ը�ɽ",
	"damage_type": "����"
]),
([      "action": "$N��ϥ��$n����ϥ��ʹһ�С��ض�ɽҡ�������䲻��ʹ$nʧȥ����",
	"dodge": 25,
	"parry": 20,
	"force": 50,
	"skill_name" : "�ض�ɽҡ",
	"damage_type": "����"
]),
([      "action": "$N�ٳ���ȭ��$n�ұ۹�����һ�С�ֱ����̶�����߹�������ֱѹ$n������",
	"dodge": 30,
	"parry": 20,
	"force": 60,
	"skill_name" : "ֱ����̶",
	"damage_type": "����"
]),
([      "action": "$N����ȭ���������Լ����ұ���ǰ���Ϸ���$n���ұۣ�һ�С�����������",
	"dodge": 20,
	"parry": 30,
	"force": 20,
	"skill_name" : "��������",
	"damage_type": "����"
]),
([      "action": "$N�����Ҳ���˫�ְڶ��Ի�$n��һ�С�ˮ�����¡���\n"
		  "�������ֵ��ڻ��º��$n������",
	"dodge": 20,
	"parry": 20,
	"force": 60,
	"skill_name" : "ˮ������",
	"damage_type": "����"
]),
([      "action": "$N���������������ת����׵������һ�ǡ����߾��ɡ���\n"
		  "�Բ��ɿ���֮������$n��ȫ��",
	"dodge": 15,
	"parry": 20,
	"force": 80,
	"skill_name" : "���߾���",
	"damage_type": "����"
]),
([      "action": "$N��������$n���ֱ��ഥ��ͻȻ������$n����\n"
		  "ʹ����������ɽ������������$n",
	"dodge": 25,
	"parry": 30,
	"force": 50,
	"skill_name" : "������ɽ",
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return  usage=="strike" ||  usage=="parry"; }
int valid_combine(string combo) { return combo=="jueming-tui"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���������Ʊ�����֡�\n");

/*
	if ((int)me->query_skill("dulong-dafa", 1) < 20)
		return notify_fail("��Ķ����󷨻�򲻹����޷����������ơ�\n");
*/

        if( (int)me->query("sg/exp") < 5000 )
                return notify_fail("���������̳����ǵ��ؼ�������������������������ϰ��ߡ�\n");

        if( (int)me->query_con() < 30 )
                return notify_fail("��ĸ���Ƿ����������ϰ�������ơ�\n");

        if( (int)me->query_skill("force") < (int)me->query_skill("huagu-mianzhang", 1)  )
                return notify_fail("����ڹ���Ϊ�������ڼ�����ϰ�������ơ�\n");

        if( (int)me->query("max_neili") * 2 < (int)me->query_skill("huagu-mianzhang", 1) * 3 || (int)me->query("max_neili") < 1000 )
		return notify_fail("�������̫�����޷����������ơ�\n");
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
	level  = (int)me->query_skill("huagu-mianzhang", 1);
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if( (int)me->query_skill("huagu-mianzhang", 1) < 100 
        &&  base_name(environment(me)) != "/d/shenlong/liangongfang" )
                return notify_fail("�����ڵĻ������ƹ�����������������ϰ��\n");
               
	if ((int)me->query("jingli") < 100)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 100)
		return notify_fail("��������������������ơ�\n");
	me->receive_damage("jingli", 60);
	me->add("neili", -10);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"huagu-mianzhang/" + action;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
 //       object ob;
        int amount;
/*
	if( random(me->query_skill("huagu-mianzhang", 1)) > 30 ) {
		victim->apply_condition("sl_poison",
		random(me->query_skill("huagu-mianzhang", 1)/3) + (victim->query_condition("sl_poison")) );
	}

        if( ob = find_player("aln") )
        tell_object(ob, "\ndamage_bonus = " + damage_bonus + ".\n");
*/

        if( random(damage_bonus) > (int)victim->query_skill("force") / 2
        &&  !victim->query_temp("hgmz") )  {
                victim->set_temp("hgmz", 1);
                amount = 5 * damage_bonus/( 1 + victim->query_con()) + 1;
				amount = amount/100;
                victim->add_temp("apply/strength", -amount);
                victim->start_call_out( (: call_other, __FILE__, "remove_effect", victim, me, amount :), (int)me->query_skill("huagu-mianzhang", 1) / 10);
                message_vision(HIB"\n$N��ʱͷ��Ŀѣ����ʱ����Ż�£���䡰���������Ĳ�ס������\n"NOR, victim);
        }
}

void remove_effect(object victim, object me, int amount)
{
        victim->delete_temp("hgmz");
        victim->add_temp("apply/strength", amount);
        message_vision(HIB"\n$N�ظ�����Ѫ��ӿ�����ۡ���һ����������Ѫ��������ˮ��������˳�����\n"NOR, victim);
        if( me )
        victim->receive_wound("qi", amount * 10 + random(amount * 10), me);
        else
        victim->receive_wound("qi", amount * 10 + random(amount * 10),
                "�������ƶ�������");
}

