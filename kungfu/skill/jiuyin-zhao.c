// Code of ShenZhou
// jiuyin-zhua.c -�����׹�צ
// xbc: 02/02/1997 modifyied by xuy
// 16th-Aug-2000 modified by yasuko
// haowen 10/10/00 change learn limit below 40 to fix skin bug

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N˫��΢�ţ�ʮ������ָ��ӳ���Ұ׹�â��ͻȻ�����צ����ָ�͵ز���",
	"force" : 280,
        "dodge" : 470,
	"lvl" : 0,
	"weapon": "�����ָ",
	"damage_type" : "����"
]),
([	"action" : "$N����ͻȻ��$n��ǰ��Χ�¹���������ת���������߰˰㣬���������һ�죬�����ֱָ��$n$l",
	"force" : 320,
        "dodge" : 460,
	"lvl" : 40,
	"weapon": "�����ָ",
        "damage_type" : "����"
]),
([	"action" : "������������һ�죬$N���ֱ۶�Ȼ���˰�ߣ�һ�ư���$n$l����ָ��Ҫ���",
	"force" : 480,
        "dodge" : 450,
	"lvl" : 80,
	"weapon": "�����ָ",
        "damage_type" : "����"
]),
([	"action" : "ͻȻ��Ӱ������$N�ѷ����ȵ�$n���̽�ֳ��䣬��ָ���ţ�����$n$l��ȥ",
	"force" : 500,
        "dodge" : 480,
	"lvl" : 120,
	"weapon": "�����ָ",
        "damage_type" : "����"
]),
([	"action" : "ֻ��$Nһ����߳�����־���$n$lץȥ����������ײ��$n�ؿ�Ѩ�������ֻ��ţ���ָ����������$nͷ��",
	"force" : 600,
        "dodge" : 500,
	"lvl" : 160,
	"weapon": "�����ָ",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }

int valid_combine(string combo) { return combo=="cuixin-zhang"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("�������׹�צ������֡�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷��������׹�צ��\n");
	if
((me->query("family/master_name") !="������")&&(me->query_skill("jiuyin-zhao",1) >
40))
		return notify_fail("�����׹�צֻ����������ѧϰ������������������\n");
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
	return notify_fail("û�о����澭������������������������׹�צ��\n");
}
string perform_action_file(string action)
{
        return __DIR__"jiuyin-zhao/" + action;
}
