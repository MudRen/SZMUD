// Code of ShenZhou
// qiankun-nuoyi.c Ǭ����Ų��
// by tony 97/7

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([      "action" : YEL"$n�������㣬�ڼ䲻�ݷ�֮�ʱܿ���\n"NOR,
        "dodge"  : 35
]),
([      "action" : YEL"����$n����ת����Խ��Խ�죬�����������Ƶ磬�㲻��ص���շ���һ�㡣\n"NOR,
        "dodge"  : 55
]),
([      "action" : YEL"$nʩչŲ��Ǭ���ķ���һ����Х����������ڰ��������һ��ת�ۣ�ƮȻ��������֮�⡣\n"NOR,
        "dodge"  : 75
]),
([      "action" : YEL"��Ȼ��$n���ΰ����ڿ��м�����������ת�ĸ�Ȧ�ӣ���ת���ߣ�����һ��ת�ۣ��������ɵ���������֮�⡣\n"NOR,
        "dodge"  : 100
])
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
        return (usage == "parry") || (usage == "dodge") || (usage == "finger");
}

int valid_combine(string combo) { return 1; }

string query_dodge_msg(string limb)
{
        object me;
	  int level, i;
 
        me = this_player();
	  level = me->query_skill("qiankun-nuoyi", 1) / 20;
	  if (level > sizeof(action))
		level = sizeof(action);

        return action[random(level)]["action"];
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
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
        int jing_cost, jingli_cost, neili_cost, neili_want;
        int qlvl = me->query_skill("qiankun-danuoyi", 1);
        int jlvl = me->query_skill("jiuyang-shengong", 1);
        if ( qlvl < 140 )
            return notify_fail("���������ϰ��Ǭ����Ų���ķ����������Ǭ����Ų�Ƶ��߲㹦���󣬷�����ͨ����ϰ��ߡ�\n");
        if (me->query_skill("force", 1) < 180)
            return notify_fail("��Ļ����ڹ���������������Ǭ����Ų�ơ�\n");
        neili_want = qlvl / 20 * 300 * 2 / (1 + jlvl / 100);
        if ( (int)me->query("max_neili") < neili_want )
            return notify_fail("������������ۺ�������Ǭ����Ų�ơ�\n");
        if ( (int)me->query("jingli") < 200 || (int)me->query("jing") < 200 || (int)me->query("neili") < 500 )
            return notify_fail("�������̫���ˣ���ЪϢһ�����\n");
        if ( jlvl < 100 ) jing_cost = 36000 / me->query_skill("force", 1);
        else jing_cost= 10000 / jlvl;
        jing_cost = jing_cost * qlvl / 100;
        neili_cost = jing_cost;
        jingli_cost = jing_cost;
        jing_cost = jing_cost * 20 / me->query("int");
        jingli_cost = jingli_cost * 20 / me->query("dex");
        neili_cost = neili_cost * 20 / me->query("con") / 2;
        me->receive_damage("jing", jing_cost);
        me->receive_damage("jingli", jingli_cost);
        me->add("neili", -neili_cost);
        return 1;
}
string perform_action_file(string action)
{
	return __DIR__"qiankun-nuoyi/" + action;
}
