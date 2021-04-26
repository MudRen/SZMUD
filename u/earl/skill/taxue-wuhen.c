// Revised by Earl
// taxue-wuhen.c ̤ѩ�޺�
// Sep 9 5

#include <ansi.h>
#include <combat.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$nһʽ������ƽɳ�����������٣�������ǰ�߳���������Ȼ�����������ɵ�����һ��\n",
        "dodge"  : 10
]),
([      "action" : "$nһʽ���������𡹣������Ծ�������һ��һת����Ʈ��������֮�⡣\n",
        "dodge"  : 20
]),
([      "action" : "$nһʽ���������ڡ���������������������ĥ��������֮��ת��ж����$N��һ�С�\n",
        "dodge"  : 30
]),
([      "action" : "$nһʽ�����ɵ��ҡ���ֻ��$n���Ӻ�����˫��������һ�ţ����ӽ��Ƶ��������$N���Ѵ�$n���š�\n",
        "dodge"  : 40
]),
([      "action" : "$nһʽ����ѩ��̲�����ݸ߷��ͣ���������������Ʈ��������$N������룬ֻ�û������ء�\n",
        "dodge"  : 50
]),
([      "action" : "$nһʽ����˿���꡹��ͻȻ����һ�У���Ȼ�����ܾ��˵Ĵ򷨣���$N��æ���Ұ�ȫ����\n",
        "dodge"  : 60
]),
([      "action" : "$nһʽ��������ѩ�������в��ܣ�ֻ΢΢һ����$N���籩�������Ľ����㼴��ա�\n",
        "dodge"  : 70
]),
([      "action" : "$nһʽ������ǱԾ������Ȼ�����ΰ���ֱ��������ֱ��ӥ��������������ƮƮ������������֮�⡣\n",
        "dodge"  : 80
]),
([      "action" : "$nһʽ��̤ѩ�޺ۡ������μ�����ת�����¾ͻ�������֮�⡣\n",
        "dodge"  : 120
])
});

mapping query_action(object me, object weapon)
{
        int zhaoshu, level;

        zhaoshu = sizeof(action);
        level   = (int) me->query_skill("taxue-wuhen");

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
                return notify_fail("�������̫���ˣ�������̤ѩ�޺ۡ�\n");
                me->add("jingli", -25);
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

        if ( victim->query_skill("taxue-wuhen", 1) < 200
        || victim->query_skill_mapped("force") != "xuantian-wuji" 
        || victim->query_skill("xuantian-wuji", 1) < 200 
        || victim->query_skill("mantian-huayu", 1) < 200 
        || !living(victim) )
                return damage;

        dp = COMBAT_D->skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
        if( victim->query_skill_mapped("throwing") == "mantian-huayu" )
                dp += COMBAT_D->skill_power(victim, "throwing", SKILL_USAGE_DEFENSE);

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
                result =  "$n����һ������һ�ߣ�����������״��$N��ͷһ����һʱ�е���æ���ң�\n";
                result += "$n���л��ɳã����̶�$N�������ƣ�\n" ;
                damage = 0;

                return ([ "result" : result, "damage" : damage ]);
        }
        else if ( random(ap+dp/2) > ap ) {
                result = HIW "ֻ��$n��������,�Լ�����������Ӱ������裬����������״��$N��ͷһ����һʱ�е���æ���ң�\n" NOR;
                result += "$n׽��ʱ�������̶�$N�������ƣ�\n" ;
                COMBAT_D->do_attack(victim, me, victim->query_temp("weapon"));
                victim->add("jingli", random(-20));
                damage = 0;

                return ([ "result" : result, "damage" : damage ]);
        }
        else if ( random(ap+2*dp) > ap ) {
                result = "$n����һ������һ�ߣ���Ȼ���׵رܿ���$N�Ĺ�����\n" ;
                damage = 0;

                return ([ "result" : result, "damage" : damage ]);
        }
        else if ( random(ap+3*dp) > ap ) {
                result = "$n����һ������һ�ߣ�$Nֻ��������������ȫ�ޡ�\n";
                damage /= 5;
        
                return ([ "result" : result, "damage" : damage ]);
        }
        else 
                return damage;
}
