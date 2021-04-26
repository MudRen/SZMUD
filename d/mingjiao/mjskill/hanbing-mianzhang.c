// Code of ShenZhou
// hanbing-mianzhang.c, based on xingxiu-duzhang.c
// by Long 05/20/97
#include <ansi.h>
inherit SKILL;
//�������ߡ�$N����Ʈ�����ɣ�˫���ڿ���һ��������һ�󺮷磬��$n��$1��ȥ
//����̹ǡ�$NͻȻ˫�ֻ���Ϊָ����$n��$1����ȥ��
//��ѩ���졣$N����һ�䣬����$n�ɱ���ͬʱ˫�Ƽ��İ�$n��������Ӱֻ�У�
//

mapping *action = ({
([      "action": "$N����¶�������Ц�ݣ�����������ɫ��˫��ɨ��$n��$l",
        "dodge": 30,
        "force": 280,
//      "poison": 80,
        "damage_type": "����"
]),
([      "action": "$NͻȻ������ת��������$n��˫�Ʒ���������$n��$l",
        "dodge": 10,
        "force": 200,
//      "poison": 60,
        "damage_type": "����"
]),
([	"action": "$N�������������֣�һ�С���ʬ���������ޱȵ�ץ��$n��$l",
	"dodge": -20,
	"force": 450,
	"damage": 65,
//      "poison": 100,
	"damage_type": "����"
]),
([	"action": "$N˫��Ю��һ���ȳ�֮������$n��$l",
	"dodge": 10,
	"force": 350,
	"damage": 60,
//      "poison": 80
	"damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="sanyin-zhua"; }
mapping query_action(object me)
{
        if (random(me->query_skill("strike")) > 60 &&
            me->query_skill("force") > 50 &&
            me->query("neili") > 100 ) {
                me->add("neili", -100);
                return ([
                "action":BLU "$Nҧ����⣬������Ѫ���ۼ�ȫ�����������$n"NOR,
                "force": 480,
		"damage": 80,
                "damage_type": "����"]);
        }
        return action[random(sizeof(action))];
}

int valid_learn(object me)
{
	int  nb,  nh;
        nb = (int)me->query_skill("poison", 1);
        nh = (int)me->query_skill("xingxiu-duzhang", 1);

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�����޶��Ʊ�����֡�\n");
	if ((int)me->query_skill("huagong-dafa", 1) < 10)
		return notify_fail("��Ļ����󷨻�򲻹����޷������޶��ơ�\n");
	if ( nb < 100 && nb <= nh )
                return notify_fail("��Ķ�����Ϊ�������޷�������޶��ơ�\n");

	if ((int)me->query("max_neili") < 60)
		return notify_fail("�������̫�����޷������޶���");
	return 1;
}


int practice_skill(object me)
{
	int  nb,  nh;
        nb = (int)me->query_skill("poison", 1);
        nh = (int)me->query_skill("xingxiu-duzhang", 1);

	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 8)
		return notify_fail("����������������޶��ơ�\n");
	if ( nb < 100 && nb <= nh )
                return notify_fail("��Ķ�����Ϊ�������޷�������޶��ơ�\n");

	if (me->query_skill("xingxiu-duzhang", 1) < 50)
		me->receive_damage("jingli", 20);
	else
		me->receive_damage("jingli", 30);
	me->add("neili", -5);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	if( random(me->query_skill("xingxiu-duzhang", 1)) > 30 ) {
		victim->apply_condition("xx_poison", 
		random(me->query_skill("xingxiu-duzhang", 1)) + victim->query_condition("xx_poison"));
	}
}
string perform_action_file(string action)
{
        if ( this_player()->query_skill("xingxiu-duzhang", 1) >= 30 )
                return __DIR__"xingxiu-duzhang/" + action;
}
