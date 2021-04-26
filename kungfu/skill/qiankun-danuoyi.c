// Code of ShenZhou
// qiankun-nuoyi.c Ǭ����Ų��
// by tony 97/7

#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
          YEL"$n�������㣬�ڼ䲻�ݷ�֮�ʱܿ���\n"NOR,
          YEL"����$n����ת����Խ��Խ�죬�����������Ƶ磬�㲻��ص���շ���һ�㡣\n"NOR,
          YEL"$nʩչŲ��Ǭ���ķ���һ����Х����������ڰ��������һ��ת�ۣ�ƮȻ��������֮�⡣\n"NOR,
          YEL"��Ȼ��$n���ΰ����ڿ��м�����������ת�ĸ�Ȧ�ӣ���ת���ߣ�����һ��ת�ۣ��������ɵ���������֮�⡣\n"NOR,
});

string *parry_msg = ({
          YEL"��֪$n����΢ת��һ����͵ľ����ͳ�����$N����$n��$l��һ��ֱ���˿�ȥ��\n"NOR,
          YEL"$nŲ��Ǭ��������ǣ����$N��������;ת�˷���ʹ�˸��ա�\n"NOR,
          YEL"$n������ָ���縧�ٹ�ɪ�����������������Σ������㲻����Ƭ�̼佫$N��������������ж�ˡ�\n"NOR,
          YEL"ȴ��$N��һ�н�Ҫ��$n��$n������ָ�����$N������Ȼת�򣬴�$n���б�˹�ȥ������䲻�����磬��һ������ȫȻʹ�˸��ա�\n"NOR,
          YEL"$n��Ҳ��������$N����ʹ��������б������$N������Ų��ж�˿�ȥ��$Nֻ����������ˮ�У����ް����������\n"NOR,
});


int valid_enable(string usage)
{
        return (usage == "parry") || (usage == "dodge") || (usage == "move");
}


string query_dodge_msg()
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

string query_parry_msg(object weapon)
{
        return parry_msg[random(sizeof(parry_msg))];
}

int valid_learn(object me)
{
        return notify_fail("Ǭ����Ų��ֻ��ͨ����ϰ��Ǭ����Ų���ķ������Լ���ϰ����ߡ�\n");
}

int practice_skill(object me)
{
        int qkdny_cost;
        if (me->query_skill("qiankun-danuoyi", 1) < 100)
            return notify_fail("���Ǭ����Ų�ƹ�����������������ͨ����ϰ��Ǭ����Ų���ķ�������ߡ�\n");
        if (me->query_skill("force", 1) < 100)
            return notify_fail("��Ļ����ڹ���������������Ǭ����Ų�ơ�\n");
        if ( (int)me->query("max_neili") < 1000 )
            return notify_fail("������������ۺ�, ������Ǭ����Ų�ơ�\n");
        if ( (int)me->query("jingli") < 60 || (int)me->query("jing") < 60 || (int)me->query("neili") < 100 )
            return notify_fail("�������̫���ˣ���ЪϢһ�����\n");
        if (me->query_skill("jiuyang-shengong", 1) < 30)
           qkdny_cost = 6000 / me->query_skill("force", 1);
        else qkdny_cost = 2000 / me->query_skill("jiuyang-shengong", 1);
        me->receive_damage("jingli", qkdny_cost);
        me->receive_damage("jing", qkdny_cost);
        qkdny_cost = qkdny_cost / 2;
        me->add("neili", -qkdny_cost);
        return 1;
}
string perform_action_file(string action)
{
	return __DIR__"qiankun-danuoyi/" + action;
}
