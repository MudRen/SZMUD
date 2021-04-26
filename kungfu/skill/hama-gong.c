// Code of ShenZhou
// ��󡹦 (��Ԫ��ǧ����ް汾)
// maco 2/1/ 2000

inherit FORCE;
inherit SKILL;
string check() { return "force"; }

#include "/kungfu/skill/force_list.h"
#include <ansi.h>

mapping *action = ({
([      "action": "$N������������󡹦�ھ��ŷ���һ�������ӵ�����ֱ��������˫��һ�䣬���и��һ���кȣ����Ʊ㳯$n�Ƴ�",
	"dodge": -15,
	"parry": -20,
	"force": 300,
	"lvl" : 0,
	"damage": 20,
	"damage_type": "����"
]),
([      "action":"$N�ͺ�һ����˫��ٿ��$n$l�Ƴ������������ȥ������ʮ���Ͷ��������ú������죬������������ͬѰ��",
	"parry": 15,
	"force": 380,
	"lvl" : 105,
	"damage": 40,
	"damage_type": "����"
]),
([      "action":"$N�������ӣ���������һ����У��͵�˫���Ƴ���$nͻ��һ����ɽ�����������ײ������Ѹ����",
	"dodge": 25,
	"force": 400,
	"lvl" : 110,
	"damage": 40,
	"damage_type": "����"
]),
([      "action":"$N�׵����ӣ�������$n��ȥ���������ƣ�����������˫��������ϣ��Ʒ����������Ʋ�ס׷������������֮��",
	"dodge": -35,
	"force": 420,
	"lvl" : 115,
	"damage": 60,
	"damage_type": "����"
]),
([      "action":"$N������ɽ��һ���ƻ�����������ȥ���Ʒ���������������仯��΢����������",
	"dodge": 10,
	"force": 420,
	"lvl" : 115,
	"damage": 40,
	"damage_type": "����"
]),
([      "action":"$N���󡱵�һ����У��������ƣ�˫��һ��һ�£�һ��һ�գ���Ȼ����������$n��ɽ��������������",
	"dodge": 20,
	"force": 400,
	"lvl" : 120,
	"damage": 90,
	"damage_type": "����"
]),
([      "action":"$N���Ӷ��£�˫��ƽ�ƶ��������п�����У�����һ��һ�ϡ���һ�ƾ�������ȥ��ȴ��������ƽƽ���棬����ȴ�ǰ��ؼ���Ǳ��",
	"dodge": 0,
	"force": 500,
	"lvl" : 125,
	"damage": 50,
	"damage_type": "����"
]),
([      "action":"$N���ڵ��£��������Ľ��˼�����������ӿ��������һ�������������ϣ�������Ծ����˫���Ƴ���һ������֮�����Ʒ���֮��$nѹ��",
	"dodge": 10,
	"force": 540,
	"lvl" : 130,
	"damage": 100,
	"damage_type": "����"
]),
});

mapping *reverse_action = ({
([      "action": "����$N���������������������������һ������ݺݵĳ�$n�˽�����",
	"dodge": -15,
	"parry": -20,
	"force": 280,
	"damage": 50,
	"damage_type": "����"
]),
([      "action":"����$N���Ƹ������������°�ĭ����ͷ��$n��ײ",
	"parry": 15,
	"force": 290,
	"damage": 60,
	"damage_type": "����"
]),
([      "action":"$N����ſڣ�����һ��������$n$lҧ�䣬�ֿ���׼",
	"dodge": -5,
	"force": 300,
	"damage": 65,
	"weapon": "����",
	"damage_type": "ҧ��"
]),
([      "action":"$Nһ����ĭ���£���Ю���磬����̵����ĭҲ�����˹�������",
	"dodge": -45,
	"force": 350,
	"damage": 70,
	"weapon":"��ĭ",
	"damage_type": "����"
]),
([      "action":"$N��Ȼ���죬һ����ĭ��$n������ȥ�����ƻ���$n���ܵķ�λ��ͬʱ����һ��Ũ̵�½�����",
	"dodge": 30,
	"force": 320,
	"damage": 100,
	"weapon" : "Ũ̵",
	"damage_type": "����"
]),
([      "action":"��ʱ$N��ʹ����������ϣ��Ź֣�������ף�����ʱ��������ʱ��ֱ������Ȼһ�ֳŵأ����Ӻ�ͦ��һ�ֳ��ƴ���$n$l",
	"dodge": 10,
	"force": 420,
	"damage": 90,
	"damage_type": "����"
]),
});

int valid_enable(string usage) {
	if (usage == "force" || usage == "parry" ) return 1;
	if (usage == "strike") {
		if (this_player()->query_skill("hama-gong",1) < 100) {
			write("��ĸ�󡹦����㣬�޷����������Ʒ��С�\n");
			return 0;
		}
		return 1;
	}
	return 0;
}


/*string query_skill_name(int level)
{
	int i;
	for(i = sizeof(action)-1; i >= 0; i--)
	if(level >= action[i]["lvl"])
		return action[i]["skill_name"];
	return "��󡹦";
}*/
mapping query_action(object me, object weapon)
{
	int i, level;
	string *power_msg = 
	({
		HIR"$N���������������󡹦��˫��ƽ�ƣ�������ü�����������к���������֮�����з缲��Ѹ���;���ʵ�Ƿ�ͬС��"NOR,
		WHT"$N�������ŭ�𣬶�������������˫�����������δ�����Ʒ��ѽ����³�������һ�ɾ���ֱ��$n���ţ��Ƶ���ǿ�ޱ�"NOR,
		HIR"$N��ɫ���������������鼡��΢΢ǣ�����������������һ����У�˫��ͦ����һ�ɾ������ֱײ�ĳ�$n�ƽ�����"NOR,
		WHT"$N�׵����ӣ����й������Ľ���������˫���Ƴ����Ը�󡹦��$n�͹���$n������$P��������֮�£�ֻ���û�����������������"NOR,
	});
	string *reverse_msg = 
	({
		HIM"����$N�������أ��������ף������������Լ�������ץһ�ѣ������������Լ����Ϻ���һ�ţ�ÿһ�ƴ򽫳�������;����ر䣬ʵ��֪�򽫺δ�"NOR,
		HIM"$N��Ȼ���������������Լ��������⣬��һ����˫�־ݵأ�����$n�����ط���һ������Ȼ�����Ծ��˫����$n��������"NOR,
		HIM"ͻȻ֮�䣬$N������������ȫȻ���أ����й����ޱȣ�����󡹦��ת���ã�������֮��������֮����������׽��"NOR,
		HIM"$Nȫ������˳���棬����������Ȼ���˴�������Ǵ��д��ţ����ֵֹ�������$n����ѽ�"NOR,
	});

	level   = (int) me->query_skill("hama-gong",1);

	if (me->query_skill_mapped("force") == "hama-gong" ) {
		if ( !me->query_temp("reverse") && me->query_temp("powerup") && random(me->query_skill("force")) > 250 && random(me->query_skill("strike")) > 250 && me->query("neili") > 1000 && me->query("jiali") > 100)
			return ([
			"action": power_msg[random(sizeof(power_msg))],
			"dodge": 20,
			"parry": 20,
			"force": 550+random(100),
			"damage": 120+random(20),
			"damage_type": random(2)?"����":"����"
			]);
		else if ( me->query_temp("reverse") && random(me->query_skill("force")) > 400  && random(me->query_skill("strike")) > 300 && me->query("neili") > 1000 )
			return ([
			"action": reverse_msg[random(sizeof(reverse_msg))],
			"dodge": 100,
			"parry": 100,
			"force": 500+random(100),
			"damage": 120,
			"damage_type": "����",
			]);
	}
	if ( me->query_temp("reverse") )
		return reverse_action[random(sizeof(reverse_action))];
	for(i = sizeof(action); i > 0; i--)
		if(level > action[i-1]["lvl"])
			return action[NewRandom(i, 20, level/5)];
}


int valid_learn(object me)
{
	mapping skl; 
	string *sname;
	int v, k=0;
	
	int i = (int)me->query_skill("hama-gong", 1);

	skl=this_player()->query_skills();
	sname=sort_array( keys(skl), (: strcmp :) );

	if(me->query_skill("hama-gong", 1) > 99){

	for(v=0; v<sizeof(skl); v++) {
		if (SKILL_D(sname[v])->check() == "force")
		k++;  
		}
		if ( k >=3 )
		return notify_fail("�����ڲ�ͬ���������ײ����������������ڹ���\n");
	}

	if ((int)me->query_skill("force", 1) < 10
	 || (int)me->query_skill("force", 1)/2 < i/3 )
		return notify_fail("��Ļ����ڹ�����㣬����ѧ��󡹦��\n");
	if ( me->query("class")=="bonze" )
	{
		if (me->query("gender")=="Ů��")
			return notify_fail("С�������󡹦�����±��˽���ͺͷ�����\n");
		if (me->query("gender")=="����")
			return notify_fail("��ʦ������󡹦�����±��˽���ͺͷ�����\n");
	}
	if ( me->query("family/family_name") == "ؤ��" )
		return notify_fail("�Ͻл���ͽ��ѧ���˸�󡹦��\n");
	if ( me->query("family/family_name") == "�䵱��")
		return notify_fail("�ϵ�����󡹦�����±��˽���ţ���Ӹ����\n");

	return 1;
}

int practice_skill(object me)
{
	if (me->query("family/master_id") != "ouyang feng"
	&& me->query_skill("hamagong", 1) > 99)
		 return notify_fail("��󡹦�����ָ����ܼ�����ߡ�\n");
		 
	if (me->query_temp("weapon"))
		 return notify_fail("���Ӳ��ֱֳ��У���������󡹦Ҳ������֡�\n");
		 
	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ�����������󡹦��\n");
		
	if ((int)me->query("neili") < 50)
		return notify_fail("���������������󡹦��\n");
		  me->add("neili", -30);
		  me->receive_damage("jingli", 30);
	if (me->query_skill("hamagong", 1) > 100){
		me->add("neili", -40);
		  me->receive_damage("jingli", 40);
	}
	if (me->query_skill("hamagong", 1) > 150){
		  me->add("neili", -20);
		  me->receive_damage("jingli", 20);
	}
	if (me->query_skill("hamagong", 1) > 200){
		  me->add("neili", -10);
		  me->receive_damage("jingli", 10);
	}
		  return 1;
}

string perform_action_file(string action)
{
	return __DIR__"hamagong/" + action;
}

string exert_function_file(string func)
{
	return SKILL_D("hamagong/") + func;
}

//Because hamagong inherits both FORCE and SKILL, when it is called
//to return the hit_ob() function, it is confused. So, we have to
//add the hit_ob() here.  Ryu.
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int damage, myneili, yourneili, my_max, your_max;
	string force_skill;
	mixed foo;
		  string result;


	myneili = (int)me->query("neili");
	yourneili = (int)victim->query("neili");
	my_max = (int)me->query("max_neili")*2;
	your_max = (int)victim->query("max_neili")*2;
	myneili = my_max > myneili ? myneili : my_max;
	yourneili = your_max > yourneili ? yourneili : your_max;
	me->add("neili", - factor );
	damage = myneili/20 + factor - yourneili/25;

	if (force_skill = victim->query_skill_mapped("force") ) {
		foo = SKILL_D(force_skill)->hit_by(me, victim, damage, damage_bonus, factor);
		if (stringp(foo)) return (string)foo;
		else if (intp(foo)) damage = (int)foo;
		else if (mapp(foo)) return foo;
	}

	if ( damage > 0 )
		damage = damage * factor / (int)me->query_skill("force") * 2;

	if( damage < 0 ) {
		if( !me->query_temp("weapon")
		&&	random(victim->query_skill("force")) > me->query_skill("force")/2 ) {
			damage = - damage;
			me->receive_damage( "qi", damage * 2, victim);
			me->receive_wound( "qi", damage, victim );
			if( damage < 10 ) result = "$N�ܵ�$n�����������ƺ�һ����\n";
			else if( damage < 20 ) result = "$N��$n���������𣬡��١���һ������������\n";
			else if( damage < 40 ) result = "$N��$n������һ���ؿ������ܵ�һ���ش�����������������\n";
			else result = "$N��$n������һ����ǰһ�ڣ��������ɳ�������\n";
			result += "( $N"+ COMBAT_D->status_msg((int)me->query("qi")*100/(int)me->query("max_qi")) + " )\n";
			damage_bonus = -5000; // just a number negative enough
			return ([ "result" : result, "damage" : damage_bonus ]);
		}
		if( damage_bonus + damage < 0 ) return - damage_bonus;
		return damage;
	}

	damage -= victim->query_temp("apply/armor_vs_force");
	if( damage_bonus + damage < 0 ) return - damage_bonus;
	if( random(me->query_skill("force")) < damage )
		return damage;
}

mixed hit_by(object me, object victim, int damage, int damage_bonus, int factor)
{
	return damage;
}

mapping curing_msg(object me)
{
	return ([
		"unfinish_self"	: "���Ŀ�����������������̣��������������������Ѫ��վ��������\n",
		"unfinish_other": HIW+me->name()+"�˹����ã�Ż�����ں�Ѫ��վ��������\n"NOR,
	]);
}