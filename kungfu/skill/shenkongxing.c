// Code of ShenZhou
// shenkongxing, ����С�
// Ryu, 11/14/96.

inherit SKILL;

string *dodge_msg = ({
	"$nĬ���ŭ�䣬һʽ�����Կա���һ�����$Nͷ��һ������������$P���\n",
	"$n�������ˣ�������ң��Ųȡ����ա�������$N��Ҹ�´���$P���ᣬ�ƹ�$N��һ�С�\n",
	"$n΢Ц����������������һ�٣�һʽ���󰲿ա������ȳ�����һ����$Nһ�л��ڿմ���\n",
	"$nһʽ����ա�������һ�࣬�Ų�����һ̤��$N�Ľ���һ��ʧȥ�˷���������������Ρ�\n",
	"$n����������˫����$N����һ����һʽ����տա�Ծ�����ߣ�ƮȻ�䵽һ�ԡ�\n",
	"$nһʽ���Ŀա��������������ޡ��������֣�$N��һ���ƺ�����$n���ƺ��ִ��ڿմ����벻������\n",
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
                return notify_fail("��ľ���̫���ˣ�����������С�\n");
        me->receive_damage("jingli", 30);
        return 1;
}

