//Cracked by Roath
// liuxingbu ���ǲ�

inherit SKILL;

string *dodge_msg = ({
        "ֻ��$nһʽ�������հ���������ת�������ڿն��𣬶����$N��һ�С�\n",
	  "$n����б�ɶ���һʽ���������ǡ��ܹ���$N��һ�С�\n",
	  "$nһʽ��ǧ�ﲻ���С��ܹ�$N�Ĺ��ƣ�����$N������һ�㣬Ʈ�����ɡ�\n",
	  "$nһת��˫�������ĳ�������һ�С����˷���ȥ���㿪$N��һ�С�\n", 
	  "$n����������һ�ɣ���һ��һ�С�������������������ػ����㿪$N����һ�С�\n",
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
                return notify_fail("��ľ���̫���ˣ������������Ρ�\n");
        me->receive_damage("jingli", 30);
        return 1;
}
