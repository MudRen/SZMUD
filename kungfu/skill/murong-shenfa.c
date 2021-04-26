// Code of ShenZhou
// murong-shenfa.c 

#include <ansi.h>
#include <combat.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$n�����Զ�����$N�Ĺ�����Χ��Ʈ���ȥ���㿪��$N�Ĺ�����\n",
        "dodge"  : 10
]),
([      "action" : "$nһ�����λ�λ��$N��ʱʧȥ�˹���Ŀ�꣡\n",
        "dodge"  : 20
]),
([      "action" : "$n���Ц�ݣ���������֮���������ܹ�$N����ʽ��\n",
        "dodge"  : 30
]),
([      "action" : "$n����һ�����У����Ӷ�Ȼ���˺����ߣ�ʹ$N�Ĺ����������ڿմ���\n",
        "dodge"  : 40
]),
([      "action" : "����$n���ζ����Ѿ�ʧȥ���ټ���\n",
        "dodge"  : 50
]),
([      "action" : "$n������ת������ܹ�$N������һ����\n",
        "dodge"  : 60
]),
([      "action" : "$n����һ����$N��$n���½�Ҳû��������㣡\n",
        "dodge"  : 70
]),
([      "action" : "$nչ��Ľ����������ƮȻ���ɣ�$Nһʱ���޼ƿ�ʩ��\n",
        "dodge"  : 80
]),
([      "action" : "����$n���˿�ȥ��\n",
        "dodge"  : 90
]),
([      "action" : "$n���β����������ڹ���Ӳ�����������������磬���ñܿ�$N�Ĺ�����\n",
        "dodge"  : 100
]),
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("murong-shenfa");

        if (level < 120 )
                zhaoshu -= (119-level)/20;

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
        if ((int)me->query("neili") < 20)
                return notify_fail("�������̫���ˣ�������Ľ������\n");
        me->add("neili", -15);
        me->add("jingli", 25);
        return 1;
}

int is_special()
{
        return 1;
}

mixed hit_by(object me, object victim, int damage)
{
        int ap, dp, level;
        object weapon = me->query_temp("weapon");
        mapping prepare;
        string result, attack_skill;

        if ( victim->query_skill("murong-shenfa", 1) < 120
        || victim->query_skill_mapped("force") != "douzhuan-xingyi" 
        || victim->query_skill("douzhuan-xingyi", 1) < 120 
        || !living(victim) )
                return damage;

        dp = COMBAT_D->skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
        if( victim->query_skill_mapped("parry") == "canhe-zhi" )
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
                result = HIW "$n����΢΢һ����$N��$n���½�Ҳδմ����֣�\n";
                result += "$n����ң���ɰ������Ͼ����$N��ȥ��\n" NOR;
                me->start_busy( (int)victim->query_skill("murong-shenfa", 1)/50 );
                victim->add("neili", -20);
                victim->add("jingli", -20);
                damage = 0;

                return ([ "result" : result, "damage" : damage ]);
        }
        else if ( random(ap+dp) > ap ) {
                result = HIG "$n���Ц�ݣ���̬�����رܵ�һ�ԣ�$N��ǰ��¶������\n";
                result += "$nץס���ݼ��ŵĻ��ᣬ���̶�$N�������ơ�\n" NOR;
                COMBAT_D->do_attack(victim, me, victim->query_temp("weapon"));
                victim->add("neili", -10);
                victim->add("jingli", -20);
                damage = 0;

                return ([ "result" : result, "damage" : damage ]);
        }
        else if ( random(ap+2*dp) > ap ) {
                result = HIY "$n����ƮȻ���ɣ���Ȼ�Ӵ����ݵرܿ���$N�Ĺ�����\n" NOR;
                victim->add("jingli", -20);
                damage = 0;

                return ([ "result" : result, "damage" : damage ]);
        }
        else if ( random(ap+3*dp) > ap ) {
                result = HIM "$n���嶸Ȼ�����Ʈ�����ߣ�$N����ʽ������ա�\n" NOR;
                victim->add("jingli", -10);
                damage /= 5;
        
                return ([ "result" : result, "damage" : damage ]);
        }
        else 
                return damage;
}

