// Code of ShenZhou
// qianzhu-wandu.c ǧ������

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : MAG "$N�������, �������˸���ʾ�, ʳָָ��$n������·Ҫ��" NOR,
	"force" : 100,
	"dodge" : 5,
	"lvl" : 0,
	"damage" : 10,
	"weapon": "ָ��",
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([      "action" : BLU "$N����ʳָ�ӵڶ�ָ����ָ���Ȼ�����ڣ�����$n$l��ȥ" NOR,
	"force" : 200,
	"dodge" : -5,
	"lvl" : 60,
	"damage" : 20,
	"weapon": "ָ��",
	"skill_name" : "�ڳ�˷�",
	"damage_type" : "����"
]),
([      "action" : YEL "$Nٿ��̤ǰ����ָ�ɷ磬����$n�ظ�֮���崦��Ѩ" NOR,
	"force" : 300,
	"dodge" : 10,
	"lvl" : 100,
	"damage" : 40,
	"weapon": "ָ��",
	"skill_name" : "���鶾��",
	"damage_type" : "����"
]),
([      "action" : CYN "$N���Ϻ�����ʢ��ָ����Ӱ��Ȼ���ţ�������ʯ�𣬴���$n��$l" NOR,
	"force" : 400,
	"dodge" : 25,
	"lvl" : 150,
	"damage" : 80,
	"weapon": "ָ��",
	"skill_name" : "���붾",
	"damage_type" : "����"
])
});

string *dodge_msg = ({
        "����$n����Ʈ��������һ�ݣ����ѱܿ���\n",
        "$n������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
        "ȴ��$n�㲻��أ����Դܿ����ߣ����˿�ȥ��\n",
});

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

string type() { return "knowledge";}

int valid_enable(string usage) { 
	return  usage=="hand" ||
		usage=="finger" || 
		usage=="parry"  ||
		usage=="dodge"  ||
		usage=="force";
}

int valid_combine(string combo) { return combo=="qianzhu-wandu"; }

int valid_learn(object me)
{
	if ((int)me->query_skill("qianzhu-wandu", 1) > 10)
		return notify_fail("ǧ������ֻ���Լ�������\n");
	return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
    int level = me->query_skill("qianzhu-wandu", 1);
    int i, j, n;

    for (n=0; n<sizeof(action); n++) {
	if (level < action[n]["lvl"]) {
	    break;
	}
    }
    i = random(n);
    j = random(n);

    if (wizardp(me))  
	tell_object(me, sprintf("lvl=%d, n=%d, i=%d, j=%d\n", level, n, i, j));
    if (i>j) return action[i];
    return action[j];
}

int practice_skill(object me)
{
	return notify_fail("ǧ�����ֲ�����ô���ġ�\n");
}

string perform_action_file(string action)
{
        return __DIR__"qianzhu-wandu/" + action;
}

string exert_action_file(string action)
{
	notify_fail("getting qzwd.heal ");
        return __DIR__"qianzhu-wandu/" + action;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    if( random(me->query_skill("qianzhu-wandu", 1)) > 10 ) {
	victim->apply_condition("qianzhu-poison", 
	    me->query_skill("qianzhu-wandu", 1)/10 + 
		victim->query_condition("qianzhu-poison"));
        if(victim->query("poisoner") != me)	victim->set("poisoner", me);
    }
}

void skill_improved(object me)
{
  int level = me->query_skill("qianzhu-wandu",1);
  int o_lvl = me->query("qianzhu-wandu/old_lvl");
 
  if ( o_lvl < level && level > 100) {
      if ( level%10 == 1) {
	if (me->query("per") > 0) {
	    tell_object(me, 
	        "��������ڵ�ǧ�붾�����ڲ�ֹ�������ϸ����ּ����ˡ�\n");
	    me->add("per", -1);
	}
        me->set("qianzhu-wandu/old_lvl", level);
      }
  }
}
