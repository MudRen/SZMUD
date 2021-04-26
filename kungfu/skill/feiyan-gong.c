//Code by Scatter
//V 2.0
//feiyan-gong(���๦)

inherit SKILL;

mapping *action = ({
([      "action" : "$n����һ�ݣ�Ծ�ڰ�գ��ڿ��з���һ����һ�С�����Ͷ�֡���ƮȻ����$N���\n",
        "dodge"  : 10,
        "skill_name" : "����Ͷ��"
]),
([      "action" : "ͻȻ$n��Хһ��������һԾ���ڿշ�������һʽ����ŮͶ�󡹣������ܿ�$N�Ĺ�����\n",
        "dodge"  : 20,
        "skill_name" : "��ŮͶ��"
]),
([      "action" : "$nһʽ������׹¥�����������ػ��У�����˷�����˼���ۼ�$N�Ĺ�����Ȼ�˿ա�\n",
        "dodge"  : 30,
        "skill_name" : "����׹¥"
]),
([      "action" : "ֻ��$n�����Ծ�������һ��һת������һʽ��������������$N����ʽ�����㿪��\n",
        "dodge"  : 40,
        "skill_name" : "��������"
]),
([      "action" : "$n����ƮȻ����ʹ��һ�С�����Ӱ��������ƮƮ����̬���ݣ�����$N�����Ĺ�����\n",
        "dodge"  : 50,
        "skill_name" : "����Ӱ"
]),
([      "action" : "$nһʽ�����۳�������Ȼ�����ΰ���ֱ��������ֱ��ӥ����������������������֮�⡣\n",
        "dodge"  : 60,
        "skill_name" : "���۳�"
]),
([      "action" : "$nһʽ�����۳�������Ȼ�����ΰ���ֱ��������ֱ��ӥ����������������������֮�⡣\n",
        "dodge"  : 70,
        "skill_name" : "���۳�"
]),
([      "action" : "$nһʽ�����۳�������Ȼ�����ΰ���ֱ��������ֱ��ӥ����������������������֮�⡣\n",
        "dodge"  : 80,
        "skill_name" : "���۳�"
])
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("feiyan-gong");

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
                return notify_fail("��ľ���̫���ˣ����������๦��\n");
        me->receive_damage("jingli", 30);
        return 1;
}
