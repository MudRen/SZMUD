// Code of ShenZhou
//tianluo-diwang.c ���޵����� by maco 1999/1/17

#include <combat.h>
#include <ansi.h>
inherit SKILL;

int ke_qz(object me, object victim, object weapon, int damage);

mapping *dodge_action = ({
([      "action" : "$n��֫��ڣ�����һ��ջ��ڷ���΢΢һ����б���Ʋ������ѱܿ���\n",
        "dodge"  : 10
]),
([      "action" : "$nչ���Ṧ�����������缲���ӵأ�����������˲Ϣ֮��������Σ������Բ֮����Ų��Ծ����$N�޴ӽ��У�\n",
        "dodge"  : 20
]),
([      "action" : "$n˳��$N���Ʊܹ�������һ�ϣ���Ȼ��$N���һ�Ӷ������������񣬲���΢�죬�����ÿ���\n",
        "dodge"  : 30
]),
([      "action" : "$n�Ų���ӯ������Ѹ�ݣ��Ṧʩչ��Բת���⣬��֮�죬���Ѱ������ز��Ų���������ɵرܹ�$N��һ�С�\n",
        "dodge"  : 40
]),
([      "action" : "ȴ��$n�������磬����΢��������ƮƮ�����ǻ������У���������ر��˿�ȥ������Ʈ�����ף��仯�򷽣�\n",
        "dodge"  : 50
]),
([      "action" : "$nչ����Ĺ���Ṧ��������ȥ��б�ܼ�ת���ݺ�Ʈ������$N����ȷ�����ֵķ�λ��\n",
        "dodge"  : 60
]),
([      "action" : "$n�½󵱷磬ƮƮȻ�����˷��ȥ��Խ��Խ����ݣ�������ȥ������ȫ��������$N������������׽����\n",
        "dodge"  : 70
]),
([      "action" : "$n˫��һ�ǣ������ڿն����������Ӵ���һ�㣬��س���ƽƽ�ӹ�������֮�£�$N�������ƺ�������һ����\n",
        "dodge"  : 80
]),
([      "action" : "$nչ����Ĺ���Ṧ���������ߣ�һ��ţ�������磬$N��Ȼ���治�ϣ����°������壡\n",
        "dodge"  : 90
]),
([      "action" : "$n������ǰһͦ����Ҳ�ƵĻ��˿�ȥ������$n������������ת���ۣ�ʵ��˲Ϣ֮��ͣ����$N�������ʽһһ��գ�\n",
        "dodge"  : 100
]),
});

mapping *action = ({
([      "action" :"$N������죬��һ��һʽ������������Գɶ��䣬��������΢����������$n$l����",
        "force" : 160,
        "dodge" : 0, 
        "parry" : -10, 
        "damage": 15,
	"post_action": (: ke_qz :),	
        "damage_type" : "����"
]),
([      "action" :"$N�����ַ������������ᣬ�Ʒ���$n�����޾�չ�˿�������ö�ˣ�����Ī��",
        "force" : 220,
        "dodge" : 10, 
        "parry" : -5, 
        "damage": 20,
	"post_action": (: ke_qz :),	
        "damage_type" : "����"
]),
([      "action" :"$N˫�ֻӳ�������һ�գ�����һ�ģ���$n������ȥ·ȫ����ס��˫����ߵ����Ǳ��ģ�$n���������ѳ���Ӱ��������֮��",
        "force" : 260,
        "dodge" : 25, 
        "parry" : -5, 
        "damage": 25,
	"post_action": (: ke_qz :),	
        "damage_type" : "����"
]),
([      "action" :"$N˫�۷��裬��ֻ�������ƻ�����ǧ��ǧ�ƣ���$n�����Ų���Σ�ʼ�ձ�����$N����Χ�ɵ�Ȧ����",
        "force" : 280,
        "dodge" : 20, 
        "parry" : -15, 
        "damage": 30,
	"post_action": (: ke_qz :),	
        "damage_type" : "����",
]),

([      "action" :"$N˫��һ����ƾ���ȥ����·�����޵����ơ����Ʒ�ʹ�������������ޱȣ������䲻���ۣ����ַ�Ѹ��������һ�С�����һ�ƣ�Ʈ���鶯֮��",
        "force" : 320,
        "dodge" : 20, 
        "parry" : -15, 
        "damage": 30,
	"post_action": (: ke_qz :),	
        "damage_type" : "����",
]),
([      "action" :"$N���ֿ���ޱȣ�������֮�����Ǳ���޷���ץ��˺�������ù�������С�������м��ԡ����޵����ơ����Ʒ�����������",
        "force" : 350,
        "dodge" : 15, 
        "parry" : -5, 
        "damage": 35,
	"post_action": (: ke_qz :),	
        "damage_type" : "����"
]),
});

int valid_enable(string usage) { return usage=="strike" || usage=="parry" || usage=="dodge";}

int valid_combine(string combo) { return combo=="meinu-quan"; }

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("�����޵����Ʊ�����֡�\n");
        if ((int)me->query_skill("yunu-xinjing", 1) < 20)
          return notify_fail("�����Ů�ľ���򲻹����޷�ѧ���޵����ơ�\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        int i, level;
        level   = (int) me->query_skill("tianluo-diwang",1);
        return action[random(sizeof(action))];
}

mapping query_dodge_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(dodge_action);
        level   = (int) me->query_skill("tianluo-diwang");

        if (level < 80 )
                zhaoshu--;

        if (level < 60 )
                zhaoshu--;

        if (level < 40 )
                zhaoshu--;

        return dodge_action[random(zhaoshu)];
}

int practice_skill(object me)
{
        if ((int)me->query("jingli") < 50)
                return notify_fail("��ľ���̫���ˡ�\n");
        if ((int)me->query("neili") < 50)
                return notify_fail("�������̫���ˡ�\n");
        me->receive_damage("jingli", 25, "����͸֧�������ˡ�");
        me->add("neili", -10);
       
       return 1;
}

string query_dodge_msg(string limb)
{
        object me, ob;
        mapping action;

        me = this_player();
        action = query_dodge_action(me, ob);

        return action["action"];
}


string perform_action_file(string action)
{
       return __DIR__"tianluo-diwang/" + action;
}


int ke_qz(object me, object victim, object weapon, int damage)
{
        string str;
        int skill,v_parry;
	skill = me->query_skill("tianluo-diwang");

        if(skill > 80 ){

	if (damage==RESULT_DODGE
	&& victim->query_skill_mapped("dodge") == "jinyangong" 
	&& (random(skill)/2 + skill/2) > random(victim->query_skill("jinyangong"))) {

	message_vision(HIW"��֪$N��Ϥ���㹦����������������Ź�������������$n����֮������ϵ�˿˿��ۣ�$n��$Pһ������������ˤ����\n"NOR, me,victim );

	victim->receive_damage("qi", random(skill)+skill*2);
	victim->start_busy(8);

        str = COMBAT_D->status_msg((int)victim->query("qi") * 100 /(int)victim->query("max_qi"));
        message_vision("( $N"+str+")\n", victim);	
	}
	else if (damage==RESULT_PARRY 
	&& (victim->query_skill_mapped("parry") == "chunyang-quan" || victim->query_skill_mapped("parry")== "sanhua-juding" ||victim->query_skill_mapped("parry") == "quanzhen-jian" || victim->query_skill_mapped("parry")== "duanyun-bian" ) 
	&& (random(skill)/2 + skill/2) > random(victim->query_skill("parry"))) {

	message_vision(HIW"����$N��ȫ�����书������Ϥ������һ������ץס$p�����������ͣ���$pˤ�˳�ȥ��\n"NOR, me,victim );
	victim->start_busy(8);
	victim->receive_damage("qi", random(skill)+skill*2);
	victim->start_busy(random(1));
        str = COMBAT_D->status_msg((int)victim->query("qi") * 100 /(int)victim->query("max_qi"));
        message_vision("( $N"+str+")\n", victim);	
		}
	}
}
