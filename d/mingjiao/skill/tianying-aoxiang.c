// Code of ShenZhou
// tianying-aoxiang.c ��ӥ����

inherit SKILL;

string *dodge_msg = ({
        "ֻ��$nʹ����ӥ���裬�����$N��һ�С�\n",
});

int valid_enable(string usage) 
{ 
	return (usage == "dodge"); 
}

int valid_learn(object me) 
{ 
	return 1; 
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 40 )
                return notify_fail("��ľ���̫���ˣ���������ӥ���衣\n");
        me->receive_damage("jingli", 30);
        return 1;
}
