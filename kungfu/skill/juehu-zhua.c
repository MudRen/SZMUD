// Code of ShenZhou
#include <mudlib.h>
#include <ansi.h>

inherit SKILL;
inherit F_DAMAGE;
mapping *action = ({
([      "action" : "$N������Ц��Ц������ץ��$n��$l",
        "dodge": 10,
        "force": 40,
//      "poison": 80,
        "damage": 0,
        "lvl" : 0,  
        "damage_type": "ץ��"
]),
([      "action" :
 "$NͻȻ����װ��������$n�ɻ󲻶�֮�䣬��ȻԾ��˫��ץ��$n������",
        "dodge": 10,
	"parry": 10,
        "force": 160,
//      "poison": 100,
        "damage": 40,
        "lvl" : 10,
	"weapon": "�����ָ",
        "damage_type": "����"
]),
([      "action" :"$N����һ����򼣬�ڵ��Ͽ������˼������Ƶ�$n���һצץ��",
        "dodge": 15,
        "parry": 15,
        "force": 180,
//      "poison": 100,
        "damage": 40,
        "lvl" : 18,
        "damage_type": "ץ��"
]),

([      "action" : "$N��������������ɫ��һ�Լ��ţ���צ̽��$n",
        "dodge": 5,
        "parry": 25,
        "force": 200, 
//      "poison": 120,
        "damage": 45,
        "lvl" : 26,
        "damage_type": "����"
]),     
([      "action" :"$N����Ķ���$n���ϴ���һ������$n˲�䷽����ң�$N�������$n��ǰץ������\n",

        "dodge": 15,
        "parry": 30,
        "force": 280,
//      "poison": 160,
        "damage": 60,
        "lvl" : 36, 
        "damage_type": "ץ��"
]),
([      "action" : "$N����$n���ٵ�ת�˼�Ȧ������һ������צ���棬��������ָ�������Ϯ��$n\n",
        
        "dodge": 10,
        "parry": 25,
        "force": 350,
//      "poison": 200,
        "damage": 70,
        "lvl" : 45, 
        "damage_type": "ץ��"
]),

([      "action" : "$N��Ӱ��ǰ���ᣬͻȻһת��������$n��$l£ȥ",
        "dodge": 25,
        "parry": 15,
        "force": 420,
//      "poison": 240, 
        "damage": 75,
        "lvl" : 55,
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
      /*  nb = (int)me->query_skill("poison", 1);
        nh = (int)me->query_skill("sanyin-zhua", 1);

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("���������צ������֡�\n");
        if ((int)me->query_skill("huagong-dafa", 1) < 10)
                return notify_fail("��Ļ����󷨻�򲻹����޷�ѧ�������צ��\n");
	if ( nb < 100 && nb <= nh )
                return notify_fail("��Ķ�����Ϊ�������޷�����������צ��\n");
*/
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
        level   = (int) me->query_skill("juehu-zhua",1);
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
/*	if ( nb < 100 && nb <= nh )
                return notify_fail("��Ķ�����Ϊ�������޷�����������צ��\n");
*/
        me->receive_damage("jingli", 30);
        me->add("neili", -5);
        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int lv,myexp,tarexp;
	lv = (int)me->query_skill("juehu-zhua",1);
	myexp = me->query("combat_exp");
	tarexp = victim->query("combat_exp");
	if ( random(lv) >200 && myexp > (int)(tarexp*1.5))
	{
	if (victim->query("gender") == "����")
	{
	me->add("max_neili", -10);
	victim->set("gender", "����");
	me->set("neili", 0);
	return HIR "$Nҧ����⣬����ȫ������$n����ץȥ������\n" NOR;
	}
	else 
	{
	victim->receive_wound("qi", lv*2);
        me->add("max_neili", -3);
        me->set("neili",0);  
        return HIR "$nֻ��������һ���ʹ�����ݺ�ץ��һ��Ѫ��¡\n" NOR;
        }
	}
}

