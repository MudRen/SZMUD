//Cracked by Roath
// xiake-wuqing.c ����������

inherit SKILL;

mapping *action = ({
([      "action" : "$Nһ�С�˭������¡�������$n���Ϸ�ȥ��$n��Ҫ������$N�������¶��ϲ���$n��$l",
        "dodge": 10,
        "force": 40,
        "damage": 0,
        "lvl" : 0,  
        "damage_type" : "����"
]),

});
int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
      	return notify_fail("�����������ֱ�����֡�\n");
	return 1;
}
mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if ((int)me->query_skill("xiake-wuqing", 1) >= 50)
		return notify_fail("��������������Ѿ��޷�������������ˡ�\n");
      if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");

	me->receive_damage("jingli", 30);
	me->add("neili", -5);
	return 1;
}
int valid_combine(string combo) 
{ 	if (strsrch(combo, "xiake") >= 0) 
		return 1;
	else
		return 0;
}
