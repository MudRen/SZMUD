// Code of ShenZhou
// xueshan-shenfa.c ѩshitiao
// qfy, chage, paoshou, Mongol Sept 27, 1996.

inherit SKILL;

string *dodge_msg = ({
	"$nһʽ������ѩ�ڡ���һ�»������⿪ȥ����$N���ƻ�����Ρ�\n",
	"$nʹ������ʨ���衹��һ�����$Nͷ��һ��������$N��$n���š�\n",
	"$n�Ų���ȣ�������ң�ʹ����ѩ��ƺӡ���$N��Ҹ�´���$P���ᡣ\n",
	"$n΢Ц����������������һ�٣�һʽ����ѩ���Ρ����$N��һ����\n",
	"$n��ת���ӣ�����һԾ��һʽ��ʨ��ҡͷ�����赭д�ػ���$N��һ�С�\n",
	"$n��������һ�ݣ�ʹ��һʽ��̤ѩ�޺ۡ�Ծ�����ߣ�ƮȻ�䵽һ�ԡ�\n",
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
                return notify_fail("��ľ���̫���ˣ�������ѩʨ����\n");
        me->receive_damage("jingli", 30);
        return 1;
}

