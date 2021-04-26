// Code of ShenZhou
///kungfu/skill/yulong-baibian.c �����ٱ�
// Snowbird July 1999
// 1.1.1.1

inherit SKILL;

mapping *action = ({
([      "action" : "$nһʽ������Ծ��������Ծ���ٰ�ջ���һ�ܣ���ƮƮ���䵽$N���\n",
        "dodge"  : 10,
        "skill_name" : "����Ծ��"
]),
([      "action" : "$n�ۼ����н���������һת������һ�С�����Ǳ�ס���ɲ�Ǽ�������Ӱ���١�\n",
        "dodge"  : 20,
        "skill_name" : "����Ǳ��"
]),
([      "action" : "$n��ȻһЦ��һʽ���������ɡ���˲ʱ��ó�ǧ�ٸ���Ӱ������$N��ȥ��$N��ʧɫ��������ʽ������ա�\n",
        "dodge"  : 30,
        "skill_name" : "��������"
]),
([      "action" : "$n�ۼ����޿ɱܣ���Ȼ�������һʽ����Ծ���š������η��绯����������$Nͷ��ƮȻԾ����\n",
        "dodge"  : 40,
        "skill_name" : "��Ծ����"
]),
([      "action" : "$n��Хһ����һ�С�������ڡ��ڿն�����$Nͷ��������Ȧ����$N���������ƻ������Ӱ���١�\n",
        "dodge"  : 50,
        "skill_name" : "�������"
]),
([      "action" : "$n˫��һ�ţ�����һͦ������$N�Ĺ���������������ȥ������һ�С������������$N��ʽʹ�ϣ��޹�������\n",
        "dodge"  : 60,
        "skill_name" : "�������"
]),
([      "action" : "$n�������ʹ���������ĺ������������ڿհ�εض����ڿ�������ת�ۣ��������¡�\n",
        "dodge"  : 70,
        "skill_name" : "�����ĺ�"
]),
([      "action" : "$n���μ�ת������һ�С������ٱ䡹���������������У����Ī�⣬$NĿ�ɿɴ������Ʋ���һ�͡�\n",
        "dodge"  : 80,
        "skill_name" : "�����ٱ�"
])
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("yulong-baibian");

        if (level < 60 )
                zhaoshu--;

        if (level < 50 )
                zhaoshu--;

        if (level < 40 )
                zhaoshu--;

        return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
        return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
                  return action[random(sizeof(action))]["action"];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 40 )
                return notify_fail("��ľ���̫���ˣ������������ٱ䡣\n");
        me->receive_damage("jingli", 30);
        return 1;
}
