// Code of ShenZhou
//������
//Ryu 
// 16th-Aug-2000 modified by yasuko

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N���ر�צΪ�ƣ����β������ұ۶�������������һ�Ƴ�$n$l��ȥ",
        "force" : 220,
        "dodge" : 420,
        "lvl" : 0,
	"damage_type" : "����"
]),
([      "action" : "$N���Ƽ��ϣ�˫��ֱ��ֱ�£�Ʈ�����������Ŵ��һ����˫��ͬʱ�Ƴ�",
        "force" : 330,
        "dodge" : 450,
	"lvl" : 40,
	"damage_type" : "����"
]),
([	"action" : "$N˫�Ʋ�ס���趯��ֻ����������һ�����죬����һ������������$n$l��ȥ",
	"force" : 400,
        "dodge" : 420,
	"lvl" : 80,
        "damage_type" : "����"
]),
([	"action" : "$N���δ춯���������������ų�$n�������ƣ�һ�ƿ���һ�ƣ�һ������һ��",
	"force" : 450,
        "dodge" : 480,
	"lvl" : 120,
        "damage_type" : "����"
]),
([	"action" : "$Nһ����Х������Ʈ�磬����������е�ֿ���ĳ�����δ������������Ѹ���Ѽ�",
	"force" : 550,
        "dodge" : 430,
	"lvl" : 160,
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="jiuyin-zhao"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������Ʊ�����֡�\n");
	if ((int)me->query("max_neili") < 500)
		return notify_fail("�������̫�����޷��������ơ�\n");
	if (me->query("family/master_name") !="������")
		return notify_fail("������ֻ����������ѧϰ������������������\n");
        if (me->query("jiuyin/corpse_poison")>151740) {
                if (me->query("jing")<=50) return notify_fail("��ľ���״��̫���ˡ�\n");
                me->set("jing", 1);
		return notify_fail("�㷢���������Ľ������Լ������ķ�������룬��Ȼ��������֭������˿���޷���⡣\n");
        }
        if (random(me->query("jiuyin/corpse_poison"))>1681) {
                if (me->query("jing")<=300/(int)me->query("int")) return notify_fail("��ľ���״��̫���ˡ�\n");
                me->receive_damage("jing", 300/(int)me->query("int"));
		return notify_fail("�������������Ľ��⣬�ܾ�����Щ���Ծ���\n");
        }
	return 1;
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	return notify_fail("û�о����澭������������������������ơ�\n");
}
