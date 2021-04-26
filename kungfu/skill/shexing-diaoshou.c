// Code of ShenZhou
// shexing-diaoshou ���ε���
// qfy August 21, 1996
//changed by wzfeng 2000 6
#include <ansi.h>
#include <combat.h>
inherit SKILL;
mapping *action = ({
([      "action" : "$N���ƻ��أ��ұ�΢�������Σ��������⼲�죬һʽ�����߳���������$n��$l",
        "force" : 140,
        "dodge" : 10,
        "damage_type" : "����",
        "lvl" : 0,
        "skill_name" : "���߳���"
]),
([      "action" : "$N���һ��ʹ������ͷ��β����������������У����ִ�$n���벻��֮����ץ��$l",
        "force" : 180,
        "dodge" : -5,
        "damage_type" : "ץ��",
        "lvl" : 5,
        "skill_name" : "��ͷ��β"
]),
([      "action" : "$Nʹ�����������㡹��˫����$nץȥ��ͬʱ��������Ϣ��һ������$n��$l",
        "force" : 200,
        "dodge" : 0,
        "damage_type" : "����",
	  "lvl" : 10,
        "skill_name" : "��������"
]),
([      "action" : "ֻ��$N�����ڵأ�����$n��ǰ̽�ӣ�ͻȻ����ʹ����������Ӱ������$n��ץ����",
        "force" : 230,
        "dodge" : -5,
        "damage_type" : "ץ��",
        "lvl" : 20,
        "skill_name" : "������Ӱ"
]),
([      "action" : "$NͻȻ��ͷ���ӣ���ȴĪ������ع���$n���������Ĺ��ƣ���һ�С�������ܡ�",
        "force" : 260,
        "dodge" : 15,
        "damage_type" : "����",
        "lvl" : 30,
        "skill_name" : "�������"
]),
([      "action" : "$Nһʽ����ӥ��������˫�ִ���˻˻�ƿ�֮��������Ѹ�ٵؾ���$n����Ҫ������",
        "force" : 300,
        "dodge" : 5,
        "damage_type" : "����",
        "lvl" : 38,
        "skill_name" : "��ӥ����"
]),
([      "action" : "$N˫�ֻ����лó������Ӱ��һ�С�������ӿ������������������ǵ�����$n",
        "force" : 330,
        "dodge" : 0,
        "damage_type" : "����",
        "lvl" : 46,
        "skill_name" : "������ӿ"
]),
([      "action" : "$N���䲻���ʹһʽ���������š�������ʳ����ָ΢�֣���������$n��$l��ͱ",
        "force" : 380,
        "dodge" : 0,
        "damage_type" : "����",
        "lvl" : 55,
        "skill_name" : "��������"
]),
([      "action" : "ͻ��$N˫�������޹ǵ������ţ�ʹ�����������񡹲�ס$n���ұ�ȴ���ĵشӲ���˼�鴦Ĩ��$n��$l",
        "force" : 420,
        "dodge" : 5,
        "damage_type" : "����",
        "lvl" : 65,
        "skill_name" : "��������"
]),
});
int valid_enable(string usage) { return usage=="unarmed" || usage=="hand" ||  usage=="parry"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�����ε��ֱ�����֡�\n");
        if (me->query("family/family_name")=="����ɽ") {
        if ((int)me->query_skill("hamagong",1) < 15)
                return notify_fail("��ĸ�󡹦��򲻹����޷�ѧ���ε��֡�\n");
        }
        else if ((int)me->query_skill("huntian-qigong", 1) < 15)
                return notify_fail("��Ļ���������򲻹����޷�ѧ���ε��֡�\n");
        if ((int)me->query("max_neili") < 50)
                return notify_fail("�������̫�����޷������ε��֡�\n");
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
        int i, level,ob_lvl,attack;
		object ob;
		
		ob = me->select_opponent();
		level = (int)me->query_skill("shexing-diaoshou", 1)+1;
		
		attack=level/100;
		
		if(level>180
			&&random(level)>level*2/5
			&&(random(me->query_dex())>25)
			&&living(ob)
			&&me->query_skill_mapped("dodge") == "xiaoyaoyou"
			&&me->query("neili")>500
			&&(random(5)>2)
			&&!me->query_temp("gb_ds_auto")
			&&(me->query_temp("gb_huixuan")>1)
			)
	{
			message_vision(YEL "$N������ϣ����������������һ�ܣ�$n��$N���������Ի󣬶�ʱ������������Ϊ���ء�\n" NOR, me,ob);
			ob->start_busy(random(3)+random(level/100));
			me->add("neili", -(100+random(100)));
		}

		

		if(level>150
			&&random(level)>level/3
			&&(random(me->query_dex())>20)
			&&living(ob)
			&&me->query_skill_mapped("dodge") == "xiaoyaoyou"
			&&!me->query_temp("gb_ds_auto")
			&&me->query("neili")>800
			&&(me->query_temp("gb_huixuan")>1)
			)
		{
				if(attack>4) attack=4;
				attack=random(attack);
				if(attack<=1) attack=1;
message_vision(HIY "�����ţ�$N���з�����˻˻����������˫�ְ�������ָ��������״���������ң���������缱�籩��㹥����"+
			   chinese_number(attack+1)+"�С�\n" NOR, me);
					for(i=0;i<attack;i++)
					{
						me->add("neili", -(50+random(50)));
						
						ob = me->select_opponent();
						if(!living(ob))
						{
						break;
						}
						me->set_temp("gb_ds_auto",1);
						COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 1);  
						me->delete_temp("gb_ds_auto");
					}
		}


        
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("����������������ε��֡�\n");
        me->receive_damage("jingli", 25);
        me->add("neili", -5);
        return 1;
}
string perform_action_file(string action)
{
        return __DIR__"shexing-diaoshou/" + action;
}

