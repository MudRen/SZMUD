//��Ȼ������
//xiaohun-zhang.c
//Scatter
//V. 2.1
//11/17/01
/*
  ������Ŀ
	-ɱ��������Եĵȼ�����
	-�����ʱ���

*/


#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N�����������أ�һ��"+HIB"��ӹ�����š�"+NOR"��$n�����ɵ��ĳ�һ��",
        "force" : 50,
        "dodge" : 5,
        "parry" : 20,
        "damage": 10,
        "lvl" : 0,
        "skill_name" : "ӹ������",
        "damage_type" : "����"
]),


([      "action" : "$Ņͷ���죬��������,����һʽ"+HIB"��������졹"+NOR"��$nͷ���տ��ĳ�������б�£��������ɻ��Σ���ɢ����",
        "force" : 80,
        "dodge" : 5,
        "parry" : 20,
        "damage": 10,
        "lvl" : 15,
        "skill_name" : "�������",
        "damage_type" : "����"
]),

([      "action" : "ֻ��$N����$n���ԣ�һ��"+HIB"������ֻӰ��"+NOR"������ƽ������һ����Ӱ��ֱ��$n",
        "force" : 97,
        "dodge" : 15,
        "parry" : 20,
        "damage": 10,
        "lvl" : 30,
        "skill_name" : "����ֻӰ",
        "damage_type" : "����"
]),

([      "action" : "$N��һ��"+HIB"���չ��ǻ���"+NOR"ʩչ�Ṧ��$n��Χ�ǻ�����ʱ��$n�ĳ�һ��",
        "force" : 114,
        "dodge" : 15,
        "parry" : 20,
        "damage": 10,
        "lvl" : 45,
        "skill_name" : "�չ��ǻ�",
        "damage_type" : "����"
]),

([      "action" : "$NͻȻվ��ԭ�ز�������$n����δ��ʱ��ͻȻ����бб�ͳ���ֱ��$n�ĸ���ҪѨ������һ��"+HIB"������ľ����"+NOR,
        "force" : 136,
        "dodge" : 25,
        "parry" : 20,
        "damage": 10,
        "lvl" : 60,
        "skill_name" : "����ľ��",
        "damage_type" : "����"
]),

([      "action" : "$n��$N�������У�ֻ��$Nһ��"+HIB"������Ƿǡ�"+NOR"��˫�ƽ�����$nӭȥ���ٶ�֮�����˲�֪����",
        "force" : 160,
        "dodge" : 25,
        "parry" : 20,
        "damage": 10,
        "lvl" : 75,
        "skill_name" : "����Ƿ�",
        "damage_type" : "����"
]),

([      "action" : "ֻ��$Nһʽ"+HIB"������������"+NOR"������������ǰ����ͬ�Ա���ͬʱ�����Ƴ������ƽ��������$n�Ƴ�",
        "force" : 183,
        "dodge" : 25,
        "parry" : 20,
        "damage": 10,
        "lvl" : 90,
        "skill_name" : "��������",
        "damage_type" : "����"
]),

([      "action" : "$N�����㱣���������һ��"+HIB"�����񲻰���"+NOR"��$n�����˶�$N��������$N������ͻȻ$N������$nӭ�����",
        "force" : 200,
        "dodge" : 25,
        "parry" : 20,
        "damage": 10,
        "lvl" : 105,
        "skill_name" : "���񲻰�",
        "damage_type" : "����"
]),

([      "action" : "$N���ް�������ʽ������$n�����������ͻȻ�������붯���������䣬˫��ͷ���������ر�������������ʽ������һ��"+HIB"���������С�"+NOR"����$n��ȥ",
        "force" : 202,
        "dodge" : 25,
        "parry" : 20,
        "damage": 10,
        "lvl" : 120,
        "skill_name" : "��������",
        "damage_type" : "����"
]),

([      "action" : "ֻ��$N�����ɫ��һʽ"+HIB"��������ʧ��"+NOR"�������϶�������$nͷ��",
        "force" : 204,
        "dodge" : 25,
        "parry" : 20,
        "damage": 10,
        "lvl" : 135,
        "skill_name" : "������ʧ",
        "damage_type" : "����"
]),

([      "action" : "$N����Ʈ����������ˮ������ȴ����֮�������ƴ��ż�ǧ����ɳһ�㣬һ��"+HIB"�������ˮ��"+NOR"��$n��ȥ",
        "force" : 206,
        "dodge" : 35,
        "parry" : 20,
        "damage": 10,
        "lvl" : 160,
        "skill_name" : "�����ˮ",
        "damage_type" : "����"
]),

([      "action" : "$NͻȻͷ�½��ϣ��������ӣ�ʹ��"+HIB"��������ʩ��"+NOR"��$n�ĳ�һ��",
        "force" : 208,
        "dodge" : 35,
        "parry" : 20,
        "damage": 10,
        "lvl" : 190,
        "skill_name" : "������ʩ",
        "damage_type" : "����"
]),


([      "action" : "$n��$N�����������Ҫ����$N���ϣ�ͻ��$N��С�����������ͬʱ�ؿ�����һ����ٿ�ص��������ǳ��䲻���"+HIB"���ľ�������"+NOR,
        "force" : 210,
        "dodge" : 35,
        "parry" : 20,
        "damage": 10,
        "lvl" : 240,
        "skill_name" : "��ʬ����",
        "damage_type" : "����"
]),

([      "action" : "$NͻȻ֮������ϲŭ���֣���״�ٳ�,����"+HIB"��������ɫ��"+NOR"����һ������ʱ������������",
        "force" : 270,
        "dodge" : 45,
        "parry" : 20,
        "damage": 10,
        "lvl" : 300,
        "skill_name" : "������ɫ",
        "damage_type" : "����"
]),

([      "action" : "$N��ɫ�Ұף�һ��"+HIB"���겻���᡹"+NOR"�������������ֽ�������$n�Ƴ�����",
        "force" : 320,
        "dodge" : 45,
        "parry" : 20,
        "damage": 10,
        "lvl" : 350,
        "skill_name" : "�겻����",
        "damage_type" : "����"
]),

([      "action" : "$n�����ƽ���$Nֻ�е�һ��ѹ���������Ƴ�һ�ƣ����Ǿ���������"+HIB"����;ĩ·��"+NOR,
        "force" : 350,
        "dodge" : 50,
        "parry" : 20,
        "damage": 10,
        "lvl" : 400,
        "skill_name" : "��;ĩ·",
        "damage_type" : "����"
])


});

int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

int valid_combine(string combo) { return combo=="meinu-quan"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("��Ȼ�����Ʊ�����֡�\n");
        if ((int)me->query_skill("yunu-xinjing", 1) < 20)
                return notify_fail("����Ů�ľ����˽ⲻ��, �޷�ѧ��Ȼ�����ơ�\n");
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������̫�����޷�����Ȼ�����ơ�\n");
    if (me->query("gender") != "����")
        return notify_fail("ֻ���е��Ӳſ���ѧ��\n");
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for(i = sizeof(action)-1; i >= 0; i--)
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

/*
mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("xiaohun-zhang",1);
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}
*/

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 30)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 20)
                return notify_fail("���������������Ȼ�����ơ�\n");

        me->receive_damage("jingli", 30);
        me->add("neili", -10);
        return 1;
}

string perform_action_file(string action)
{
        if ( this_player()->query_skill("xiaohun-zhang", 1) >= 30 )
                return __DIR__"xiaohun-zhang/" + action;
}
mapping query_action(object me, object weapon) 
{
           int i, level; 
           object target; 
           string jmsg;
           level = (int)me->query_skill("xiaohun-zhang", 1); 
           switch(me->query_temp("perform/jingtao"))
           {
               case 1:jmsg = "$N��ɫ�Ұף�һ�С��겻���᡹�������������ֽ�������$n�Ƴ�����"NOR;break;
                 case 2:jmsg = "$NͻȻͷ�½��ϣ��������ӣ�ʹ����������ʩ����$n�ĳ�һ��"NOR;break;
                 case 3:jmsg = "ֻ��$N�����ɫ��һʽ��������ʧ���������϶�������$nͷ��"NOR;break;
           }
           target = me->select_opponent(); 
           if( me->query_temp("perform/jingtao") && target ) 
           {
return (["action":jmsg, 
           "dodge": -20,
           "parry": 25,
           "force": 650,
           "damage": 120,
           "damage_type": "����"]);
           }
                   else {
           for(i = sizeof(action); i > 0; i--) 
                   if(level > action[i-1]["lvl"]) 
                           return action[NewRandom(i, 20, level/5)]; 
            }
}
