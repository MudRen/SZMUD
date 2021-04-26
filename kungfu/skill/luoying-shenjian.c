// Code of ShenZhou
//luoyingshenjian-zhang.c
//kane 14/10/97  

#include <ansi.h>
#include <combat.h>

inherit SKILL;

mapping *action = ({
([      "action" :"$N��ǰһ����˫�ƶ�Ȼ��һ�����Ʒ��أ�����б�ɣ�����һ�С�����էչ��������$n��$l",
        "force" : 150,
        "dodge" : 0, 
        "parry" : -10, 
        "damage": 15,
        "lvl" : 0,
        "skill_name" : "����էչ",
        "damage_type" : "����"
]),
([      "action" :"$N�����ֲ������ƻ��⣬ʹ��һ�С��ط�������������䲻��ǿ������ȴ�紺�����棬�޿ײ��룬����$n����",
        "force" : 180,
        "dodge" : 10, 
        "parry" : -5, 
        "damage": 20,
        "lvl" : 8,
        "skill_name" : "�ط����",
        "damage_type" : "����"
]),
([      "action" :"$N����һ�㣬Ծ�����࣬һʽ�����Ƿɻ������ڰ������ת����Ȧ�ӣ���ջ��ƣ���$n��ͷ����",
        "force" : 220,
        "dodge" : 25, 
        "parry" : -5, 
        "damage": 25,
        "lvl" : 16,
        "skill_name" : "���Ƿɻ�",
        "damage_type" : "����"
]),
([      "action" :"$N����۽���ȥ��ʹ��һ�С��꼱��񡹣��������٣�˫�Ʒ����罣����$n���������ʮ���ƣ�$n��ʱ��æ����",
        "force" : 250,
        "dodge" : 20, 
        "parry" : -15, 
        "damage": 30,
        "lvl" : 24,
        "skill_name" : "�꼱���",
        "damage_type" : "����",
	"weapon" : "�Ʒ�"
]),
([      "action" :"$N����һ�ڳ�����˫��֮�������ĵ�����Ȼһ�֣�һ�С��Ǻ����졹��һ�������ƾ���Ȼ����$n��$l",
        "force" : 290,
        "dodge" : 15, 
        "parry" : -5, 
        "damage": 35,
        "lvl" : 32,
        "skill_name" : "�Ǻ�����",
	"weapon" : "�ƾ�",
        "damage_type" : "����"
]),
([      "action" :"$N˫��΢��������²���������һ�С������׷ɡ���ֻ��$N˫�ۻӶ�������˷�������Ӱ��Ѹ�����׵ػ���$n",
        "force" : 330,
        "dodge" : 20, 
        "parry" : -10, 
        "damage": 40,
        "lvl" : 40,
        "skill_name" : "�����׷�",
	"weapon" : "����",
        "damage_type" : "����"
]),
([      "action" :"$N΢΢һЦ��ʹ��һ�С�����׷�¡�����������ǰ������������ת����סȫ��ͻȻ���ƺ�����������һ������Ӱ���ٵػ���$n��$l",
        "force" : 380,
        "dodge" : 25, 
        "parry" : -10, 
        "damage": 45,
        "lvl" : 48,
        "skill_name" : "����׷��",
        "damage_type" : "����"
]),
([      "action" :"$N�ֱ�΢�ͻȻ����һ����ͷ�����䣬����һʽ�������®���������㱻������һ�ɷ�Բ������������֮��",
        "force" : 400,
        "dodge" : 10, 
        "parry" : 25, 
        "damage": 50,
        "lvl" : 56,
        "skill_name" : "�����®",
        "damage_type" : "����"
]),
([      "action" :"$N��ָ��£��������Ե��һ�С����ƺ�ȡ�������Ϊ�����Ʒ�������������죬���ʯ�����$n������������",
        "force" : 350,
        "dodge" : 25, 
        "parry" : -5, 
        "damage": 60,
        "lvl" : 64,
        "skill_name" : "���ƺ��",
	"weapon" : "�Ʒ�",
        "damage_type" : "����"
]),
([      "action" :"$N����������ʹ��һ�С��׺羭�졹�������������£�����$nü�ģ���������������˳��һ��������һ�䣬��ֱ���⣬ת��$n��$l",
        "force" : 390,
        "dodge" : 20, 
        "parry" : -5, 
        "damage": 70,
        "lvl" : 72,
        "skill_name" : "�׺羭��",
        "damage_type" : "����"
]),
([      "action" :"$N����������²ȳ��Ź����Է�λ��˫�ƻ�������һʽ���������������������ȣ�����$n��$l������������˫�ƾ�����һ���������",
        "force" : 450,
        "dodge" : -20, 
        "parry" : 30, 
        "damage": 80,
        "lvl" : 80,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" :"$Nһ����Х���������ߣ�ʹ��һʽ����Ӣ���졹���������Ʒ׷ɣ�������һʵ�������һʵ�����������罣����Ʈ�����ɣ�$nȫ��Ҫ����һ�����ܹ���",
        "force" : 420,
        "dodge" : 25, 
        "parry" : -10, 
        "damage": 90,
        "lvl" : 90,
	"weapon" : "�Ʒ�",
        "skill_name" : "��Ӣ����",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="xuanfeng-saoye"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("����Ӣ���Ʊ�����֡�\n");
        if ((int)me->query_skill("bitao-xuangong", 1) < 20)
          return notify_fail("��ı���������򲻹����޷�ѧ��Ӣ���ơ�\n");
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
        level   = (int) me->query_skill("luoying-shenjian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 50)
                return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 50)
                return notify_fail("�������̫���ˡ�\n");
        me->receive_damage("jingli", 25);
	me->add("neili", -5);
       
       return 1;
}

string perform_action_file(string action)
{
       return __DIR__"luoying-shenjian/" + action;
}
