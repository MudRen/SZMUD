//Cracked by Roath
//chunyang.c ����ȭ
//sdong 07/98 

#include <ansi.h>
inherit SKILL;
int chunyangwuji(object me, object victim, object weapon, int damage);
mapping *action = ({
([      "action" : "$Nʩչ�����ײ�ʳ���������ڿ�Ծ�������ſ������ɺ��ٿգ���������ȭ����ͻȻ������ǰ��̽������$n$l",
	"force" : 150,
	"dodge" : 5,
		"parry" : 10,
	"lvl" : 0,
	"skill_name" : "���ײ�ʳ",
	"damage_type" : "����"
]),
([	"action" : "$N����ʹ��������Ϸ�꡹��������μ��У���ȭ��ಡ���һ�����Ʒ����ʹ�����������$n��$l",
	"force" : 180,
	"dodge" : -5,
	"parry" : 15,
	"lvl" : 10,
	"skill_name" : "����Ϸ��",
	"damage_type" : "����"
]),
([	"action" : "$N���������Ȼŭ��һ������ǰһ��������˫�ơ�Ұ���ϲۡ������ŷ���֮����������$n",
	"force" : 220,
	"dodge" : 10,
	"parry" : 10,
	"lvl" : 20,
	"skill_name" : "Ұ���ϲ�",
	"damage_type" : "����"
]),
([	"action" : "$N�ڿշ���һʽ���ڻ����ġ�����ȭ����$n�ؿ��������͵���ȥ",
	"force" : 240,
	"dodge" : 15,
	"parry" : 10,
	"lvl" : 30,
	"skill_name" : "�ڻ�����",
	"damage_type" : "����"
]),
([	"action" : "$N��ǰһ���ͳ壬һʽ������Ϸ�项��˫ȭͻȻͬʱ������ֱȡ$n��˫Ŀ",
	"force" : 300,
	"dodge" : 10,
	"parry" : 15,
	"lvl" : 40,
	"skill_name" : "����Ϸ��",
	"damage_type" : "����"
]),
([	"action" : "$N�������һ�������ñܿ�$n�Ĺ�����ͻȻһת������һ�С����뷴�ҡ���һ��Ťס$n�۰���ȭȴ����$n������",
	"force" : 360,
	"dodge" : 15,
	"parry" : 10,
	"lvl" : 50,
	"skill_name" : "���뷴��",
	"damage_type" : "����"
]),
([	"action" : "$N��ǰһ����������ʹ����������ʳ����һ�ǹ�ȭ������һ�еص���$n",
	"force" : 420,
	"dodge" : 15,
	"parry" : 10,
	"lvl" : 60,
	"skill_name" : "������ʳ",
	"damage_type" : "����"
]),
([	"action" : "$N������֮�����ͺ�һ����ͻȻһʽ���������ơ�����ȭ��ĳ�죬Ю���ſ�磬�����Ƶ絷��$n$l",
	"force" : 510,
	"dodge" : 15,
	"parry" : 15,
	"lvl" : 70,
	"skill_name" : "��������",
	 "damage_type" : "����"
])
});

int valid_enable(string usage) { return  usage=="cuff" || usage=="parry"; }

int valid_combine(string combo) { return combo=="sanhua-juding"; }

int valid_learn(object me)
{
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("������ȭ������֡�\n");
	if ((int)me->query_skill("xiantian-gong", 1) < 15)
		return notify_fail("����������칦��򲻹����޷�ѧ����ȭ��\n");
	if ((int)me->query("max_neili") < 50)
		return notify_fail("�������̫�����޷�������ȭ��\n");
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
	int i, j, level, st_lvl;
	mapping perform;
	level = (int)me->query_skill("chunyang-quan",1);
	st_lvl = me->query("shentong");
	if (st_lvl > 60) st_lvl -= 60;
	else st_lvl = 0;
	if( mapp(perform = me->query_temp("perform")) && !undefinedp(perform["chunyangwuji"]) 
	  && intp(i = perform["chunyangwuji"]) && i >= 1 && i <= me->query_temp("cyq-wuji/max_times") ) { 
		j = random(sizeof(action)); 
		if (wizardp(me)) tell_object(me,HIG"�����ǡ������޼����ĵ�"+chinese_number(i)+"�С�\n"NOR);
		return (["action": action[j]["action"], 
			"damage": level * 3 / 2 + st_lvl*3, 
			"force" : me->query_skill("force")/2, 
			"damage_type": action[j]["damage_type"], 
			"post_action": (: chunyangwuji :) ]); 
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
		return notify_fail("�����������������ȭ��\n");
	me->receive_damage("jingli", 25, "����͸֧��������");
	me->add("neili", -5);
	return 1;
}

string perform_action_file(string action)
{
	return __DIR__"chunyang-quan/" + action;
}

void finish_chunyangwuji(object me, int skill_lvl) 
{ 
	me->set_temp("apply/attack", me->query_temp("cyq-wuji/old_attack")); 
	me->set_temp("apply/damage", me->query_temp("cyq-wuji/old_damage")); 
	me->set_temp("apply/speed", me->query_temp("cyq-wuji/old_speed")); 
	me->delete_temp("perform/chunyangwuji"); 
	me->delete_temp("cyq-wuji"); 
	me->start_busy(2+random(2)); 
	if (wizardp(me)) if (wizardp(me)) tell_object(me,HIG"�������޼����Ѿ����С�\n"NOR);
} 
int chunyangwuji(object me, object victim, object weapon, int damage) 
{        
	string msg; 
	int cyq_wuji = me->query_temp("perform/chunyangwuji"); 
	int skill_lvl = me->query_skill("chunyang-quan", 1)/4; 
	int exp_m = me->query("combat_exp", 1);
	int exp_t = victim->query("combat_exp", 1);
	if (wizardp(me)) 
		write("attack:"+me->query_temp("apply/attack")+",damage:"+me->query_temp("apply/damage")+",speed:"+me->query_temp("apply/speed")+",times:"+me->query_temp("perform/chunyangwuji")+"\n"); 
	if( damage > 0 ) {
		if( victim->query("qi") <= 0 ) {
			msg = HIR"\n\tֻ��$Nȭ�����ͣ�����"+chinese_number(cyq_wuji)+"�з���ʱ��$n�Ѿ��ܲ�ס$N��ȭ�磡\n"NOR;
 			if( me->is_killing(victim->query("id")))
 				victim->receive_wound("qi", victim->query("max_qi")+100,"��"+ me->name()+"�������޼�����ǿ������������");
			message_vision(msg , me, victim); 
			finish_chunyangwuji(me, skill_lvl); 			  
			return 1;
		}else msg = HIY"\n\t$Nһ�����У�����$n��Ӧ��"+chinese_number(cyq_wuji+1)+"���Ѿ�����ɽ����֮����$n������\n"NOR;
	}else{
		if( random(exp_m) < random(exp_t / 2) ){
			msg = HIW"\n\t$Nһ�в��У���ʱ�����Լ��������������޼���������ʽ��Ҳʹ��������\n"NOR;
			message_vision(msg , me, victim); 
			finish_chunyangwuji(me, skill_lvl); 			  
			return 1;
		}else{
			msg = HIY"\n\t$Nһ�в��У���ת���ν���"+chinese_number(cyq_wuji+1)+"��Ѹ�ٵݳ����ٶȽ�ǰ���ҷ������\n"NOR;
			me->add_temp("apply/speed", skill_lvl / 4);
			me->add_temp("apply/damage", skill_lvl / 3);
		}
	}
	if( cyq_wuji >= me->query_temp("cyq-wuji/max_times")){
		msg = HIY"\n\t$Nһ������$n��������"+chinese_number(cyq_wuji)+"�У�����ȭ��������ʵ���ɱ����ӣ�\n"NOR;
		message_vision(msg , me, victim); 
		finish_chunyangwuji(me, skill_lvl); 
		return 1;
	}
	me->add("neili", -skill_lvl / 3); 
	me->add("jingli", -skill_lvl / 4); 
	me->add_temp("perform/chunyangwuji", 1); 
	me->add_temp("apply/attack", skill_lvl / 2); 
	me->add_temp("apply/damage", -skill_lvl / 2); 
	message_vision(msg , me, victim); 
	COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
	return 1;
} 
