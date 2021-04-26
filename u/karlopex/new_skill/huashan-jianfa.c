// huashan-jianfa
// ���콣 snowyu 2002/4  

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action":"$Nһ�С����Ƴ�ᶡ��������鶯��ӯ������$w����$n��$l",
	"force" : 150,
        "dodge" : 5,
	"parry" : 5,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "���Ƴ��",
	"damage_type":	"����"
]),
([	"action":"$Nʹ�����з����ǡ������Ʒ���������ڲ�������ţ�����$n��$l",
	"force" : 180,
        "dodge" : 5,
	"parry" : 5,
	"damage": 25,
	"lvl" : 9,
	"skill_name" : "�з�����",
	"damage_type":	"����"
]),
([	"action":"$N��������һ�С�����������$w���϶��»���һ���󻡣���$n������ȥ",
	"force" : 220,
        "dodge" : 8,
	"parry" : 8,
	"damage": 30,
	"lvl" : 18,
	"skill_name" : "������",
	"damage_type":	"����"
]),
([	"action":"$N��ǰ����һ���������ھ�������$wʹ�����׺���ա��������޳��ֱ��$n",
	"force" : 250,
        "dodge" : 10,
	"parry" : 10,
	"damage": 35,
	"lvl" : 25,
	"skill_name" : "�׺����",
	"damage_type":	"����"
]),
([	"action":"$N���е�$w������ҵ�һ�Σ�ʹ��������ӭ�͡����ź�������ֱ��$n��$l",
	"force" : 280,
        "dodge" : 15,
	"parry" : 15,
	"damage": 40,
	"lvl" : 32,
	"skill_name" : "����ӭ��",
	"damage_type":	"����"
]),
([	"action":"$N����Ծ��һʽ�������ա����������콣Ӱ��$w��$n�����ȥ",
	"force" : 310,
        "dodge" : 15,
	"parry" : 15,
	"damage": 45,
	"lvl" : 40,
	"skill_name" : "������",
	"damage_type":	"����"
]),
([	"action":"$N�������У�$w�Ƴ�ѩ����â���ӳ����ޱ���ľ����һ������һ���׵ع���$n",
	"force" : 350,
        "dodge" : 10,
	"parry" : 10,
	"damage": 55,
	"lvl" : 48,
	"skill_name" : "�ޱ���ľ",
	"damage_type":	"����"
]),
([      "action":"$N�����й�ֱ���������������;��Ȼת�����ϣ�����ɽ�������˵��Ǳ���޷�",
	"force" : 390,
        "dodge" : 5,
	"parry" : 5,
        "damage": 65,
        "lvl" : 55,
        "skill_name" : "��ɽ����",
        "damage_type":  "����"
]),
([      "action":"$N����б��һ����һ�С��Ű�ɭɭ�������ɭȻ��������$n��Χ����",
        "force" : 410,
        "dodge" : 8,
	"parry" : 8,
        "damage": 75,
        "lvl" : 62,
        "skill_name" : "�Ű�ɭɭ",
        "damage_type":  "����"
]),
([	"action":"$N˫������$w����â������һʽ����˫�޶ԡ���Ԧ�����Ҿ��׵���$n���",
	"force" : 450,
	"dodge" : 10,
	"parry" : 10,
	"damage": 85,
	"lvl" : 70,
	"skill_name" : "��˫�޶�",
	"damage_type":	"����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������������\n");
	if ((int)me->query_skill("zixia-gong", 1) < 25)
		return notify_fail("�����ϼ�񹦻��̫ǳ��\n");
	return 1;
}
string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"]) return action[i]["skill_name"];
}
mapping query_action(object me, object weapon)
{
        int i, count, level, used, level2, lvl, damage, level3;
        object target;
	string s_action;
        string *msg =
        ({ 
                HIC"\n$N����һ������һ����������ķ���ҲԽ��Խǿ��\n"NOR,
                HIW"\n$N��������������һ�ɾ���������չ��$nֻ���������ˣ����ϡ����ϱ�����ε��������ۡ�\n"NOR,
                HIR"\n$N����һ�죬����ɽ�������ӵ����쾡��,����"+ weapon->name() +HIR"��ʹ�����缲������һ�㡣��\n"NOR,
                HIY"\n$N��һ����������"+ weapon->name() +HIY"�����������Σ�һ������һ����������װ㹥�ϣ�\n"NOR,
               
        });
        level = (int) me->query_skill("huashan-jianfa",1);
        level2 = (int) me->query_skill("zixia-gong",1);
        level3 = (int) me->query_skill("sword",1);
        used = me->query_temp("kuaijian");
        target = me->select_opponent();

        if( !me->query_temp("kuangfeng_kuaijian") && used > 1 && used < 6)
        {
                message_vision( msg[used-2] , me, target);
                me->set_temp("kuangfeng_kuaijian", 1);
                for( count=0; count < used-1; count++ )
                {
                        me->add("jingli", -25);
                        me->add("neili", -50);
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                }
                me->delete_temp("kuangfeng_kuaijian", 1);
                me->add_temp("kuaijian", 1);
        }
        for(i = sizeof(action); i > 0; i--)
	        if(level > action[i-1]["lvl"]){
	        	lvl = NewRandom(i, 20, level/5);
			if (wizardp(me)) tell_object(me, HIG"\n���õ��ǻ�ɽ�����е�"+action[lvl]["skill_name"]+"�˺�����"+action[lvl]["damage"]+"��\n"NOR);
			if ( level > 200 ){
				if ( me->query_temp("zixia/sword",1) && random ( level3 ) > random ( level2 )){
					damage = ( level3 + level2 )/ (5 + random ( 5 ));
		                	s_action = action[lvl]["action"]+"��"MAG"\n$N��һ��"+action[lvl]["skill_name"]+"��������ϼ�����ھ���$n��ȥ������"NOR,
		                        me->add("jingli", -25);
		                        me->add("neili", -50);
					if (wizardp(me)) tell_object(me, HIG"\n������ϼ���˺�����"+action[lvl]["damage"]+"   ����ϼ����˺���"+(action[lvl]["damage"]+damage)+"    ������"+damage+"�˺�����\n"NOR);
				}else{
					damage = level3 / (6 + random ( 6 ));
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
}
int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ�����������ɽ������\n");
	me->receive_damage("jingli", 25, "����͸֧��������");
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"huashan-jianfa/" + action;
}
