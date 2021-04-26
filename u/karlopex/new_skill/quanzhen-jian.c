// Code of ShenZhou
// quanzhen-jianfa ȫ�潣��
// by sdong

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([	"action":"$N�ζ�$w��̤���ţ���ƫ�棬������˼�����һ�������ޱȵġ��ֻ�������������ʵ�ң��ѵ���$n$1",
	"force" : 150,
		  "dodge" : 5,
	"parry" : 5,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "�ֻ�����",
	"damage_type":	"����"
]),
([	"action":"$Nʹһ�С���������������������Ʈ������$w����ʵʵ�ó����㺮������$n$l",
	"force" : 180,
		  "dodge" : 5,
	"parry" : 5,
	"damage": 25,
	"lvl" : 9,
	"skill_name" : "��������",
	"damage_type":	"����"
]),
([	"action":"$N������$nһת����Ȼһʽ���ɨҶ������$w������콣Ӱ��Ю�ž�����$nɨȥ",
	"force" : 250,
	 "dodge" : 10,
	"parry" : 10,
	"damage": 60,
	"lvl" : 25,
	"skill_name" : "�ɨҶ",
	"damage_type":	"����"
]),
([	"action":"$N���쳤Ц������ƮȻ�����ڰ��������һ����һʽ�����ʹ��������$w����ػ���$n��$l",
	"force" : 380,
	 "dodge" : 15,
	"parry" : 15,
	"damage": 75,
	"lvl" : 32,
	"skill_name" : "���ʹ��",
	"damage_type":	"����"
]),
([	"action":"$N�������Ž���������̤��һ�С������롱����б�̣�$w��ȻԾ��ٿ�Ļ��������ǹ�����$n��$l",
	"force" : 220,
	 "dodge" : 8,
	"parry" : 8,
	"damage": 20,
	"lvl" : 40,
	"skill_name" : "������",
	"damage_type":	"����"
]),
([	"action":"$N��ǰ��ȥһ�󲽣�ʹ����̽��������������$w���һ������Ѹ�����׻���$n��$l",
	"force" : 350,
		  "dodge" : 10,
	"parry" : 10,
	"damage": 65,
	"lvl" : 48,
	"skill_name" : "̽������",
	"damage_type":	"����"
]),
([	"action":"$N����һ��$w��һʱ�������仨����$w�ó���㽣����ƮȻ����$n��$l",
	"force" : 310,
		  "dodge" : 15,
	"parry" : 15,
	"damage": 35,
	"lvl" : 56,
	"skill_name" : "�����仨",
	"damage_type":	"����"
]),
([	"action":"$N����$wһָ���������࣬һʱ������Į������$w����������$n��$l",
	"force" : 310,
		  "dodge" : 15,
	"parry" : 15,
	"damage": 45,
	"lvl" : 62,
	"skill_name" : "����Į��",
	"damage_type":	"����"
]),
([      "action":"$N���һ����һ�С��׺羭�졹��$w����㻮��һ����Բ������$n��$l",
	"force" : 390,
	 "dodge" : 5,
	"parry" : 5,
	 "damage": 65,
	 "lvl" : 70,
	 "skill_name" : "�׺羭��",
	 "damage_type":  "����"
]),
([      "action":"$N��������Ʈ��ͻȻһת��ͷ�½��ϣ�˫����$w��һ�С���׹��������������Ϣ�ع���$n��$l",
		  "force" : 410,
		  "dodge" : 8,
		"parry" : 8,
		  "damage": 65,
		  "lvl" : 75,
		  "skill_name" : "��׹����",
		  "damage_type":  "����"
]),
([	"action":"$N����$wһ����һ�С�������Ե����$w�Ƴ�ҫ�۹�â����������$n",
	"force" : 400,
	 "dodge" : 10,
	"parry" : 10,
	"damage": 85,
	"lvl" : 80,
	"skill_name" : "������Ե",
	"damage_type":	"����"
]),
([	"action":"$N��Ȼ���θ߸�Ծ��ʹ�����˼����ġ���$w�ó����컨�꣬Ѹ����������$n��$l",
	"force" : 450,
	 "dodge" : 20,
	"parry" : 20,
	"damage": 100,
	"lvl" : 90,
	"skill_name" : "�˼�����",
	"damage_type":	"����"
]),
});


int valid_enable(string usage) { return usage == "sword" || usage == "parry" || usage == "zuoyou-hubo" ; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("xiantian-gong", 1) < 10
		&& (int)me->query_skill("yunu-xinjing", 1) <20 )
		return notify_fail("����ڹ����̫ǳ��\n");
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
        int i, count, level, used, level2, lvl, damage, level3;
 	string s_action;
	level   = (int) me->query_skill("quanzhen-jian",1);
        level2 = (int) me->query_skill("force",1);
        level3 = (int) me->query_skill("sword",1);
        for(i = sizeof(action); i > 0; i--)
	        if(level > action[i-1]["lvl"]){
	        	lvl = NewRandom(i, 20, level/5);
			if (wizardp(me)) tell_object(me, HIG"\n���õ���ȫ�潣���е�"+action[lvl]["skill_name"]+"�˺�����"+action[lvl]["damage"]+"��\n"NOR);
			if ( level > 200 ){
				if ( me->query_temp("sanqing",1) && random ( level3 + level / 2  ) > random ( level2 )){
					damage = ( level3 + level2 )/ (2 + random ( 5 ));
		                	s_action = action[lvl]["action"]+"��"MAG"\n$N��һ��"+action[lvl]["skill_name"]+"�����������ڹ�������һ����������ھ�������$n����������"NOR,
		                        me->add("jingli", -10);
		                        me->add("neili", -20);
					if (wizardp(me)) tell_object(me, HIG"\n����������˺�����"+action[lvl]["damage"]+"   ���������˺���"+(action[lvl]["damage"]+damage)+"    ������"+damage+"�˺�����\n"NOR);
				}else{
					damage = level3 / (3 + random ( 6 ));
		                	s_action = action[lvl]["action"];
					if (wizardp(me)) tell_object(me, HIG"\nδ�����ټ����˺�����"+action[lvl]["damage"]+"   ���ټ�����˺���"+(action[lvl]["damage"]+damage)+"    ������"+damage+"�˺�����\n"NOR);
                		}
				return ([
			                "action":s_action,
			                "dodge":action[lvl]["dodge"],
			                "force":action[lvl]["force"],
			                "parry":action[lvl]["parry"],
			                "damage":action[lvl]["damage"] + damage,
			                "damage_type":action[lvl]["damage_type"],
			        ]);
                	}
	        	return action[lvl];
		}
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ���������ȫ�潣����\n");
	me->receive_damage("jingli", 25, "����͸֧��������");
	return 1;
}

string perform_action_file(string action)
{
		  return __DIR__"quanzhen-jian/" + action;
}
/*
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
		  string result;

	if(me->query_temp("sanqing",1))
	{
					 damage_bonus *=2;
//					 if( damage < 5 ) damage = 0;

					 result = HIY"$n���ϵ�"NOR+HIR"ͨ�鱦��"NOR+HIY"��Ȼ�ų�һ��ҫ�۹�â��$N����һ������Ҳ����������\n"NOR;

					 return ([ "result": result, "damage": damage_bonus+random(damage_bonus) ]);
	}

}
*/
/*
	if(me->query_temp("sanqing",1))
	{
		if(me->query("jing",1)<damage_bonus+20)
		{
			message_vision(HIM "$N����������ô�ã�������Ϊ���ۣ�������������½���\n\n" NOR, me);
			::hit_ob(me, victim, damage_bonus, factor);
		}
		else
		{
			if(damage_bonus<10)damage_bonus=10;
			damage_bonus = 25;
			me->receive_damage("jing", 20);
			victim->receive_damage("qi", 20);
			victim->receive_damage("max_qi", 20);
//			victim->receive_damage("qi",damage_bonus,"�þ���������");
//			victim->receive_damage("max_qi",damage_bonus,"�þ���������");
//			me->receive_damage("jing",damage_bonus,"�þ���������");
//			::hit_ob(me, victim, damage_bonus, factor);
			message_vision(HIR "$Nһ�л��У���$n���˲��ᣡ\n\n" NOR, me,victim);
			return 1;
		}
	}
	else ::hit_ob(me, victim, damage_bonus, factor);
}
*/