// Code of ShenZhou
// sanyin-zhua.c -�������צ
//aska dec,2 1996
//wsky march 7th 2000

#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N������Ц��Ц���������$n�����ţ���$nȫ���м�֮�ʣ�һת������ץ��$n��$l",
        "dodge": 10,
        "force": 40,
//      "poison": 80,
        "damage": 20,
        "lvl" : 0,  
        "damage_type": "ץ��"
]),
([      "action" : "$NͻȻ����װ��������$n�ɻ󲻶�֮�䣬��ȻԾ��˫��ץ��$n��$l��$n��֮�£���֪����",
        "dodge": 10,
        "parry": 10,
        "force": 160,
//      "poison": 100,
        "damage": 40,
        "lvl" : 10,
        "weapon": "�����ָ",
        "damage_type": "����"
]),
([      "action" :"$N�˵ض���������һ����򼣬�ڵ��Ͽ������˼������Ƶ�$n���һצץ��",
        "dodge": 15,
        "parry": 15,
        "force": 180,
//      "poison": 100,
        "damage": 50,
        "lvl" : 18,
        "damage_type": "ץ��"
]),

([      "action" : "������У�$N��������������ɫ��һ�Լ��ţ���צ�͵�̽��$n��$l",
        "dodge": 5,
        "parry": 25,
        "force": 200, 
//      "poison": 120,
        "damage": 55,
        "lvl" : 26,
        "damage_type": "����"
]),     
([      "action" :"$N����Ķ���$n���ϴ���һ������$n˲�䷽����ң�$N�������$n��ǰץ������",

        "dodge": 15,
        "parry": 30,
        "force": 280,
//      "poison": 160,
        "damage": 60,
        "lvl" : 36, 
        "damage_type": "ץ��"
]),
([      "action" : "$N����$n���ٵ�ת�˼�Ȧ������һ������צ���棬��������ָ�������Ϯ��$n",
        
        "dodge": 10,
        "parry": 25,
        "force": 350,
//      "poison": 200,
        "damage": 80,
        "lvl" : 45, 
        "damage_type": "ץ��"
]),

([      "action" : "$N��Ӱ��ǰ���ᣬ����Ʈ��������ͻȻһת��������$n��$l£ȥ",
        "dodge": 25,
        "parry": 15,
        "force": 420,
//      "poison": 240, 
        "damage": 75,
        "lvl" : 65,
        "damage_type": "����"
]),

([      "action" : "$Nʹ��һ�С������֡���ʮָ������������ɫ��â����ס$n���������總��֮��",
        "dodge": 20,
        "parry": 45,
        "force": 450,
//      "poison": 300,
        "damage": 85,
        "lvl" : 63, 
        "skills_name" : "������",
        "damage_type": "ץ��"
])
});
int valid_enable(string usage) { return usage=="claw" || usage=="parry"; }

int valid_combine(string combo) { return combo=="chousui-zhang"; }

int valid_learn(object me)
{
        
        int  nb,  nh;
        nb = (int)me->query_skill("poison", 1);
        nh = (int)me->query_skill("sanyin-zhua", 1);

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���������צ������֡�\n");
        if ((int)me->query_skill("huagong-dafa", 1) < 10)
                return notify_fail("��Ļ����󷨻�򲻹����޷�ѧ�������צ��\n");
        if ( nb < 100 && nb <= nh )
                return notify_fail("��Ķ�����Ϊ�������޷�����������צ��\n");

        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷����������צ��\n");
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
        int i, level;
        level   = (int) me->query_skill("sanyin-zhua",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        int  nb,  nh;
        nb = (int)me->query_skill("poison", 1);
        nh = (int)me->query_skill("sanyin-zhua", 1);

        if ((int)me->query("jingli") < 30)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("�������������\n");
        if ( nb < 100 && nb <= nh )
                return notify_fail("��Ķ�����Ϊ�������޷�����������צ��\n");

        me->receive_damage("jingli", 30);
        me->add("neili", -5);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int neili, neili2, cases, csz, par, mein, exp1, exp2;
        string result;
        neili=me->query("neili");
        neili2=victim->query("neili");
	exp1=me->query("combat_exp")/10000;
	exp2=victim->query("combat_exp")/10000;
	csz=me->query_skill("sanyin-zhua",1);
	par=victim->query_skill("parry",1);
	mein=0;
	
	if(csz>150){
	if (present("huo yan", environment(me))){
        	mein=13;
        	if(csz<150) cases=1;
        	else if (csz>=150 && csz<200) cases=3;
        	else cases=6;
        	switch(random(cases)){
        		case 0:
        		message_vision(HIR"\n$Nһ��������Ϻ��һ�֣��ؿڿ��ǣ�˫�����һ����磬���Ż���������$n��ȥ��"NOR,me,victim);
        		damage_bonus+=250+random(100);
        		return ([ "result" : result, "damage" : damage_bonus ]);
			break;
        		case 1:
        		message_vision(HIB"\n$NͻȻ���Ʒ�һ�䣬��������һĨ�����������$n�������ƣ�$n����һ�����˺�һ����"NOR,me,victim);
        		damage_bonus+=250+random(150);
        		return ([ "result" : result, "damage" : damage_bonus ]);
        		break;
        		case 2:
        		message_vision(HIY"\n$N����һ�Σ�������ȣ�˫�Ʒ���һ����ɫ���棬Ѹ���ޱȵ���$n��ȥ��"NOR,me,victim);
        		damage_bonus+=250+random(200);
        		return ([ "result" : result, "damage" : damage_bonus ]);
        		break;
        		case 3:
        		message_vision(HIR"\n$N������У��͵�ҧ���Լ���ͷ��һ����Ѫ��$n��ȥ��$nɲʱ�䲻֪���룬ֻ�����ܿ���"NOR,me,victim);
        		damage_bonus+=250+random(250);
        		return ([ "result" : result, "damage" : damage_bonus ]);
        		break;
        		case 4:
        		message_vision(HIW"\n$N����һ�Σ���������$nͻȻ�����һ˿�������Լ�Ϯ������������һ���ʹ��"NOR,me,victim);
        		damage_bonus+=250+random(300);
        		return ([ "result" : result, "damage" : damage_bonus ]);
        		break;
        		case 5:
        		message_vision("\n$N"HIB"������"NOR"��"HIR"������"NOR"��"HIW"˫�����һ�󾢷�"NOR"����û���"HIG"��"HIY"��"HIM"��"HIR"ɫ"NOR"��Ư���ޱȡ�"NOR,me,victim);
        		damage_bonus+=250+random(400);
        		return ([ "result" : result, "damage" : damage_bonus ]);
			case 6:
        		message_vision("\n$N"HIB"������"NOR"��"HIR"������"NOR"��"HIW"˫�����һ�󾢷�"NOR"����û���"HIG"��"HIY"��"HIM"��"HIR"ɫ"NOR"��Ư���ޱȡ�"NOR,me,victim);
        		damage_bonus+=250+random(400);
        		return ([ "result" : result, "damage" : damage_bonus ]);
        		break;
        	}
        }}
	
        if(random(neili)>random(neili2)){
                message_vision(MAG"$n��Ȼ����һ����Ϯ��������һ�Σ�ͷ��΢΢��Щ���衣\n"NOR, me, victim);
                victim->apply_condition("xx_poison", random(me->query_skill("sanyin-zhua", 1)/2) + victim->query_condition("xx_poison"));
                if(victim->query("poisoner") != me) victim->set("poisoner", me);
        } else message_vision(YEL"$næ�������ֿ�����$Nצ�ϵľ綾�������⡣\n"NOR,me,victim);
	
}

string perform_action_file(string action)
{
        if ( this_player()->query_skill("sanyin-zhua", 1) >= 100 )
                return __DIR__"sanyin-zhua/" + action;
}

