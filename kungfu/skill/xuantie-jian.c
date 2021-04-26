
//xuantie-jian (��������)
//UPDATE BY SCATTER
//VERSION 1.0 BETA
//2001/08/05
// update by april 2001.12.18

// COLOR DEFINE
// RED - ��ɫ              HIR - ����ɫ
// GRN - ��ɫ              HIG - ����ɫ
// YEL - ����ɫ            HIY - ��ɫ
// BLU - ����ɫ            HIB - ��ɫ
// MAG - ǳ��ɫ            HIM - �ۺ�ɫ
// CYN - ����ɫ            HIC - ����ɫ
// WHT - ǳ��ɫ            HIW - ��ɫ

/*
[61] about xuantie-jian ��ʽ��                ���ڰ���(chchong)(Wed Aug 29)
----------------------------------------------------------------------
������������ʽ��
˳�̿��죬����ֺ���������ɽ���������£�
�������ף�бɨ������ƽĨ��ɳ������÷����


$N�������أ���ɽ��Ρ�ʣ�һ�С�˳�̿��졹ֱ��$n���ţ�
$N����һ����һʽ������ֺ������е�$wɨ��$n���䣬����֮����һ�ɱ�Ȼ������
ֻ��$N����$wͦ�����������ߣ��׹���磬һ�С�������ɽ������$n��
$NͻȻ��ʽ���������ֵݳ�$w�������˸һ�С��������¡�����$n���ϣ�
$N��������ȫ������$w��ô󿪴�ͣ���̤�й���һʽ���������ס���$w���ŷ�����$n��ȥ��
ͻȻ$N����$w�����ת��һ�С�ƽĨ��ɳ������Լ�д��з�ɳ����������ɨ��$n��
$N����$wͻȻбת�ƹ�$n���ƣ�һ�С�бɨ��������ʽ֮�����˷�����˼��ֱ������$n��ͷ��
$Nһ������$w��һ�С�����÷����ֻ�������������㺮����$n��ȥ��

��Ϊxuantie-jian �з��˹���ľ��������ڼ�����û����ʽ������������������120lv �ڳ�
save
$NͻȻ֮������ȫ�ޣ�ֻ�Ǽ�ƽ����һ�̣�ȴ�Ѿ����ڽ�ǰ����$n���ϴ�ȥ��Ȼ����ʽԽ��ƽƽ����ȴ��Խ��
$N����$w������磬��������ʽ������Ͷ��֮�������������ھ�����$n��ǰ�����罣���Ѿ����˹���һ��������ʤ��


������е����������Ļ��������ң��ҿ����ڲ����䣺��
*/



#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action":"$N�������أ���ɽ��Ρ�ʣ�һ�С�˳�̿��졹ֱ��$n����",
        "force" : 150,
        "dodge" : 5,
        "parry" : 5,
        "damage": 30,
        "lvl" : 0,
        "skill_name" : "˳�̿���",
        "damage_type":  "����"
]),
([      "action":"$N����һ����һʽ������ֺ������е�$wɨ��$n���䣬����֮����һ�ɱ�Ȼ����",
        "force" : 280,
        "dodge" : 15,
        "parry" : 15,
        "damage": 40,
        "lvl" : 20,
        "skill_name" : "����ֺ�",
        "damage_type":  "����"
]),
([      "action":"ֻ��$N����$wͦ�����������ߣ��׹���磬һ�С�������ɽ������$n",
        "force" : 350,
		"dodge" : 10,
        "parry" : 10,
        "damage": 50,
        "lvl" : 40,
        "skill_name" : "������ɽ",
        "damage_type":  "����"
]),
([      "action":"$NͻȻ��ʽ���������ֵݳ�$w�������˸һ�С��������¡�����$n����",
        "force" : 280,
    "dodge" : 15,
        "parry" : 15,
        "damage": 60,
        "lvl" : 60,
        "skill_name" : "��������",
        "damage_type":  "����"
]),
([      "action":"$N��������ȫ������$w��ô󿪴�ͣ���̤�й���һʽ���������ס���$w���ŷ�����$n��ȥ",
        "force" : 220,
    "dodge" : 8,
        "parry" : 8,
        "damage": 70,
        "lvl" : 80,
        "skill_name" : "��������",
        "damage_type":  "����"
]),
([      "action":"ͻȻ$N����$w�����ת��һ�С�ƽĨ��ɳ������Լ�д��з�ɳ����������ɨ��$n",
        "force" : 350,
        "dodge" : 10,
        "parry" : 10,
        "damage": 80,
        "lvl" : 100,
        "skill_name" : "ƽĨ��ɳ",
        "damage_type":  "����"
]),
([      "action":"$N����$wͻȻбת�ƹ�$n���ƣ�һ�С�бɨ��������ʽ֮�����˷�����˼��ֱ������$n��ͷ",
        "force" : 310,
        "dodge" : 15,
        "parry" : 15,
        "damage": 90,
        "lvl" : 120,
        "skill_name" : "бɨ����",
        "damage_type":  "����"
]),
([      "action":"$Nһ������$w��һ�С�����÷����ֻ�������������㺮����$n��ȥ",
        "force" : 310,
        "dodge" : 15,
        "parry" : 15,
        "damage": 100,
        "lvl" : 140,
        "skill_name" : "����÷��",
        "damage_type":  "����"
])

});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");


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
        level   = (int) me->query_skill("xuantie-jian",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        //**** ADD BY SCATTER (BUG FIX)
        object weapon; 
        if( !objectp(weapon = me->query_temp("weapon")) 
                || (string)weapon->query("skill_type") != "sword" ) 
                return notify_fail("��ʹ�õ��������ԡ�\n"); 
        //**** EOF ADD BY SCATTER (BUG FIX)

        if ((int)me->query("jingli") < 30)
                return notify_fail("��ľ�������������������\n");
        me->receive_damage("jingli", 25, "����͸֧��������");
        return 1;
}


string perform_action_file(string action)
{
	return __DIR__"xuantie-jian/" + action;
}
