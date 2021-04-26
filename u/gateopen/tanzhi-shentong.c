// Code of ShenZhou

//tanzhi-shentong.c
//kane 4/9/97 
#include <ansi.h>
#include <combat.h>

inherit SKILL;
inherit F_DBASE;
inherit F_SSERVER;

// Use to determind auto dianxue success or not, if no xiao, no auto dianxue
// s_Attack_Type mean it is a finger attack or sword attack, since return message is not the same
#include "/kungfu/skill/th_jianzhi_auto_dianxue_success_calculation.h";

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

mapping *action = ({
([      "action" : "$N����ʳָ���͵�һ�����죬һ��ϸϸ��������$n"+xuedao[random(sizeof(xuedao))],
	"force" : 250,
	"dodge" : 0,
	"parry" : 0,
	"damage": 25,
	"lvl" : 0,
	"weapon": "ָ��", 
	"damage_type" : "����"
]),
([      "action" : "$N��ס��ָ���������������£�����ָ�������������۵�ֿ������$n��"+xuedao[random(sizeof(xuedao))]+"��"+xuedao[random(sizeof(xuedao))]+"��"+xuedao[random(sizeof(xuedao))],
	"force" : 300,
	"dodge" : 20,
	"parry" : 15,
	"damage": 40,
	"lvl" : 20,
	"weapon": "ָ��",
	"damage_type" : "����"
]),
([      "action" : "$N������ָ������ָ��һ�뵯������ָָ������$n"+xuedao[random(sizeof(xuedao))]+"������ָ�ϰ�������������Ϣ������"+xuedao[random(sizeof(xuedao))],
	"force" : 350,
	"dodge" : 25,
	"parry" : 20,
	"damage": 50,
	"lvl" : 40,
	"damage_type" : "����"
]),
([      "action" : "$N˫�㲻�����ˣ�̤�Ŷ�����ľ֮λ��ʳ�ж�ָ����סĴָ��һ����Х�����ֵ���������һ�������޼���ָ��������$n��"+xuedao[random(sizeof(xuedao))],
	"force" : 400,
	"dodge" : 30,
	"parry" : 15,
	"damage": 60,
	"lvl" : 60,
	"damage_type" : "����"
]),
([      "action" : "$N���һ����˫���������У���������һ�����ţ�����ָ����������Ϣ��Ϯ��$n��"+xuedao[random(sizeof(xuedao))]+"��"+xuedao[random(sizeof(xuedao))]+"��"+xuedao[random(sizeof(xuedao))]+"����ҪѨ",
	"force" : 450,
	"dodge" : 40,
	"parry" : 10,
	"damage": 80,
	"lvl" : 80,
	"weapon": "ָ��",
	"damage_type" : "����"
]),
([      "action" : "$N��ɫ���أ�������ת��ֻ��$N������ָ����Ϊ����ɫ����������$n��$nֻ���ؿ�һ�ϣ���һ��ɭ��֮����ָ��ѹ�ü�������Ҳ��������",
	"force" : 500,
	"dodge" : 50,
	"parry" : 10,
	"damage": 100,
	"lvl" : 100,
	"damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

//int valid_combine(string combo) { return combo=="lanhua-fuxue"; }

int valid_learn(object me)
{
	if (me->query("family/master_name") != "��ҩʦ")
		return notify_fail("��ָ��ͨ���һ����������������ҩʦ��̡�\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����ָ��ͨ������֡�\n");
	if ((int)me->query_skill("bitao-xuangong", 1) <60)
		return notify_fail("��ı���������򲻹����޷�ѧ��ָ��ͨ��\n");
	if ((int)me->query("max_neili") < 500)
		return notify_fail("�������̫�����޷�����ָ��ͨ��\n");
	if ((int)me->query_skill("finger", 1) <60)
	   return notify_fail("��Ļ���ָ����򲻹����޷�ѧ��ָ��ͨ��\n");
	return 1;
}

mapping query_action(object me, object weapon)
{
	int i, level;        
	object victim, w;

	if( !victim && me->is_fighting() ) victim = offensive_target(me);
	w = victim->query_temp("weapon");
        level   = (int) me->query_skill("tanzhi-shentong",1);
/*
	if ((w) && random(level)>random(400) && me->query("neili")>600) {
        	me->add("neili", -100);	
        	message_vision(HIG"$N��Цһ�������ʳ�ж�ָ��$n���е�"+w->name()+HIG"��ȥ��\n"NOR,me,victim);
        	remove_call_out("bash_weapon");
		call_out("bash_weapon",0, me, victim);
        }
*/	
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	if ((int)me->query("jingli") < 80)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 40)
		return notify_fail("���������������ָ��ͨ��\n");
	me->receive_damage("jingli", 25);
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
       return __DIR__"tanzhi-shentong/" + action;
}

int bash_weapon(object me, object victim)
{
        object ob;
        int wap, wdp;
//      string attack_skill;
//      attack_skill = weapon->query("skill_type");

        if( (me->query("neili") > 100)
        &&      ob = victim->query_temp("weapon") ) {
                wap = (int)me->query("neili") / 20
                        + (int)me->query("max_neili")/2
                        + (int)me->query_str()
                        + (int)me->query_skill("tanzhi-shentong",1)/2;
                wdp = (int)ob->weight() / 500
                        + (int)ob->query("rigidity")
                        + (int)victim->query_str()
                        + (int)victim->query("neili")/15;
                wap = random(wap);
                if( wap > 2 * wdp ) {
                        message_vision(HIW "$Nֻ��������" + ob->name() + "�ѳֲ��������ַɳ���\n" NOR,
                                victim);
                        ob->unequip();
                        ob->move(environment(victim));
                        victim->reset_action();
                } else if( wap > wdp ) {
                        message_vision(HIW "ֻ������ž����һ����$N���е�" + ob->name() + "�Ѿ���Ϊ���أ�\n" NOR, victim );
                        ob->unequip();
                        ob->move(environment(victim));
                        ob->set("name", "�ϵ���" + ob->query("name"));
//                      ob->set("value", (int)ob->query("value") / 10);
                        ob->set("value", 0);
                        ob->set("weapon_prop", 0);
                        victim->reset_action();
                } else if( wap > wdp / 2 ) {
                        message_vision("$Nֻ��������" + ob->name() + "һ����Щ���֣�\n",
                                victim);
                } 
/*		else {
                        message_vision("$N�����Сʯ�Ӻ�$n��" + ob->name()
                                + "�����ð�����Ļ��ǡ�\n", me, victim);
                }*/
        }
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level, jiali, power, busy;

	object weapon;
	string s_Xue;
	string result = "";
	
	s_Xue = xuedao[random(sizeof(xuedao))];

	weapon = me->query_temp("weapon");
	
	if(objectp(me) && me->query_temp("n_th_Jianzhi_Auto_Dian_Xue"))
	{
		Auto_Dianxue_Success_Or_Not(me, "finger");
		// return "��ડ���һ����$n��"+s_Xue+"�ѱ�$N����"+weapon->name()+"���С�\n"+result;
		// return "$n��"+s_Xue+"����һ��ָ�����У���ʱ���鲻�ѡ�\n"+result;
		// message_vision("$N��"+s_Xue+"����һ��ָ�����У���ʱ���鲻�ѡ�\n", victim);
	}
}

#include "/kungfu/skill/th_jianzhi_auto_dianxue_success_calculation.c";