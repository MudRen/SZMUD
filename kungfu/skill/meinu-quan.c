//��Ůȭ�� 
//meinu-quan.c
// Code By Scatter
// Chinese By Lisser
// V. 2.0

/*
����Ůȭ����

    ��Ůȭ��ÿһ�ж�������һλ�Ŵ���Ů��Ů�ӵ���̬���񱾾ͱ仯�ȶ����٣�
��������Ů�Ը���в���֮�����Ц֮�ʡ���ϲ֮�֣��Ը���֪�Ѷȡ���ǧ������
��Ů���Ī���������̬��������֮�У��������ӣ�����ܽ⣿��Ůȭ��ʹ������
����ȣ������޷���ϰ��

  �������£��������ģ�������ģ�����׹¥��
  �ļ��麺���༧���ȣ�Ƽ�������༧������
  �������ˣ�������̣������貨����Ĺ�ľӡ�

  ���⹥������
    �����޵�����
      ָ�perform luowang
      ��������Ůȭ����Ч�ȼ�120����Ů�ľ���Ч�ȼ�100��
      �ص㣺˫ȭ�������޵��������˶�ʱ���ڲ��ܶ����ͻ�����
*/
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "ֻ��$Nʹ��"+HIM"���������¡�"+NOR"�������������һ�ݣ���$n�����ӳ�һȭ",
        "force" : 15,
        "dodge" : 30,
        "lvl" : 0,
        "skill_name" : "��������",
        "damage_type" : "����"
]),

([      "action" : "$Nһ��"+HIM"���������ġ�"+NOR"��˫�ִ��ؿڴ���$n�ݳ�",
        "force" : 30,
        "dodge" : 25,
        "lvl" : 20,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "$Nʹһ��"+HIM"��������ġ�"+NOR"��˫�۽��������ɨ��$n",
        "force" : 50,
        "dodge" : 20,
        "lvl" : 40,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$Nʹһ��"+HIM"������׹¥��"+NOR"���˵ع���$n����",
        "force" : 70,
        "dodge" : 15,
        "lvl" : 60,
        "skill_name" : "����׹¥",
        "damage_type" : "����"
]),
([      "action" : "$N˫���������£�ʹ��"+HIM"���ļ��麺��"+NOR"���������಻�ϵ��ĳ�",
        "force" : 100,
        "dodge" : 10,
        "lvl" : 80,
        "skill_name" : "�ļ��麺",
        "damage_type" : "����"
]),
([      "action" : "$N������$n��ǰչ�������������һ�㣬������$n������ȭ��������һ��"+HIM"���༧���ȡ�"+NOR,
        "force" : 130,
        "dodge" : 30,
        "lvl" : 100,
        "skill_name" : "�༧����",
        "damage_type" : "����"
]),
([      "action" : "$N��ָ������ȴ��һ��"+HIM"��Ƽ������"+NOR"������$n����",
        "force" : 160,
        "dodge" : 25,
        "lvl" : 130,
        "skill_name" : "Ƽ������",
        "damage_type" : "����"
]),
([      "action" : "$Nʹһ��"+HIM"���༧������"+NOR"���������ѣ�������$n��ȥ��˫��ֱ����ȭ",
        "force" : 190,
        "dodge" : 20,
        "lvl" : 160,
        "skill_name" : "�༧����",
        "damage_type" : "ץ��"
]),
([      "action" : "$Nһ��"+HIM"���������ˡ�"+NOR"����֫��ڱܿ�$n�Ĺ�����������$n��ȥ",
        "force" : 200,
        "dodge" : 15,
        "lvl" : 190,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" : "ֻ��$N��������$n���ԣ�����һ��"+HIM"��������̡�"+NOR"���¶�����$nֱ��",
        "force" : 210,
        "dodge" : 15,
        "lvl" : 200,
        "skill_name" : "�������",
        "damage_type" : "����"
]),
([      "action" : "$N����������ѻ������������������ˮ��Ư��һ��ƽ�$n������$n������ȭ��ȴ��һ��"+HIM"�������貨��"+NOR,
        "force" : 215,
        "dodge" : 30,
        "lvl" : 210,
        "skill_name" : "�����貨",
        "damage_type" : "ץ��"
]),
([      "action" : "$Nʹһ��"+HIM"����Ĺ�ľӡ�"+NOR"������֧�ã���������ӳ�����̾һ�������ּ���֮��",
        "force" : 220,
        "dodge" : 25,
        "lvl" : 220,
        "skill_name" : "��Ĺ�ľ�",
        "damage_type" : "����"
])


});

int valid_enable(string usage) { return usage=="cuff" || usage=="parry"; }
int valid_combine(string combo) { return combo=="xiaohun-zhang" || combo=="suhan-zhi"; }
int valid_learn(object me)
{

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��ϰ��Ůȭ��������֡�\n");
        if ((int)me->query_skill("yunu-xinjing", 1) < 10)
                return notify_fail("�����Ů�ľ��˽ⲻ��, �޷�ѧϰ��Ůȭ����\n");

        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷�����Ůȭ����");
        return 1;
}


int practice_skill(object me)
{

        if ((int)me->query("jingli") < 30)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 8)
                return notify_fail("���������������Ůȭ����\n");

        if (me->query_skill("riyue-quan", 1) < 50)
                me->receive_damage("jingli", 20);
        else
                me->receive_damage("jingli", 25);
        me->add("neili", -5);
        return 1;
}

mapping query_action(object me, object weapon) 
{
        return action[random(sizeof(action))];
}

string perform_action_file(string action)
{
                return __DIR__"meinu-quan/" + action;
}
