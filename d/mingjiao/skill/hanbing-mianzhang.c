// Code of ShenZhou
// hanbing-mianzhang.c 	��������
// Long 05/20/97
// Zhangchi 2/2000

#include <ansi.h>
inherit SKILL;

//�������ߡ�$n����Ʈ�����ɣ�˫���ڿ���һ��������һ�󺮷磬��$N��$1��ȥ
//����̹ǡ�$nͻȻ˫�ֻ���Ϊָ����$N��$1����ȥ��
//��ѩ���졣$n����һ�䣬����$N�ɱ���ͬʱ˫�Ƽ��İ�$N��������Ӱֻ�У�
//˪�����ء�$Nֻ����ǰһ�����ж��Ի���ȫ���ѱ�������$n������֮��,
//          $n������Ц,���������ĳ�������ͷ�������Ϣ��ӡ��$N�����š�
//	    $n���ⲻ֧,��$N�������󡢾�������֮�ʣ�����Ϯ����
//	    $n�����棬���Ӻ����������������ˣ�˫�����಻���ز�����$N����,����ֱ治����ʵ��
//	    $n������Σ�������ǰ,���Ʒ���һ�ɺ���Ϯ��$NС����

mapping *action = ({
([      "action": "$N����Ʈ�����ɣ�˫���ڿ���һ��������һ�󺮷磬��$n��$l��ȥ",
        "dodge": 30,
        "force": 280,
	"parry": 15,
	"damage": 50,
        "lvl": 20,
        "skill_name": "��������",
        "damage_type": "����"
]),
([      "action": "$NͻȻ˫�ֻ���Ϊָ����$n��$l����ȥ",
        "dodge": 10,
        "force": 200,
	"parry": 20,
	"damage": 70,
        "lvl": 40,
        "skill_name": "����̹�",
        "damage_type": "����"
]),
([      "action": "$N����һ�䣬����$n�ɱ���ͬʱ˫�Ƽ��İ�$n��������Ӱֻ��",
        "dodge": -20,
        "force": 450,
	"parry": 25,
	"damage": 80,
        "lvl": 60,
        "skill_name": "��ѩ����",
        "damage_type": "����"
]),
([      "action": "$nֻ����ǰһ�����ж��Ի���ȫ���ѱ�������$N������֮��",
        "dodge": 10,
        "force": 350,
	"parry": 30,
	"damage": 100,
        "lvl": 80,
        "skill_name": "˪������",
        "damage_type": "����"
]),
([      "action": "$N������Ц,���������ĳ�������ͷ�������Ϣ��ӡ��$n������",
        "dodge": 20,
        "force": 300,
	"parry": 35,
	"damage": 110,
        "lvl": 100,
        "damage_type": "����"
]),
([      "action": "$N���ⲻ֧,��$n�������󡢾�������֮�ʣ�����Ϯ��",
        "dodge": -20,
        "force": 400,
	"parry": 15,
	"damage": 130,
        "lvl": 120,
        "damage_type": "����"
]),
([      "action": "$N�����棬���Ӻ����������������ˣ�˫�����಻���ز�����$n����,����ֱ治����ʵ",
        "dodge": 30,
        "force": 350,
	"parry": 35,
	"damage": 120,
        "lvl": 140,
        "damage_type": "����"
]),
([      "action": "$N������Σ�������ǰ,���Ʒ���һ�ɺ���Ϯ��$nС��",
        "dodge": 0,
        "force": 400,
	"parry": 15,
	"damage": 130,
        "lvl": 160,
        "damage_type": "����"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
int valid_combine(string combo) { return combo=="yingzhua-qinna"; }

int valid_learn(object me)
{
        int  nb,  nh;

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���������Ʊ�����֡�\n");

        if ((int)me->query_skill("shenghuo-xuanming", 1) < 10)
                return notify_fail("���ʥ��������򲻹����޷����������ơ�\n");

        if ((int)me->query("max_neili") < 50)
                return notify_fail("�������̫�����޷�����������");
        return 1;
}


int practice_skill(object me)
{
	int hbmz, qfsf;

	hbmz = me->query_skill("hanbing-mianzhang");
	qfsf = me->query_skill("qingfu-shenfa");

        if ((int)me->query("jingli") < 30)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 8)
                return notify_fail("��������������������ƣ\n");
        if ( qfsf < hbmz*2/3 )
                return notify_fail("�����������Ϊ�������޷���ߺ������ơ�\n");

        me->add("neili", -5);
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level  = (int)me->query_skill("hanbing-mianzhang", 1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if( random(me->query_skill("hanbing-mianzhang", 1)) > 30 ) {
                victim->apply_condition("hanbing_damage", 
                random(me->query_skill("hanbing-mianzhang", 1)/2) + victim->query_condition("hanbing_damage"));
        }
}


string perform_action_file(string action)
{
        return __DIR__"hanbing-mianzhang/" + action;
}
