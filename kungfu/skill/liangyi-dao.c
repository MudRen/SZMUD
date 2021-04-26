//Cracked by Kafei
// liangyi-dao.c ��ɽ�����ǵ���
// qfy September 7, 1996

#include <ansi.h> 
inherit SKILL;

mapping *action = ({
([	"action":"$Nš��תʩչ������һ�ơ�����Ȼ�ӵ��ӱ��󷴻��˸����Σ�����������ն��$n$l",
	"force" : 150,
        "dodge" : 10,
	"parry" : 10,
	"damage": 15,
	"lvl" : 0,
	"skill_name" : "����һ��",
	"damage_type":	"����"
]),
([	"action":"$N��������������ġ���$wһʽ��̫�����ȡ���������ٱ�ض�׼$n��$l������ȥ",
	"force" : 250,
        "dodge" : 15,
	"parry" : 15,
	"damage": 30,
	"lvl" : 10,
	"skill_name" : "̫������",
	"damage_type":	"����"
]),
([	"action":"$N��ǰ����һ�����Ⱦݡ�������ʹ�������Ǻϵ¡����Ӷ�$w��$n�����������ն����",
	"force" : 300,
        "dodge" : 10,
	"parry" : 10,
	"damage": 40,
	"lvl" : 25,
	"skill_name" : "���Ǻϵ�",
	"damage_type":	"����"
]),
([	"action":"$N������������桱λ���������ַ��������»��������������������������$n����������",
	"force" : 350,
        "dodge" : 15,
	"parry" : 10,
	"damage": 50,
	"lvl" : 35,
	"skill_name" : "���»���",
	"damage_type":	"����"
]),
([      "action":"$Nʹ������ɫ���ࡹ���������á������ƾ�������ֱ�Ķ���������$wȴ������Ϣ����$n��$l",
        "force" : 400,
        "dodge" : 15,
        "parry" : 15,
        "damage": 70,
        "lvl" : 45,
        "skill_name" : "��ɫ����",
        "damage_type":  "����"
]),
([	"action":"$N��̤���Ƿ�λ�������ߣ�һ�С���ٲ���������������$w����̹Ǻ��磬��$n���뵶����������",
	"force" : 450,
        "dodge" : 20,
	"parry" : 20,
	"damage": 85,
	"lvl" : 60,
	"skill_name" : "��ٲ���",
	"damage_type":	"����"
]),
});

int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

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
                if(level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        int i, level, level2, level3, damage;
	string action_msg;
	level   = (int) me->query_skill("liangyi-dao",1);
        level2 = (int) me->query_skill("zixia-gong",1);
        level3 = (int) me->query_skill("blade",1);
	if( me->query_temp( "zixia/using" ) == "blade" && me->query_temp("zixia/lvl") >= 2 ){
		i = random(sizeof(action)); 
		if( me->query_temp("perform/zixia") ) { 
			me->delete_temp("perform/zixia"); 
			action_msg = MAG"$N������ϼ�񹦣���ʱ�ӵ��ɷ磬��������������ʩ�������������еļ��£�����ԴԴ�����ĵݳ���\n"NOR; 
		} else action_msg = action[i]["action"]; 
		if ( wizardp(me) ) tell_object(me, HIG"\n���õ��Ƿ����ǵ����е�"+action[i]["skill_name"]+"�˺�����"+action[i]["damage"]+"��\n"NOR);
		if ( !me->query_temp("perform/zixia") && random ( level3 ) > random ( level2 ) )
			damage = ( level3 + level2 - 350 )/ ( 10 + random ( 10 ) );
		if ( wizardp(me) ) tell_object(me, HIG"δ����ϼ���˺�����"+action[i]["damage"]+"   ����ϼ����˺���"+(action[i]["damage"]+damage)+"    ������"+damage+"���˺�����\n"NOR);
		return (["action": action_msg, 
			 "damage": action[i]["damage"]+damage, 
			 "force" : action[i]["force"]+level*3, 
 			 "dodge" : action[i]["dodge"], 
			 "parry" : action[i]["parry"], 
			 "damage_type": action[i]["damage_type"], 
//			 "post_action": (: call_other,  SKILL_D("zixia-gong"), "guard_crush" :) 
		]); 
	} 
        for(i = sizeof(action); i > 0; i--)
                if(level > action[i-1]["lvl"])
                        return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
	object weapon;

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if ((int)me->query("jingli") < 50)
		return notify_fail("��ľ��������������ǵ�����\n");
	me->receive_damage("jingli", 25);
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"liangyi-dao/" + action;
}
