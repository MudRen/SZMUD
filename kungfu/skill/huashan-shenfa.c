// Code of ShenZhou
// huashan-shenfa.c ��ɽ��
// qfy July 8, 1996

#include <ansi.h>
#include <combat.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$n�������٣��������࣬һʽ���������᡹��ʱ�ܿ���$N���������ơ�\n",
        "dodge"  : 10
]),
([      "action" : "$n�����Ʈ����������ݣ����ɵ�һʽ��������ϼ����������$N�Ĺ��ơ�\n",
        "dodge"  : 20
]),
([      "action" : "$nһʽ���໲������������ƮƮ���λζ���һת�ۼ���Ƶ���$N�����\n",
        "dodge"  : 30
]),
([      "action" : "$n��ͷ������ȭһʽ��ȴ����ɡ���������󻬳�����$N�Ĺ��ƻ������Ρ�\n",
        "dodge"  : 40
]),
([      "action" : "$nʹ�������ճ���������ֱԾ���ڰ���л�Ϊ�������ա���Ʈ�䵽һ�ԡ�\n",
        "dodge"  : 50
]),
([      "action" : "$nһ�С��������ǡ����������Ҽ��ٻζ����ó�������Ӱ�����ݵ��ƽ�$N�Ĺ��ơ�\n",
        "dodge"  : 60
]),
([      "action" : "$n��ЦƮ��ʹ�����������Ρ������λó�һ����Ӱ����ƮƮ������$N����ࡣ\n",
        "dodge"  : 70
]),
([      "action" : "$n��������һ�С��������롹������������$N��ת��ʹ���޴����֣����Ʋ������ơ�\n",
        "dodge"  : 80
])
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("huashan-shenfa");

        if (level < 60 )
                zhaoshu--;

        if (level < 50 )
                zhaoshu--;

        if (level < 40 )
                zhaoshu--;

        return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
        return usage == "dodge" || usage == "move";
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
        return action[random(sizeof(action))]["action"];
}

int practice_skill(object me)
{
        if( (int)me->query("jingli") < 40 )
                return notify_fail("��ľ���̫���ˣ���������ɽ����\n");
        me->receive_damage("jingli", 30, "����͸֧��������");
        return 1;
}


/*  // remove special dodge // maco
int is_special()
{
	if (me->query_temp("hssf-yanhui",1))
        	return 1;
        else return 0;
}

mixed hit_by(object me, object victim, int damage)
{
        int ap, dp, level;
        object weapon = me->query_temp("weapon");
        mapping prepare;
        string result, attack_skill;

        if ( !victim->query_temp("hssf-yanhui") || !living(victim) )
                return damage;

        dp = COMBAT_D->skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
        if( victim->query_skill_mapped("parry") == "dugu-jiujian" )
                dp += COMBAT_D->skill_power(victim, "parry", SKILL_USAGE_DEFENSE);

        ap = COMBAT_D->skill_power(me, "dodge", SKILL_USAGE_DEFENSE);
        prepare = me->query_skill_prepare();
        if( !prepare ) prepare = ([]);

        if( objectp(weapon) ) attack_skill = weapon->query("skill_type");
        else switch( sizeof(prepare) )
        {
                case 0: attack_skill = "unarmed"; break;
                case 1: attack_skill = (keys(prepare))[0]; break;
                case 2: attack_skill = (keys(prepare))[me->query_temp("action_flag")]; break;
        }

        ap += COMBAT_D->skill_power(me, attack_skill, SKILL_USAGE_ATTACK);

        ap /= 100;
        dp /= 100;

        if ( random(ap+dp) > ap ) {
                result = HIR "$n��������һ������һ�ߣ�$N����ʧ�֣�һʱ�е���æ���ң�\n";
                result += "$n׽��ʱ�������̶�$N�������ƣ�\n" NOR;
                me->start_busy( (int)victim->query_skill("huashan-shenfa", 1)/50 );
                victim->add("neili", -20);
                victim->add("jingli", -20);
                damage = 0;

                return ([ "result" : result, "damage" : damage ]);
        }
        else if ( random(ap+dp) > ap ) {
                result = HIR "$n��������һ������һ�ߣ�$Nһ��ʧ�֣�����֮����¶������\n";
                result += "$n׽��ʱ�������̶�$N�������ƣ�\n" NOR;
                COMBAT_D->do_attack(victim, me, victim->query_temp("weapon"));
                victim->add("neili", -10);
                victim->add("jingli", -20);
                damage = 0;

                return ([ "result" : result, "damage" : damage ]);
        }
        else if ( random(ap+2*dp) > ap ) {
                result = HIR "$n��������һ������һ�ߣ���Ȼ��������رܿ���$N�Ĺ�����\n" NOR;
                victim->add("jingli", -20);
                damage = 0;

                return ([ "result" : result, "damage" : damage ]);
        }
        else if ( random(ap+3*dp) > ap ) {
                result = HIR "$n��������һ������һ�ߣ���$N������жȥ��롣\n" NOR;
                victim->add("jingli", -10);
                damage /= 5;
        
                return ([ "result" : result, "damage" : damage ]);
        }
        else 
                return damage;
}*/
string perform_action_file(string action)
{
        return __DIR__"huashan-shenfa/" + action;
}
