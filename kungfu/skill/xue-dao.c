// Code of ShenZhou
// xue-dao.c Ѫ��
// updated by snowbird sept 99
// 1.1.1.2

inherit SKILL;

mapping *action = ({
(["action" : "$Nʹ��һ�С�ĥ��˱Ѫ�����ѵ�ҧ�ڿ��У�ֻ��$n��ǰ�����ת������������͵�������ǰ���γ�����һ��ֱ����ȥ",
  "force" : 100,
  "dodge" : -10,
  "parry" : 5,
  "damage": 15,
  "lvl" : 0,
  "skill_name" : "ĥ��˱Ѫ",
  "damage_type" : "����"
]),
(["action" : "$N�����˼磬��ͨ춱ۣ���ǰһ�壬���һ���룬�������ţ�����һ����$n����·ʵ������������һ�С���ֽ������",
  "force" : 150,
  "dodge" : -10,
  "parry" : 10,
  "damage": 25,
  "lvl" : 12,
  "skill_name" : "��ֽ����",
  "damage_type" : "����"
]),
(["action" : "$N�ڷ��ɺɹ��������е�ֱ��ǰ�죬һ�С�Ѫ��ãã��������$wֱ��ǰ�죬��$n����������������ڵ���֮��",
  "force" : 200,
  "dodge" : -5,
  "parry" : 5,
  "damage": 35,
  "lvl" : 20,
  "skill_name" : "Ѫ��ãã",
  "damage_type" : "����"
]),
(["action" : "$N��һ�һ�С����Ǿ��졹�����е����ַɳ���һ���⣬����$n��$l��ȥ",
  "force" : 250,
  "dodge" : 5,
  "parry" : 5,
  "damage": 50,
  "lvl" : 28,
  "skill_name" : "���Ǿ���",
  "damage_type" : "����"
]),
(["action" : "$Nһ�С�Ѫ�����������ԭ�ش���һ��ת, ����һ����$n��$lͱ�˹�ȥ",
  "force" : 300,
  "dodge" : 5,
  "parry" : 5,
  "damage": 55,
  "lvl" : 36,
  "skill_name" : "Ѫ������",
  "damage_type" : "����"
]),
(["action" : "$N˫�ַ�ִ���⣬��춻��У�ͻȻ���΢����һ�С�͵�ƻ��ա������ִ��ұ��´���ת��$n��Ŀ�⣬����ִ���ʹ�$n��$l",
  "force" : 350,
  "dodge" : -10,
  "parry" : 15,
  "damage": 60,
  "lvl" : 44,
  "skill_name" : "͵�ƻ���",
"damage_type" : "����"
]),
(["action" : "$NͻȻ�������ʣ�����۽���ȥ�������򣬷��ֳ鵶��һʽ��Ѫϴ��ӡ���ֻ��һƬƥ��Ҳ�Ƶĵ����$n����ֱ���������",
  "force" : 400,
  "dodge" : 10,
  "parry" : 20,
  "damage": 75,
  "lvl" : 52,
  "skill_name" : "Ѫϴ���",
  "damage_type" : "����"
]),
(["action" : "$N����ƽָ��һ�С�Ѫ�����桹�����������������ֱ�����������������$n������",
  "force" : 450,
  "dodge" : 5,
  "parry" : 25,
  "damage": 80,
  "lvl" : 60,
  "skill_name" : "Ѫ������",
  "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("longxiang-banruo", 1) < 20
	&& (int)me->query_skill("xiaowuxiang", 1) < 20){
		return notify_fail("���������������̫ǳ��\n");
	}
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
        mapping retval;
        int i, j, level, neili;
        level  = (int) me->query_skill("xue-dao",1);

        for(i = sizeof(action); i > 0; i--) {
                if(level > action[i-1]["lvl"]) {
                      j = NewRandom(i, 20, level/5);
                      break;
                }
        }
        retval = action[j];
        if (random(me->query_skill("blade")) > 150 && (me->query_skill_mapped("force") == "longxiang-banruo")
        && me->query_skill("force") > 100  && me->query("neili") > 800 ) {
			// has some chance to upgrade damage if neili and force are high
			// cost some neili
			if (random(3)) {
               retval["damage"] = retval["damage"] + random(me->query_skill("force"))/5;
			   me->add("neili", -50);
            }
        }
        return retval;
}

int practice_skill(object me)
{
        object weapon;

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if ((int)me->query("jingli") < 50)
                return notify_fail("��ľ���������Ѫ����\n");
        me->receive_damage("jingli", 35);
        return 1;
} 
string perform_action_file(string action)
{
        if ( this_player()->query_skill("xue-dao", 1) >= 50 )
                return __DIR__"xue-dao/" + action;
}
