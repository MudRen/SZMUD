// Code of ShenZhou
// damo-jian.c ��Ħ��

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action":"$Nʹһʽ��������Ե����������$w����΢�񣬻ó�һ���������$n��$l",
	"force" : 120,
        "dodge" : -10,
	"damage": 55,
	"lvl" : 0,
	"skill_name" : "������Ե��",
	"damage_type":	"����"
]),
([	"action":"$N����ǰ��ʹ������ȥ�����С��������������ޣ�$w��������$n��$l��ȥ",
	"force" : 140,
        "dodge" : -10,
	"damage": 60,
	"lvl" : 9,
	"skill_name" : "��ȥ������",
	"damage_type":	"����"
]),
([	"action":"$Nһʽ��������ɣԶ��������Ʈ�����ߣ��˷�����������$wңҡָ��$n��$l",
	"force" : 160,
        "dodge" : 5,
	"damage": 65,
	"lvl" : 18,
	"skill_name" : "������ɣԶ",
	"damage_type":	"����"
]),
([	"action":"$N��������Ծ��һʽ���ֻط����᡹���������ּ�ת������ն��$n��$l",
	"force" : 180,
        "dodge" : 10,
	"damage": 70,
	"lvl" : 27,
	"skill_name" : "�ֻط�����",
	"damage_type":	"����"
]),
([	"action":"$N����$w�й�ֱ����һʽ��ˮ��ͨ���š���������Ϣ�ض�׼$n��$l�̳�һ��",
	"force" : 220,
        "dodge" : 15,
	"damage": 75,
	"lvl" : 36,
	"skill_name" : "ˮ��ͨ����",
	"damage_type":	"����"
]),
([	"action":"$N����$wбָ���죬��â���£�һʽ������������������׼$n��$lбб����",
	"force" : 260,
        "dodge" : 5,
	"damage": 80,
	"lvl" : 44,
	"skill_name" : "����������",
	"damage_type":	"����"
]),
([	"action":"$N��ָ�����㣬����$w�Ƴ�����ѩ����â��һʽ��ǧ��һέȥ������$n��$l",
	"force" : 320,
        "dodge" : 5,
	"damage": 85,
	"lvl" : 52,
	"skill_name" : "ǧ��һέȥ",
	"damage_type":	"����"
]),
([	"action":"$N���Ƶ�����һʽ�����Ķ���������$w�Ի���Ծ�����缲�������$n���ؿ�",
	"force" : 380,
        "dodge" : 5,
	"damage": 90,
	"lvl" : 60,
	"skill_name" : "���Ķ�����",
	"damage_type":	"����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_combine(string combo) { return combo=="xiuluo-dao"; }

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
        int i, j, wt, level;
       	object target;
	string *msg;

	level   = (int) me->query_skill("damo-jian",1);
	wt = me->query_temp("sl_weituo");
	target = me->select_opponent();
	weapon = me->query_temp("weapon");

	msg = ({ 
		HIR"\n$N����Խ��Խ��������ͻ�죬���֮�䣬$n" +HIR"��ȫ�ǽ���������\n"NOR,
		HIY"\n$N���潣ת���ؽ����ӣ�һ������һ�������಻�����������������������ޱȡ�\n"NOR,
		HIC"\nԭ����Ħ���ߵľ��Ǹ���·�ӣ��˿�ȴ���������鶯֮�������Ƹ���������\n"NOR,
		HIW"\n��ʱ$N�Ľ���һ���Ƴ���Ȼ������Τ�ӷ�ħ�������ӵ������쾡�¡�\n"NOR,
	});

	if( wt > 1 && wt < 6 && !me->query_temp("weituo_attack")) {

		message_vision( msg[wt-2] , me, weapon);
		me->set_temp("weituo_attack", 1);
		for( j=0; j < wt-1; j++ )
		{
			me->add("neili", -50);
			COMBAT_D->do_attack(me, target, weapon);
		}
		me->delete_temp("weituo_attack", 1);
		me->add_temp("sl_weituo", 1);

	}

        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ�����������Ħ����\n");

        if( (int)me->query_skill("qianye-shou", 1) < 100 )
                return notify_fail("�������ǧҶ����Ϊ��������\n");

	me->receive_damage("jingli", 25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"damo-jian/" + action;
}
