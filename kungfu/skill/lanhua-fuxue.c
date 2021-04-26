// Code of ShenZhou

//lanhuafuxue-shou.c
//kane 05/9/97  

#include <combat.h>
#include <ansi.h>

inherit SKILL;
inherit F_DBASE;
inherit F_SSERVER;

string* xuedao = ({
        "�޹�Ѩ",
        "�ز�Ѩ",
        "�羮Ѩ",
        "�ճ�Ѩ",
        "����Ѩ",
        "���Ѩ",
        "����Ѩ",
        "�縮Ѩ",
        "����Ѩ",
        "�յ�Ѩ",
        "ǿ��Ѩ",
        "�ٺ�Ѩ",
        "����Ѩ",
        "����Ѩ",
        "����Ѩ",
        "��׵Ѩ",
        "̫��Ѩ",
        "����Ѩ",
        "����Ѩ",
        "�βѨ",
        "������",
        "����Ѩ"
});

mapping *action = ({
([      "action" :"$N��������ǰһ����ʹ��һ�С������Ƶ��������ֻӳ���ʳָ��Ĵָ����������ָ���ţ����������������������$n������Ѩ��",
        "force" : 130,
        "dodge" : 10, 
        "parry" : 5, 
        "damage": 10,
        "lvl" : 0,
        "skill_name" : "�����Ƶ�",
        "damage_type" : "����"
]),
([      "action" :"$N������ת��һʽ�����Ʊ��¡�����������$n��$l������������֮�Σ�Сָ������ָ���赭д�ط���$n������������Ѩ",
        "force" : 180,
        "dodge" : 15, 
        "parry" : 5, 
        "damage": 20,
        "lvl" : 10,
        "skill_name" : "���Ʊ���",
        "damage_type" : "����"
]),
([      "action" :"$Nʹ��һ�С����������������ֻӳ�����ָ΢�ţ���ס$n����������Ѩ����Ȼ�����������ѵ�ˮ�����������$n����̫��Ѩ",
        "force" : 220,
        "dodge" : 25, 
        "parry" : 5, 
        "damage": 25,
        "lvl" : 15,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" :"$N�������ǲ����紩���������Ƶ�$n��󣬿���������ʹ��һ�С�����ŪӰ�������ַ���$n��׵��������Ѩ�������������ޣ��˵İ����޷�",
        "force" : 280,
        "dodge" : 30, 
        "parry" : 5, 
        "damage": 25,
        "lvl" : 30,
        "skill_name" : "����ŪӰ",
        "damage_type" : "����"
]),
([      "action" :"$Nǰ��һ����˫�������һ�С��������塹��������Сָ����$nҸ�׼�ȪѨ����ָ����羮Ѩ��Ĵָ�����Ϲ�Ѩ��ɲ�Ǽ���Ϯ$n������Ѩ",
        "force" : 350,
        "dodge" : 30, 
        "parry" : 10, 
        "damage": 35,
        "lvl" : 40,
        "skill_name" : "��������",
        "damage_type" : "����"
]),
([      "action" :"$N����չ��������Ƶ�$n���棬ʹ��һʽ�������뷼����˫�ֲ���������������ˮ�����$n������Ѩ��������ӰӰ�´���ס$n������Ѩ",
        "force" : 380,
        "dodge" : 40, 
        "parry" : 10, 
        "damage": 50,
        "lvl" : 50,
        "skill_name" : "�����뷼",
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
/*
int valid_combine(string combo)
{
        object me = this_player();
        if( me->query("gender") == "Ů��" )
                return combo=="luoying-shenjian";
}
*/
int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��������Ѩ�ֱ�����֡�\n");
        if ((int)me->query_skill("bitao-xuangong", 1) < 20)
           return notify_fail("��ı���������򲻹����޷�ѧ������Ѩ�֡�\n");
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
        int i, level, bt, dp;
	object victim;
	string xue, *msg;

	if( !victim && me->is_fighting() ) victim = offensive_target(me);
        level  = (int) me->query_skill("lanhua-fuxue",1);
        bt  = (int) me->query_skill("bitao-xuangong",1);
	dp = (int) victim->query_skill("dodge",1);
	xue = xuedao[random(sizeof(xuedao))];


	if(me->query_temp("luoying_lanhua"))
	{
	me->prepare_skill("hand");
	me->prepare_skill("strike", "luoying-shenjian");
	COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
	me->prepare_skill("strike");
	me->prepare_skill("hand", "lanhua-fuxue");
	}

	msg = 
	({
		HIG"$N������ӣ���$n�Ʊ�������Ѩ���Ϸ�ȥ����һ������Ʈ�ݣ���Ѩ��׼��ʵ�Ƿ�ͬС�ɣ�"NOR,
		HIC"ͻȻ��$N����б�ӣ��������$n�󾱡��춦�����޹ǡ���Ѩ���������ᣬ�����˾��������ޣ�����$n�������⡰С��Ѩ����"NOR,
		HIW"����$Nһֻѩ�׵�������ָ�ֿ���������������̬�������ԣ��������ţ��������ݵط���$n��"+xue+"��"NOR,
		HIC"$N����Сָ�����������һʽ���п�ݣ���Ѩ��׼��ȴ�������赭д����������"NOR,
	});

	if( me->query_temp("fuxue") && random(4) == 0 )
	{
		victim->delete_temp("xue");
		victim->set_temp("xue",xue);

		return ([
		"action": msg[random(sizeof(msg))],
		"force" : 400+random(40),
		"dodge" : 20,
		"damage": 50+random(20),
		"damage_type" : "����" ]);
	}

	else if ( !me->query_temp("luoying_lanhua") 
	&& level > random(level+400) && me->query("neili") > 300 
	&& me->query("combat_exp") > random(victim->query("combat_exp")*2) 
	&& !victim->is_busy() ) {
                me->add("neili", -20);
                message_vision(HIC"\n$N��ȻһЦ��������������ި��������֣�����ʵ�죬���ػ������$n��"+xue+"������ÿ졢׼���桢������Ҫ����\n"NOR,me,victim);
        	message_vision(GRN"$N΢һ���񣬱��������ţ�ֻ����"+xue+"��һ�����飬�ж�����ٻ�������\n"NOR,victim);
		victim->start_busy(1 + random(level/50));
	}

        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}


int practice_skill(object me)
{
        if ((int)me->query("jingli") < 50)
                return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 50)
                return notify_fail("�������̫���ˡ�\n");
        me->receive_damage("jingli", 15);
	me->add("neili", -5);
       
       return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali;
        level = (int) me->query_skill("lanhua-fuxue",1);
	jiali = me->query("jiali");
        if( me->query_temp("fuxue")  ) {
	victim->start_busy(level/100 +random(jiali/100+1));
	victim->add("neili", -(30 + jiali/2));
        me->interrupt_me();
	return "$n΢һ���񣬱��������ţ�ֻ����"+victim->query_temp("xue")+"��һ�����飬�ж�����ٻ�������\n";
        }
}

string perform_action_file(string action)
{
	return __DIR__"lanhua-fuxue/" + action;
}
