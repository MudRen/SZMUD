// Code of ShenZhou
// jinshe-zhuifa ����׶��
// qfy September 18, 1996

#include <ansi.h>
inherit SKILL;
string type() { return "base_skill"; }
string* xuedao = ({
        "�İ�Ѩ",
        "�ز�Ѩ",
        "��ӭѨ",
        "Ͽ��Ѩ",
        "ͷάѨ",
        "�¹�Ѩ",
        "����Ѩ",
        "̫��Ѩ",
        "����Ѩ",
        "�ػ�Ѩ",
	"�ٳ�Ѩ",
        "�ٺ�Ѩ",
        "ͨ��Ѩ",
        "����Ѩ",
        "ӡ��Ѩ",
        "����Ѩ",
        "��ҺѨ",
        "����Ѩ",
        "����Ѩ",
        "�ٻ�Ѩ",
        "��̨Ѩ",
        "̫��Ѩ",
        "����Ѩ",
        "����Ѩ",
        "�βѨ",
        "����Ѩ"
});

mapping *action1 = ({
([	"action":"$N����һö$w����׼$nһ���֣���$w��ֱ����$n��"+xuedao[random(sizeof(xuedao))],
	"force" : 120,
        "dodge" : 20,
	"damage": 20,
	"number": -1,
	"lvl" : 0,
]),
([	"action":"$N˫�����ӣ���ö$w���ź�Х���������ɶ�������$n��"+xuedao[random(sizeof(xuedao))]+"��"+xuedao[random(sizeof(xuedao))],
	"force" : 180,
        "dodge" : 30,
	"damage": 40,
	"number": -2,
	"lvl" : 5,
]),
([	"action":"$N����Ծ�𣬾Ӹ�������$n������ö$w��ֱȡ$n��˫Ŀ��"+xuedao[random(sizeof(xuedao))],
	"force" : 220,
        "dodge" : 30,
	"damage": 60,
	"number": -3,
	"lvl" : 15,
]),
([	"action":"ͻȻ$N��ͷ����ֻ���á�ಡ���һ����һö$w�ɺ���ɳ�����$n��"+xuedao[random(sizeof(xuedao))]+"�����ȥ",
	"force" : 260,
        "dodge" : 15,
	"damage": 40,
	"number": -1,
	"lvl" : 25,
]),
([	"action":"����$N��˫��£�����У�������Ϣ�ط���һö$w��б�䵽$n��"+xuedao[random(sizeof(xuedao))]+"��Ѹ���ޱ�",
	"force" : 300,
        "dodge" : 25,
	"damage": 50,
	"number": -1,
	"lvl" : 35,
]),
([      "action":"$NһЦ���ˣ�����ȴ������һ�ģ���ö$w����ǰ��Ȼ�������ȡ$n���ʺ�"+xuedao[random(sizeof(xuedao))],
        "force" : 340,
        "dodge" : 30,
        "damage": 70,
        "number": -2,
        "lvl" : 45,

]),
([      "action":"$N˫��ͬ�ӷ�����ö$w����$n˫Ŀ���ſ�һ������һö$w���������ϵس�Խǰ��ö$w������������$n��"+xuedao[random(sizeof(xuedao))],
	"force" : 380,
        "dodge" : 30,
        "damage": 85,
        "number": -3,
        "lvl" : 45,
]),
});

mapping *action2 = ({
([      "action":"$N����һö$w����׼$nһ���֣���$w��ֱ����$n��"+xuedao[random(sizeof(xuedao))],
        "force" : 120,
        "dodge" : 20,
        "damage": 20,
        "number": -1,
        "lvl" : 0,
]),
([      "action":"$N˫�����ӣ���ö$w���ź�Х���������ɶ�������$n��"+xuedao[random(sizeof(xuedao))]+"��"+xuedao[random(sizeof(xuedao))],
        "force" : 180,
        "dodge" : 30,
        "damage": 40,
        "number": -2,
        "lvl" : 5,
]),
([      "action":"ͻȻ$N��ͷ����ֻ���á�ಡ���һ����һö$w�ɺ���ɳ�����$n��"+xuedao[random(sizeof(xuedao))]+"�����ȥ",
        "force" : 260,
        "dodge" : 15,
        "damage": 40,
        "number": -1,
]),
([      "action":"����$N��˫��£�����У�������Ϣ�ط���һö$w��б�䵽$n��"+xuedao[random(sizeof(xuedao))]+"��Ѹ���ޱ�",
        "force" : 300,
        "dodge" : 25,
        "damage": 50,
        "number": -1,
        "lvl" : 35,
]),
([      "action":"$NһЦ���ˣ�����ȴ������һ�ģ���ö$w����ǰ��Ȼ�������ȡ$n���ʺ�"+xuedao[random(sizeof(xuedao))],
        "force" : 340,
        "dodge" : 30,
        "damage": 70,
        "number": -2,
        "lvl" : 45,
]),
});

mapping *action3= ({
([      "action":"$N����һö$w����׼$nһ���֣���$w��ֱ����$n��"+xuedao[random(sizeof(xuedao))],
        "force" : 120,
        "dodge" : 20,
        "damage": 20,
        "number": -1,
        "lvl" : 0,
]),
([      "action":"ͻȻ$N��ͷ����ֻ���á�ಡ���һ����һö$w�ɺ���ɳ�����$n��"+xuedao[random(sizeof(xuedao))]+"�����ȥ",
        "force" : 260,
        "dodge" : 15,
        "damage": 40,
        "number": -1,
]),
([      "action":"����$N��˫��£�����У�������Ϣ�ط���һö$w��б�䵽$n��"+xuedao[random(sizeof(xuedao))]+"��Ѹ���ޱ�",
        "force" : 300,
        "dodge" : 25,
        "damage": 50,
        "number": -1,
        "lvl" : 35,
]),
});

int valid_enable(string usage) { return usage == "throwing" ; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");

	if ((int)me->query_skill("force") < 50)
		return notify_fail("����ڹ����̫ǳ��\n");

	if ((int)me->query_int() < 30)
		return notify_fail("������Բ������޷��������׶����\n");

        if ((int)me->query_con() < 20)
                return notify_fail("��ĸ��ǲ������޷�������׶����\n");

	if (!present("jinshe miji", me)) 
                return notify_fail("��ϰ����׶������һ���ж��������ܼ�����\n");

	return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
	mapping act;

	level   = (int) me->query_skill("jinshe-zhuifa",1);

	if ( weapon->query_amount() >= 3 ) {
           for(i = sizeof(action1); i > 0; i--) {
                if(level > action1[i-1]["lvl"]) {
			act = action1[NewRandom(i, 20, level/5)];
			if (weapon->query_amount()==3 && (int)act["number"]==-3) {
				weapon->unequip();
				tell_object(me, HIR "���"+weapon->name()+"�ù��ˣ�\n" NOR);
			}
			weapon->add_amount(act["number"]);
                        return act;
		}
	    }
	}

	if ( weapon->query_amount() >= 2 ) {
	   for(i = sizeof(action2); i > 0; i--) {
		if(level > action2[i-1]["lvl"]) {
			act = action2[NewRandom(i, 20, level/5)];
			if (weapon->query_amount()==2 && (int)act["number"]==-2) {
				weapon->unequip(); 
				tell_object(me, HIR "���"+weapon->name()+"�ù��ˣ�\n" NOR);
			}
                        weapon->add_amount(act["number"]);
                        return act;
                }
	    }
	}

	for(i = sizeof(action3); i > 0; i--) {
           if (level > action3[i-1]["lvl"]) {
			weapon->unequip();
                        weapon->add_amount(-1);
			tell_object(me, HIR "���"+weapon->name()+"�ù��ˣ�\n" NOR);
			return action3[NewRandom(i, 20, level/5)];
	   }
	}
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ�������������׶����\n");
	me->receive_damage("jingli", 25, "����͸֧��������");
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"jinshe-zhuifa/" + action;
}
