// Code of ShenZhou
// riyue-lun.c -�����ַ�
// Summer, 10/2/96.
#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action":"$N���΢ƫ��һ�� �������ơ�������$wֱֱ�ص���$n��$l",
	"force" : 180,
        "dodge" : -5,
        "parry" : 5,
	"damage": 10,
	"lvl" : 0,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "������",
	"damage_type":"����"
]),
([	"action":"$Nһ�С���ɽ���ơ�������$w���֣������Ŷ���һ����Ȧ��Ϯ��$n������",
	"force" : 220,
        "dodge" : -5,
        "parry" : 10,
	"damage": 20,
	"lvl" : 10,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "��ɽ����",
	"damage_type":"����"
]),
([	"action":"$Nһ�С���΢�ơ����׳�����$w��ȴ��$w��δ��أ��ҽű���$w��һ������$w��$n���ɹ�ȥ����������",
	"force" : 260,
        "dodge" : -5,
        "parry" : 5,
	"damage": 35,
	"lvl" : 20,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "��΢��",
	"damage_type":"����"
]),
([	"action":"$N��������$w�����д���������һ�С������ơ�����$nӭͷ���£�һ��һ�ͣ��������죬����$n��$l",
	"force" : 300,
        "dodge" : -10,
        "parry" : 5,
	"damage": 50,
	"lvl" : 30,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "������",
	"damage_type":"����"
]),
([      "action":"$Nһ�С�Բ���ơ�������ͽ�ɣ�$w����$nͷ��ˤ�䣬$wδ��������Ю��һ�󼲷磬���ƾ���",
        "force" : 340,
        "dodge" : -10,
        "parry" : 5,
        "damage": 60,
        "lvl" : 40,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "skill_name" : "Բ����",
        "damage_type":"����"
]),
([	"action":"$N������$w��һ�ƣ�һ�С����ػ��ơ�������Բ������$n˫����ͻȻ�ִӻ����ͳ�$w����$n�����η���һƬ$wӰ��",
	"force" : 360,
        "dodge" : 0,
        "parry" : 15,
	"damage": 75,
	"lvl" : 50,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "���ػ���",
	"damage_type":"����"
]),
([	"action":"$w��$N��ǰ���ģ�����һ����⻷��$N��̤�ϣ�һ�С�׽���ơ���ֱ��$n�Ķ��š�",
	"force" : 380,
        "dodge" : -5,
        "parry" : 20,
	"damage": 85,
	"lvl" : 60,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
	"skill_name" : "׽����",
	"damage_type":"����"
]),
});

int valid_enable(string usage) { return (usage == "hammer") || (usage == "parry"); }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("longxiang-banruo", 1) < 50)
		return notify_fail("���������������Ϊ���̫ǳ��\n");
	if ( (int)me->query_skill("riyue-lun", 1) >= 30
        && (int)me->query_str() < 25 )
                return notify_fail("��ı���������\n");

	return 1;

}
mapping query_action(object me, object weapon)
{
	int i, level, force, neili;
	object ob;
	ob = me->query_temp("weapon");

        level   = (int) me->query_skill("riyue-lun",1);
        force = me->query_skill("force")/3;
        neili = me->query("neili")/30;

        // if I am performing, don't print out combat msg, and set damage
        if (me->query_temp("xueshan/riyue"))
        {
        return ([
        "action": HIW"$N���кȵ�����"+chinese_number(me->query_temp("xueshan/riyue"))+"������"NOR,
        "force" : 450+random(force),
        "dodge" : -10,
        "parry" : 20,
        "damage" : 110+random(force),
        "post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "skill_name" : "����ͬ��",
        "damage_type":"����"]);
		  }

	if ( me->query_skill_mapped("force") == "longxiang-banruo"
	&& (ob->query("name")=="����" || ob->query("name")=="����")){
	if (random(me->query_skill("hammer")) > 275 
        && me->query("neili") > 600 && ob->query_amount() >= 5){
        me->add("neili", -50);
        return ([
        "action":HIY "����һ�����죬$Nʹ����"+chinese_number(ob->query_amount())+"�ִ�ת����������ɣ����з�����ֻ$w��˫���Ը���һ�֣�һ������$n"NOR,
        "force" : 600+random(neili*3),
        "dodge" : -10,
        "parry" : 20,
        "damage" : 150+random(force*3),
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "skill_name" : "���ִ�ת",
        "damage_type":"����"]);
        }

        if (random(me->query_skill("hammer")) > 180 
        && me->query("neili") > 300  && ob->query_amount() > 1){
	me->add("neili", -30);
                return ([
                "action":HIW "$N��ֻ����"+chinese_number(ob->query_amount())+"ֻ$w�Ի����������������Ʋ�������������Ӵ�������$w���˳�ȥ"NOR,
                "damage": 120+random(force*2),
		"dodge" : -5,
		"force" : 500+random(neili*2),
		"parry" : 20,
		"lvl" : 80,
		"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
                "damage_type": "����"]);
        }

	if (random(me->query_skill("hammer")) > 150 && ob->query_amount() >= 3 
        && me->query("neili") > 200){
	return ([      
	"action":HIC "$N��������ȫ��"+chinese_number(ob->query_amount())+"ֻ$w��һʽ���Լ��项����ֱ�ɡ���б�ɡ������������׹������������ʱ��$n��ȫ����·�ѱ�����"NOR,
        "force" : 450+random(force),
        "dodge" : -5,
        "parry" : 25,
        "damage": 120+random(neili),
        "lvl" : 70,
	"post_action":  (: call_other, "/adm/daemons/weapond.c", "bash_weapon" :),
        "skill_name" : "�Լ���",
        "damage_type": "����"]);
	}
   }
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("id") != "fa lun")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ��������������ַ���\n");
	if ( (int)me->query_skill("riyue-lun", 1) >= 30
        && (int)me->query_str() < 25 )
                return notify_fail("��ı����������޷�������������ַ���\n");

	me->receive_damage("jingli", 25);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"riyue-lun/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        string msg;
        int ap, dp, damage;

        ap = me->query("combat_exp")/1000;
        ap += me->query_skill("force");
        dp = victim->query("combat_exp")/1000;
        dp += victim->query_skill("force");
        ap = (ap + random(ap*2))/2;

        msg = HIR"$N�����ս���������ڲ����������ԣ�������֮����$n��ȥ��\n"NOR;

        if( me->query_temp("longxiang") && (ap > dp) ) {
                damage *= 2;
                message_vision(msg,me,victim);
        }

	return damage;
}
