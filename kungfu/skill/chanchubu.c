// Code of ShenZhou
//��ܲ���
//Jay 10/7/96

inherit SKILL;

string *dodge_msg = ({
	"$n���ɡ���һ����һʽ������˳桹��һ�±ĵ�һ�ߣ��ܿ���$N�ķ�â��\n",
	"$nʹ�����ɾ��졹��˫���ش�$Nͷ��һ��������\n",
	"$nһ�С����뵾���$N��Ҹ�´���$P���ᡣ\n",
	"$n�������ɡ������������á��������졹����$N�����񣬶��$N�Ĺ�����\n",
	"$n�������һ�ɣ�һʽ��󸷭�׶ǡ����$N��һ�С�\n",
	"$n����һ�ݣ�ʹ���������¡�Ծ�����ߣ�ƮȻ�䵽һ�ԡ�\n",
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
                return notify_fail("��ľ���̫���ˣ���������ܲ�����\n");
        me->receive_damage("jingli", 30);
        return 1;
}

