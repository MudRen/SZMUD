//Cracked by Roath
// mofu-wuzong.c -ħ������
// written by Dong 4/12/97

inherit SKILL;

string *dodge_msg = ({
        "ֻ��$nһ�С�������֦�����ڿն������嵹�ң������$N��һ�С�\n",
        "$n˫��������һ�죬��ǰһ����һ�С�����չ������������Ʈ�������$N�Ĺ�����\n",
        "$n������������һ�ģ�һ���������ڿա����������ҵ�����Ʈ��$N��֪����η�ֻ���ջ����ơ�\n",
        "$n���˷�����һ�С�������Ӱ���ƹ�$N�Ĺ��ƣ�Ʈ��$N�����ᡣ\n",
//        "$n��ҹ���̿ա�\n",
//        "$n��ҹ���̿ա�\n",
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
                return notify_fail("��ľ���̫���ˣ�������ħ�����١�\n");
        me->receive_damage("jingli", 30);
        return 1;
}
