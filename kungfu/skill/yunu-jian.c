// Code of ShenZhou
// yunu-jian ��Ů����
// maco �汾  1999/1/17  (�����ţ�������)

#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit F_DBASE;
inherit F_SSERVER;

int ke_qz(object me, object victim, object weapon, int damage);

mapping *action = ({
([      "action":"$N����$w���϶��£�һ�С���ǰ���¡���$w���������ʻ���չ���У����ػ�����ֻ�ϵ�$n�ۻ����ң��벻֪���н��Ӻδ�����",
        "force" : 160,
        "dodge" : 5,
        "parry" : 5,
        "damage": 15,
        "lvl" : 0,
        "skill_name" : "��ǰ����",
	"post_action": (: ke_qz :),	
        "damage_type":  "����"
]),
([      "action":"$N$w΢�ڣ�һ�С����ٰ�����������ѣ����˴�Լ���������¼����Ȼ���ҷ緶",
        "force" : 180,
        "dodge" : 5,
        "parry" : 5,
        "damage": 25,
        "lvl" : 9,
        "skill_name" : "���ٰ���",
	"post_action": (: ke_qz :),	
        "damage_type":  "����"
]),
([      "action":"$Nһ�С�ɨѩ��衹��������ţ����ζ���������Ͷ���ƮƮ�г���֮�룬$w���������潣�𣬴���$n$l",
        "force" : 200,
	"dodge" : 10,
        "parry" : 10,
        "damage": 60,
        "lvl" : 15,
        "skill_name" : "ɨѩ���",
	"post_action": (: ke_qz :),	
        "damage_type":  "����"
]),
([      "action": "$Nһ�С�����С�á�������$w������������ָ�����������ƣ�������������$n$l������֮�֣�������˼",
        "force" : 240,
	"dodge" : 15,
        "parry" : 15,
        "damage": 40,
        "lvl" : 25,
        "skill_name" : "����С��",
	"post_action": (: ke_qz :),	
        "damage_type":  "����"
]),
([      "action":"$N�Ų�΢��������̤������������һ�С����¶��ġ�������Ѹ�ݣ��鶯��ã������������������ҷ������ף���ʽ���",
        "force" : 280,
	"dodge" : 8,
        "parry" : 8,
        "damage": 70,
        "lvl" : 30,
        "skill_name" : "���¶���",
	"post_action": (: ke_qz :),	
        "damage_type":  "����"
]),
([      "action":"$N����΢�ڣ�һ�С��رߵ��ס���$w����$n$l����һ��ȥ�ƿ����ǳ۵��������ҷ��˴�Լ��Ʈ���ޱ�",
        "force" : 300,
        "dodge" : 10,
        "parry" : 10,
        "damage": 55,
        "lvl" : 35,
        "skill_name" : "�رߵ���",
	"post_action": (: ke_qz :),	
        "damage_type":  "����"
]),
([      "action":"$N$w���Ʈ���������̬ƮƮ���ɣ�������$n��$l�������㣬ȴ��һ�С�С԰�վա�",
        "force" : 310,
        "dodge" : 15,
        "parry" : 15,
        "damage": 65,
        "lvl" : 45,
        "skill_name" : "С԰�վ�",
	"post_action": (: ke_qz :),	
        "damage_type":  "����"
]),
([      "action":"$N�������ܣ�һʽ������ҹ��������̨�γ�����·��Խ��Խ��������ȴ�ް�������$wʹ�þ���Ѹ������ȥ����",
        "force" : 320,
	"dodge" : 5,
        "parry" : 5,
	"damage": 75,
	"lvl" : 55,
	"skill_name" : "����ҹ��",
	"post_action": (: ke_qz :),	
	"damage_type":  "����"
]),
([      "action":"$N$w����������ʮ������⣬����һ�С����¿��ˡ���ת˲�佣���ѽ�$n�ϰ���������",
        "force" : 330,
        "dodge" : 8,
	"parry" : 8,
        "damage": 80,
        "lvl" : 60,
        "skill_name" : "���¿���",
	"post_action": (: ke_qz :),	
        "damage_type":  "����"
]),
([      "action":"$N����һ����һʽ���ʱʻ�ü����$w΢΢�������ὣб��$n$l�������������ɰ���",
        "force" : 360,
	"dodge" : 10,
        "parry" : 10,
        "damage": 100,
        "lvl" : 70,
        "skill_name" : "�ʱʻ�ü",
	"post_action": (: ke_qz :),	
        "damage_type":  "����"
]),
([      "action":"$N��ƮƮ���������ˣ�һ�С����İ�ͨ����$w���ط�ת���̣���������ʮ���¼��죬�������ø��ֵķ�����ָҲ����˼���",
        "force" : 380,
	"dodge" : 10,
        "parry" : 10,
        "damage": 85,
        "lvl" : 75,
        "skill_name" : "���İ�ͨ",
	"post_action": (: ke_qz :),	
        "damage_type":  "����"
]),
([      "action":"$Nһ��$w����ʱ����������$w�������߰��������ߣ�һ�С����������$n�����������ǰ�ӹ�������$l��һ��",
        "force" : 400,
	"dodge" : 20,
        "parry" : 20,
        "damage": 100,
        "lvl" : 80,
        "skill_name" : "�������",
	"post_action": (: ke_qz :),	
        "damage_type":  "����"
]),
});

int valid_enable(string usage) { return usage == "sword" || usage == "parry" || usage == "zuoyou-hubo"; }

int valid_learn(object me)
{
        if ((int)me->query("max_neili") < 100)
                return notify_fail("�������������\n");
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
        object victim;
        level   = (int) me->query_skill("yunu-jian",1);
        if( !victim && me->is_fighting() ) victim = offensive_target(me);
	if (random(level) > 350 && random(me->query("neili")) > 1000 )
return ([      "action":HIW"$N���˼�������������������$w"+HIW"Ʈ����ȥ��������������һ·��Ů��������ʹ��Ӣ��ˬ�ʣ��������ˣ�"NOR,
        "force" : 450 + me->query_skill("yunu-jian"),
	"dodge" : 10,
        "parry" : 10,
        "damage": 100,
        "lvl" : 75,
	"post_action": (: ke_qz :),	
        "damage_type":  "����"
]);
	else if (random(level) > 250 && random(me->query("neili")) > 1000 ){
	if (me->query("gender")== "����") {
return ([      "action":HIG"$N�������飬�ж����������಻��������������������������ɣ����н��������ӵ�ȹ�����̬֮��"NOR,
        "force" : 450 + me->query_skill("yunu-jian"),
	"dodge" : 10,
        "parry" : 10,
        "damage": 100,
        "lvl" : 75,
	"post_action": (: ke_qz :),	
        "damage_type":  "����"
]);
}
	else {
return ([      "action":HIY"$N�������ߣ�$w"+HIY"��һ��δ�ϣ������������г���ʱ�������󣬽��еֵ�ʱ����ת�ң����ƽ��ǽ��������ˣ������ⲻ������$n��֮������Ȼ��"NOR,
        "force" : 450 + me->query_skill("yunu-jian"),
	"dodge" : 10,
        "parry" : 10,
        "damage": 100,
        "lvl" : 75,
	"post_action": (: ke_qz :),	
        "damage_type":  "����"
]);
	}
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
                return notify_fail("��ľ�����������Ů������\n");
        me->receive_damage("jingli", 25, "����͸֧�������ˡ�");
        return 1;
}


string perform_action_file(string action)
{
        return __DIR__"yunu-jian/" + action;
}

int ke_qz(object me, object victim, object weapon, int damage)
{
        string str;
        int skill,v_parry;
	object weapon2;
	weapon2 = victim->query_temp("weapon");
	skill = me->query_skill("yunu-jian");

        if(skill > 80 ){
	if (damage==RESULT_DODGE
	&& victim->query_skill_mapped("dodge") == "jinyangong" 
	&& (random(skill)/2 + skill/2) > random(victim->query_skill("jinyangong"))) {

	message_vision(HIW"��֪$N��Ϥ���㹦����������������Ź�������������$n����֮������ϵ�˿˿��ۣ�$n��$Pһ������������ˤ����\n"NOR, me,victim );
	victim->start_busy(8);
	victim->receive_damage("qi", random(skill)+skill);
        str = COMBAT_D->status_msg((int)victim->query("qi") * 100 /(int)victim->query("max_qi"));
        message_vision("( $N"+str+")\n", victim);	
	}
	else if (damage==RESULT_PARRY 
	&& ( objectp(weapon2 = victim->query_temp("weapon")) 
&& (((victim->query_skill_mapped("parry") == "quanzhen-jian" &&(string)weapon2->query("skill_type") == "sword")
|| (victim->query_skill_mapped("parry")== "duanyun-bian" && (string)weapon2->query("skill_type") == "whip")))
&& (random(skill)/2 + skill/2) > random(victim->query_skill("parry")) )) {

	message_vision(HIW"$nͻ���Լ�����"+weapon2->name()+HIW"��ͦ���죬����$N����"+weapon->name()+HIW"��˹�ȥ��һ��֮�£����������ضᡣ\n"NOR, me,victim );
	message_vision(HIW"˫�����ᣬֻ΢һ���֣�$NͻȻ�ſ�"+weapon->name()+HIW"��˫��ֱ�ۣ��ͻ�$nǰ�أ�ͬʱ"+weapon->name()+HIW"��������������˫��һ������·����������֮����\n"NOR, me,victim );
	if (random(me->query("combat_exp")) > random(victim->query("combat_exp"))){
	message_vision(HIW"$nֻ������"+weapon2->name()+HIW"�����ֺ��أ�����һ�У�\n"NOR, me,victim );
        weapon2->unequip();
	weapon2->move(environment(me));
	}
        weapon->unequip();
        me->add_temp("apply/speed", skill*10);
        me->add_temp("apply/damage", skill*10);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
        me->add_temp("apply/speed", -skill*10);
        me->add_temp("apply/damage", -skill*10);
        weapon->wield();
        message_vision("\n$N��Ӧ��ݣ����ѳ���"+weapon->name()+"�������У�\n", me,victim );
        me->add("neili",-40);
}
	else if (damage==RESULT_PARRY 
	&& ( !objectp(weapon2 = victim->query_temp("weapon")) 
&& ((victim->query_skill_mapped("parry") == "quanzhen-jian" )
|| (victim->query_skill_mapped("parry")== "chunyang-quan")
|| (victim->query_skill_mapped("parry")== "sanhua-juding")
|| (victim->query_skill_mapped("parry")== "duanyun-bian"))
&& (random(skill)/2 + skill/2) > random(victim->query_skill("parry")) )) {

	message_vision(HIW"����$n�漴ͦ��һ�̣��ؽ��ȿ���׼��ֱ��$n���ƣ�����ȫ���书����������֮����$n���´󾪣���æ���֣��������ƣ�$N����������\n"NOR, me,victim );
        me->add_temp("apply/speed", skill*10);
        me->add_temp("apply/damage", skill*10);
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
        me->add_temp("apply/speed", -skill*10);
        me->add_temp("apply/damage", -skill*10);
	me->add("neili",-40);
		}
	}
}


mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int level;
        level  = (int) me->query_skill("yunu-jian",1);

	if( victim->query_temp("sanhua") ) {
	victim->delete_temp("sanhua");
	victim->start_busy(1+random(1));
	victim->add("neili",-200);
	victim->receive_wound("qi", level*3+random(level));
	victim->receive_damage("qi", level*10);

	return HIR"$nͻȻ˫Ŀֱ�ɣ����һ��������ˤ�����������˼��صİ��ˣ����커������Ȼ���ƣ�\n"NOR;
			}
			
}