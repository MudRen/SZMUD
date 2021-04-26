// Code of ShenZhou
// yuxiao-jian.c
//kane 22/5/97  
//maco 12/30/99
// FunBoo @sz 6/28/2002 auto dianxue with xiao

#include <ansi.h>

inherit SKILL;
inherit F_DBASE;
inherit F_SSERVER;

nomask int parry_available() { return 1; }

// Use to determind auto dianxue success or not, if no xiao, no auto dianxue
// s_Attack_Type mean it is a finger attack or sword attack, since return message is not the same
#include "/kungfu/skill/th_jianzhi_auto_dianxue_success_calculation.h";

// Ѩ�� array
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
	"��βѨ",
	"����Ѩ",
	"�͹�Ѩ",
	"�ٻ�Ѩ",
	"��̨Ѩ",
	"̫��Ѩ",
	"����Ѩ",
	"����Ѩ",
	"�βѨ",
	"������",
	"����Ѩ"
});

string *parry_msg = ({
	"ȴ��$n����΢ת�����赭д����$W���ᵲ��$w���ڴ�δ����ߣ�������δ��Ƭ��ͣ�͡�\n",
});


string query_parry_msg(object weapon, object victim)
{
	object ob;

	if (!objectp(ob = victim->query_temp("weapon"))
	|| !victim->query_temp("exercise/playing"))
		return SKILL_D("parry")->query_parry_msg(weapon);
	else
		return replace_string(parry_msg[random(sizeof(parry_msg))], "$W", ob->name());
}

mapping *action = ({
([      "action" : "$N����һ��������$wһ��ʹ��һ�С�ɽ����������Ȧת����$w��������������Ȼ����һ����$w���ã���۵�ֿ�㼲��$n��$l",
	"force" : 100,
	"dodge" : 10,
	"parry" : -15,
	"damage": 20,
	"lvl" : 0,
	"skill_name" : "ɽ������",
	"damage_type" : "����"
]),
([      "action" : "$N$wһ�ᣬʹ��һʽ���������񡹣����潣�ߣ�Ԣ���ڹ�����$n����ʽ���ǲ������ܣ���ֱ����$n��$l",
	"force" : 120,
	"dodge" : -10,
	"parry" : 15,
	"damage": 30,
	"lvl" : 5,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([      "action" : "$N����$w�������裬ʹ��һ�С����¥̨��������һ���̳�����;��������ü�����λ������$n��$l",
	"force" : 140,
	"dodge" : 10,
	"parry" : -5,
	"damage": 25,
	"lvl" : 10,
	"skill_name" : "���¥̨",
	"damage_type" : "����"
]),
([      "action" : "$N����$w��Ȼһ����ʹ��һ�С����亮������$w�����°�ɻ�Ȧת��ٿ��һչ�����ʯ������$n��$l",
	"force" : 170,
	"dodge" : 5,
	"parry" : -10,
	"damage": 35,
	"lvl" : 10,
	"skill_name" : "���亮��",
	"damage_type" : "����"
]),
([      "action" : "$Nͦ����$w����$n���̴̵�������һ�С�������������������˸������΢��������$w��������֮��������$n�������Ѩ",
	"force" : 190,
	"dodge" : -10,
	"parry" : -5,
	"damage": 40,
	"lvl" : 15,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([      "action" : "$N����һ����˳��ʹ��һ�С�����ˮ�ơ����������࣬�������磬����һմ���ߣ������������裬ƮȻ����$n��$l",
	"force" : 210,
	"dodge" : 20,
	"parry" : -5,
	"damage": 45,
	"lvl" : 20,
	"skill_name" : "����ˮ��",
	"damage_type" : "����"
]),
([      "action" : "$N��ָ��$w��һ�����һ�����죬һ�С�������������$w�й�ֱ��������˿�����ɣ�������ǰ�Ĵ���$n��$l",
	"force" : 230,
	"dodge" : 0,
	"parry" : 45,
	"damage": 55,
	"lvl" : 20,
	"skill_name" : "��������",
	"damage_type" : "����"
]),
([      "action" : "$N����չ����ʹ��һʽ����ʷ������������$w��ز���裬�������ƿ�һ�㣬����$n��$l����̬Ʈ�ݣ���������",
	"force" : 250,
	"dodge" : 10,
	"parry" : 0,
	"damage": 45,
	"lvl" : 25,
	"skill_name" : "��ʷ����",
	"damage_type" : "����"
]),
([      "action" : "$N����һ�䣬���μ������ˣ�һʽ���ɻ���䡹������ɭɭ�����������컨��һ�㣬������˷�����������ʵ�����˱��޿ɱ�",
	"force" : 280,
	"dodge" : 0,
	"parry" : 10,
	"damage": 50,
	"lvl" : 30,
	"skill_name" : "�ɻ����",
	"damage_type" : "����"
]),
([      "action" : "$N��̤������Է�λ���������֣�����ʹ��һ�С������˪��������$wбָ������$n����������ʵʵ��Ӧ�����ң���ͨ��������ྶͥ",
	"force" : 300,
	"dodge" : -5,
	"parry" : 5,
	"damage": 50,
	"lvl" : 35,
	"skill_name" : "�����˪",
	"damage_type" : "����"
]),
([      "action" : "$N����$w�ɻ���һ�С���©��������������$n��ȥ���䲻��������ȴռ���Ȼ�����$n�������߷�Բ֮�ؾ�����ס",
	"force" : 320,
	"dodge" : 0,
	"parry" : 5,
	"damage": 55,
	"lvl" : 40,
	"skill_name" : "��©������",
	"damage_type" : "����"
]),
([      "action" : "$N�Ų��������ģ�������ҡҡ��׹��ʵ����ȾŹ���һ�С����������ѡ�������ƽƽ�������������޵ش���$n��$l",
	"force" : 350,
	"dodge" : 0,
	"parry" : 5,
	"damage": 65,
	"lvl" : 45,
	"skill_name" : "����������",
	"damage_type" : "����"
]),
([      "action" : "$N�Ʋ����Σ�һ�С���ɽ��ס���$w���ַɳ�������$n��$l������ʹ������׽Ӱ��������������$w���ù�������ָΪ��������$n",
	"force" : 380,
	"dodge" : 10,
	"parry" : -10,
	"damage": 75,
	"lvl" : 50,
	"skill_name" : "��ɽ���",
	"damage_type" : "����"
]),
([      "action" : "$Nһ����Х������ԴԴ����ע�뽣��������â��ʢ��һʽ������ֹϢ��������������һ��ƥ��Ҳ�ƵĽ���Ю��ɭɭ�����ƿն���������ӵ�к����ȻĪ��",
	"force" : 400,
	"dodge" : -10,
	"parry" : -20,
	"damage": 120,
	"lvl" : 60,
	"skill_name" : "����ֹϢ",
	"damage_type" : "����"
]),
([      "action" : "$N�Ųȷ�����ʮ���Է�λ�����Ƽӿ죬ʹ��һ�С��Ǻ�ǧ���衹��ֻ��һƬãã�����У�������ɫ��Ȧ��ӿ���������֮��$n��û�뽣��֮��",
	"force" : 420,
	"dodge" : 10,
	"parry" : 10,
	"damage": 95,
	"lvl" : 70,
	"skill_name" : "�Ǻ�ǧ����",
	"damage_type" : "����"
]),
([      "action" : "$N����һ����$w��ǰ�ݳ���������֮һ����̫������֮һ����̫��������һʽ�����ʶ���ۡ�����������������ƣ���Ͼ�޹�",
	"force" : 450,
	"dodge" : 0,
	"parry" : 20,
	"damage": 100,
	"lvl" : 90,
	"skill_name" : "���ʶ����",
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("bitao-xuangong",1) < 50)
		return notify_fail("��ı����������̫ǳ��\n");
	if ((int)me->query("shijian") > 20000+random(20000)) {
		tell_object(me, CYN"������һ�����ƺ����һ�������������������\n"NOR);
		me->add("th_jianyi",1);
		me->delete("shijian");
	}
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
	int i, level, jm;
	object target;

	level   = (int) me->query_skill("yuxiao-jian",1);
	target = me->select_opponent();
	weapon = me->query_temp("weapon");
	jm = me->query_temp("th_jianmang");
	
	if (me->query_temp("final_jianmang"))
	{
		if( wizardp(me) )
		{
			tell_object(me,"jm:"+jm+"\n");
		}

		return ([
		"action":HIC"$w"NOR+HIC"�ϵĽ�â�����Ƴ��߰���������......\n\n"NOR+HIG"$N����������һ�����������ӵ�����Ĵ��˰��Ȧ�ӣ�����$w"NOR+HIG"һͦ����ؽ�âͻʢ����â����$n$l��"NOR,
		"force" : 480+jm*20,
		"dodge" : 0,
		"parry" : 0,
		"damage": 140+jm*10,
		"weapon": HIG"��â"NOR,
	//	"post_action": (: next_sword :),	
		"damage_type":  "����"
				]);
	}
	
	if( me->query_temp("th_jianzhi") )
	{
		if( wizardp(me) )
		{
			tell_object(me,"��ָ��������"+(me->query_temp("th_jianzhi") - 20));
		}
	}

	me->add_temp("th_jianzhi", -1); 
	weapon->unequip();
	
	if(me->query_temp("apply/damage") <= 0)
	{
		me->set_temp("apply/damage", 0);
	}

	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	
	/*
	// Check for auto dianxue after finger attack
	if(me->query_temp("n_th_Jianzhi_Auto_Dian_Xue"))
	{
		Auto_Dianxue_Success_Or_Not(me, "finger");
	}
	*/
	
	weapon->wield();
	
	if(me->query_temp("apply/damage") <= 0)
	{
		me->set_temp("apply/damage", 0);
	}

	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

// In here do dianxue success or not after perform used yxj attacked.
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, power, busy, n_Dianxue_Success_Or_Not;

	object weapon;
	string s_Xue;
	string result = "";
	
	s_Xue = xuedao[random(sizeof(xuedao))];

	weapon = me->query_temp("weapon");
	
	if(objectp(me) && weapon->query("shape") == "flute" && me->query_temp("n_th_Jianzhi_Auto_Dian_Xue"))
	{
		n_Dianxue_Success_Or_Not = Auto_Dianxue_Success_Or_Not(me, "sword");
		if(n_Dianxue_Success_Or_Not==1)
		{
			return "��ડ���һ����$n��"+s_Xue+"�ѱ�$N����"+weapon->name()+"���С�\n"+result;
		}
	}
}
	
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ������������｣����\n");
	me->receive_damage("jingli", 30);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"yuxiao-jian/" + action;
}

#include "/kungfu/skill/th_jianzhi_auto_dianxue_success_calculation.c";
