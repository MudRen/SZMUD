// Code of ShenZhou
inherit SKILL;

string *dodge_msg = ({
"$nһʽ�����������ɢ�󡹣������������̾һ����ƮȻ�˺�\n",
"$nһʽ�����к�����Ѱ������$Nֻ����ǰһ����һ��֮�£�$n����ת���������\n",
"$n�ƽ�ʵ�ˣ����赭д�رܿ�����һ�У����ǡ����������޹��⡹��\n",
"$nʹһ�С��۵���÷�����䡹������һƫ��$N�ƺ��ŵ�һ���������޵�������\n",
"$n΢΢һЦ��һʽ��С�����������������$N����б�Ӷ�����\n",      
"$n���ּ���֮ɫ������΢�ӣ�һʽ��������������꡹���˿�ȥ��\n"
"$n���ּ���֮ɫ������΢�ӣ�һʽ�����³ɿա���һ��һ����$N�Ĺ��ƶ������˿մ���\n"
});

int valid_enable(string usage) { return (usage == "dodge") || (usage ==
"move"); }

int valid_learn(object me) { return 1; }
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 40 )
                return notify_fail("��ľ���̫���ˣ���������ʫ����\n");
        me->receive_damage("jingli", 30);
        return 1;
}

