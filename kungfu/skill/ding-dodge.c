// Code of ShenZhou
// ding-dodge.c ���ֲ� 

inherit SKILL;

string *dodge_msg = ({
	"$n�������ĵ���������һ�����պñܹ�$N���������ơ�\n",
	"����$nǡ����������һ���������$N��һ�С�\n",
//	"ֻ��$nһ�С��׺׳��졹���������ϱ�ֱ���������࣬�����$N��һ�С�\n",
//	"$nһ�������ӷ���������ݳ�����֮Զ���ܿ���$N���������ơ�\n",
//	"$nʹ��������չ�᡹����һ��ƮȻ�ݳ��������ŵء�\n"
//        "����$n����Ʈ��������һ�ݣ����ѱܿ���\n",
//       "$n������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
//        "����$n����һ�ã�$N��һ�����˸��ա�\n",
//        "ȴ��$n�㲻��أ����Դܿ����ߣ����˿�ȥ��\n",
//        "$n����΢�Σ��о����յرܿ���$N��һ�С�\n"
});

int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 40 )
                return notify_fail("��ľ���̫���ˣ����������ֲ���\n");
        me->receive_damage("jingli", 30);
        return 1;
}

