// Code of ShenZhou
// lingbo-weibu.c �貨΢��
// AceP, Xuy

inherit SKILL;

mapping *action = ({
([	"action" : "����$n����������̤�����ڡ�����ת�����롱��$N��ʽ�������԰�$nΧס����\n֪���ģ�$n����Ȱ�Ŀ��Ȧ�⡣\n",
	"dodge"  : 10
]),
([	"action" : "$n�����򶫿��������̤ʵ֮ʱ�����������������ϣ�����$N����ʽѸ����ף�\n��Ȼ������գ�\n",
	"dodge"  : 20
]),
([	"action" : "$n�Թ��Ե�̤�����������$N�Ĺ�����ÿһ����̤�ڱ����벻���ĵط������ü�\n����������$N�ı���\n",
	"dodge"  : 30
]),
([	"action" : "$n����΢�Σ�����Ʈ�磬�����Ź�֮�����ԡ�ԥλ�����ϡ���λ����������˼��\n�ܿ���$N����һ�С�\n",
	"dodge"  : 40
]),
([	"action" : "$n����һ�����ģ���������б���벽����̤�����ڡ�����ת����λ���������·���\nȴ�ڼ䲻�ݷ��Ŀ�϶�бܹ���$N����ʽ��\n",
	"dodge"  : 50
]),
([	"action" : "$n����һ�ã�̤�����ڡ���ת����λ����հ֮��ǰ�������ں�$N�����������$n\n�������֮�Ȼ��ȴ���ǲ�����һ�ǰ�㣬��һ���С�\n",
	"dodge"  : 60
]),
([	"action" : "$n��Ȼ����˫�ۣ�����ͥɢ��һ�����ߣ���$N����ʽȦ���������䣬������б��\n$N��$n���´�Ҳɨ����һƬ��\n",
	"dodge"  : 70
]),
([	"action" : "$n�㲻��أ�ƮȻ���ߣ���һ�ϡ���һб����������һ�㣬��$N��ʽ�ķ�϶֮��\nӲ�����ؼ��˹�ȥ��\n",
	"dodge"  : 80
]),
([	"action" : "$n�������ģ�������������ÿһ����̤�����벻����λ���ϣ��ն����յذ�$N��\n��ʽ���������\n",
	"dodge"  : 90
]),
([	"action" : "$n���΢Ц����������翣�������У�$Nһ��������ǰ��ȴ����$nƮ�ڰ��˳��\n������������ң���ɣ�\n",
	"dodge"  : 100
]),
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("lingbo-weibu");

	if (level < 120 )
		zhaoshu -= (119-level)/20;

	return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
	return usage == "dodge";
}

int valid_learn(object me)
{
	return 1;
}

string query_dodge_msg(string limb)
{
// The following codes are buggy, because "me" is the attacker instead
// of defender.
/*	object me, ob;
	mapping action;

	me = this_player();
	action = query_action(me, ob);

	return action["action"];
*/
        return action[random(sizeof(action))]["action"];

}

int practice_skill(object me)
{
	if ((int)me->query("neili") < 20)
		return notify_fail("�������̫���ˣ��������貨΢����\n");
	me->add("neili", -50);
	me->add("jingli", -50);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"lingbo-weibu/" + action;
}

