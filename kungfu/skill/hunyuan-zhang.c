// Code of ShenZhou
// hunyuan-zhang.c ��Ԫ��
// qfy July 9, 1996

#include <ansi.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$N˫���ڹ����������⼲�ƣ�һʽ�����Ƴ�ᶡ�����$n���ؿ�",
	"force" : 145,
        "dodge" : 5,
	"parry" : 15,
	"damage_type" : "����",
	"lvl" : 0,
	"skill_name" : "���Ƴ��"
]),
([	"action" : "$N������̧������ת������б��������ʹ�����׺���ա�����$n���ʺ�",
	"force" : 160,
        "dodge" : 5,
	"parry" : 15,
	"weapon": "����",
        "damage_type" : "����",
	"lvl" : 12,
	"skill_name" : "�׺����"
]),
([	"action" : "$Nʹһʽ���ƶ����롹��ת��̧�⣬����$n������",
	"force" : 180,
        "dodge" : 8,
	"parry" : 10,
        "damage_type" : "����",
	"lvl" : 18,
	"skill_name" : "�ƶ�����"
]),
([	"action" : "$N����ץ��$n��$l����ȭ�����󷢣�һʽ�����ɴ�䡹����ͼ����$n�Ĺ���",
	"force" : 210,
        "dodge" : -5,
	"parry" : 15,
        "damage_type" : "����",
	"lvl" : 24,
	"skill_name" : "���ɴ��"
]),
([	"action" : "$Nʹ�����������������Ⱥ�ŵ�����ϣ���ȭ������ȭ���϶�����Ȼ����$n$l",
	"force" : 245,
        "dodge" : 10,
	"parry" : 10,
        "damage_type" : "����",
	"lvl" : 30,
	"skill_name" : "������"
]),
([	"action" : "$N����Ծ��һʽ���ޱ���ľ����˫�ƻó�������Ӱ������$n���������",
	"force" : 290,
        "dodge" : 15,
	"parry" : 15,
        "damage_type" : "����",
	"lvl" : 36,
	"skill_name" : "�ޱ���ľ"
]),
([	"action" : "$N����΢�����ȹ�������ȭ���������°���һ�С���ɽ��ˮ��������$n��$l",
	"force" : 335,
        "dodge" : 10,
	"parry" : 15,
        "damage_type" : "����",
	"lvl" : 42,
	"skill_name" : "��ɽ��ˮ"
]),
([	"action" : "$Nʹһʽ���������á������ƻ�������ֱ�Ķ��������������ػ���$n��$l",
	"force" : 370,
        "dodge" : 10,
	"parry" : 15,
        "damage_type" : "����",
	"lvl" : 48,
	"skill_name" : "��������"
]),
([	"action" : "$N�������»��أ�һʽ��������ơ�����Ȼ�������ƻ���Ϊ��������$n$l",
	"force" : 400,
        "dodge" : 15,
	"parry" : 15,
        "damage_type" : "����",
	"weapon": "˫��",
	"lvl" : 54,
	"skill_name" : "�������"
]),
([	"action" : "$Nһʽ���������졹�����������������׵س��$n�����ƻ������ֱ��$n��$l",
	"force" : 450,
        "dodge" : 10,
	"parry" : 10,
        "damage_type" : "����",
	"lvl" : 60,
	"skill_name" : "��������"
])
});

int valid_enable(string usage) { return usage=="strike" ||  usage=="parry"; }

int valid_combine(string combo) { return combo=="pishi-poyu"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����Ԫ�Ʊ�����֡�\n");
	if ((int)me->query_skill("zixia-gong", 1) < 20)
		return notify_fail("�����ϼ����򲻹����޷�ѧ��Ԫ�ơ�\n");
	if ((int)me->query("max_neili") < 100)
		return notify_fail("�������̫�����޷�����Ԫ�ơ�\n");
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
	level = (int)me->query_skill("hunyuan-zhang", 1);
        level2 = (int) me->query_skill("zixia-gong",1);
        level3 = (int) me->query_skill("strike",1);
	if( me->query_temp("zixia/lvl") && me->query_temp("zixia/lvl") % 5 == 1){
		i = random(sizeof(action)); 
		action_msg = action[i]["action"]; 
		if ( wizardp(me) ) tell_object(me, HIG"\n���õ��ǻ�Ԫ���е�"+action[i]["skill_name"]+"�˺�����"+action[i]["damage"]+"��\n"NOR);
		if ( !me->query_temp("perform/zixia") && random ( level3 ) > random ( level2 ) )
			damage = ( level3 + level2 - 350 )/ ( 10 + random ( 10 ) ) + me->query_temp("zixia/lvl");
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
	if ((int)me->query("jingli") < 30)
		return notify_fail("��ľ���̫���ˡ�\n");
	if ((int)me->query("neili") < 20)
		return notify_fail("���������������Ԫ�ơ�\n");
	me->receive_damage("jingli", 25, "����͸֧��������");
	me->add("neili", -5);
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        int time, level, old_time;

	if ( me->query_temp("wuji") ) {  
        	level = me->query_skill("hunyuan-zhang", 1);
        	old_time = victim->query_condition("hyz_damage");

		if ( victim->query_temp("last_enemy") != me->query("id") ) {
			victim->set_temp("last_enemy", me->query("id") );
			victim->delete("huashan/enemy");
		}

		if ( !victim->query("huashan/enemy") )
			victim->set("huashan/enemy", me->query_skill("hunyuan-zhang", 1)*3/4);

        	time = level/20 + old_time;
//		me->delete_temp("wuji");
		call_out("delete_wuji", 1, me);
        	victim->apply_condition("hyz_damage", time);
		tell_object(victim,HIR"��ֻ����һ�ɻ��ȵ�����Ϯ������ڸ������������ޱȣ�\n"NOR);
	}
}

void delete_wuji(object me) 
{
	me->delete_temp("wuji");
}
string perform_action_file(string action)
{
        return __DIR__"hunyuan-zhang/" + action;
}
