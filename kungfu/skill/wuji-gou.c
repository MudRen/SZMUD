// Code of ShenZhou
// wuji-gou.c �޼�����
// snowbird august 99
// 1.1.1.1

inherit SKILL;

mapping *action = ({
([      "action" : "$N����$w�����������һ����һʽ��ѩ���צ����ٿ������$n��$l",
        "force" : 100,
        "dodge" : 20,
        "damage" : 15,
        "lvl" : 0,
        "damage_type" : "����"
]),
([      "action" : "$N���˴�$wһת��б�ӹ�ȥ��һʽ������̩���������ţ������磬�ݺݵ�ɨ�˹�ȥ",
        "force" : 150,
        "dodge" : 15,
        "damage" : 30,
        "lvl" : 20,
        "damage_type" : "����"
]),
([      "action" : "$N��Ӱ���Σ�һ�С�Ұ����ס���$w�����޷纣�꣬���಻�ϵس�$nֱ������",
        "force" : 200,
        "dodge" : 10,
        "damage" : 45,
        "lvl" : 40,
        "damage_type" : "����"
]),
([      "action" : "$N��$wһ�죬����һ��ԲȦ��һ�ǡ��乭��񡱣����ҿ������򽫹�ȥ",
        "force" : 250,
        "dodge" : 15,
        "damage" : 60,
        "lvl" : 60,
        "damage_type" : "����"
]),
([      "action" : "$Nһ�С����߿��衱������$wֱ�����������һ������Բ�Ĺ�������ͷ����",
        "force" : 300,
        "dodge" : 15,
        "damage" : 75,
        "lvl" : 80,
        "damage_type" : "����"
]),
([      "action" : "$N�����ֱ���ȥ��$wһ�С������蹵�������϶��£�������ȥ",
        "force" : 350,
        "dodge" : 20,
        "damage" : 90,
        "lvl" : 100,
        "damage_type" : "����"
]),
([      "action" : "$N����Ծ�𣬾��ڿ���һ�С�����������������»���$wֱն$nҪ��",
        "force" : 400,
        "dodge" : 20,
        "damage" : 105,
        "lvl" : 120,
        "damage_type" : "����"
]),
([      "action" : "$N$wһ�飬ʹһ�С���Į������˳�Ʒ�ն�����级�籼�ף�ȡ��$n$l",
        "force" : 450,
        "dodge" : 20,
        "damage" : 120,
        "lvl" : 140,
        "damage_type" : "����"
]),
});


int valid_enable(string usage) { return (usage == "hook") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 150)
                return notify_fail("�������������\n");
        if ((int)me->query_skill("hongming-xuangong", 1) < 20)
                return notify_fail("��ĺ�ڤ�������̫ǳ��\n");
        if ((int)me->query_skill("hook", 1) < 20)
                return notify_fail("��Ĺ���������������ʵ��\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        mapping retval;
		int i, j, level, neili;
        level  = (int) me->query_skill("wuji-gou",1);

        for(i = sizeof(action); i > 0; i--) { 
                if(level > action[i-1]["lvl"]) {
                      j = NewRandom(i, 20, level/5);
                      break;
                }
		}
		retval = action[j];
		if (random(me->query_skill("hook")) > 150 
            && me->query_skill("force") > 100  && me->query("neili") > 500 ) {
			retval["damage"] = retval["damage"] + me->query_skill("force")/5;
		}
        return retval;
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "hook")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("jingli") < 40)
                return notify_fail("��ľ����������޼�������\n");
        me->receive_damage("jingli", 30);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"wuji-gou/" + action;
}

mapping *query_skilldbase() {return action;}
